#include "button.hpp"

Button::Button (int _pin, bool _normally_high_flag) {
  pin = _pin;
  pinMode(pin, INPUT);
  timer = 0;
  debounce_ms = 5;
  debounce_flag = false;
  button_state = false;
  normally_high_flag = _normally_high_flag;
}

bool Button::read () {
  bool sample = digitalRead(pin);
  if (normally_high_flag)
    sample = !sample;

  if (sample && !button_state) {
    if (millis() - timer > debounce_ms) {
      timer = millis();
      
      if (!debounce_flag) {
	debounce_flag = true;
      }
      else {
	debounce_flag = false;
	button_state = true;
      }
    }
  }

  else if (!sample && button_state) {
    if (millis() - timer > debounce_ms) {
      timer = millis();
      
      if (!debounce_flag) {
	debounce_flag = true;
      }
      else {
	debounce_flag = false;
	button_state = false;
      }
    }
  }

  return button_state;
}

bool Button::read_raw () {
  return digitalRead(pin);
}

void Button::set_debounce (unsigned long _debounce_ms) {
  debounce_ms = _debounce_ms;
}

int Button::get_pin () {
  return pin;
}

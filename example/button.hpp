#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Arduino.h>


/**
 * NOTE: normally_high has not been tested. Notify on github if not working.
 */

class Button {
  
public:

  /**
   * This class assumes the physical wiring of the button is
   * such that a digitalRead() will return 0 when not pressed.
   * If not, see param normally_high_flag.
   *
   * @param pin Cannot and should not be changed once set.
   *
   * @param noramlly_high_flag if a digitalRead() return 1 when not pressed, set 
   * this flag to true.
   */
  Button (int pin, bool normally_high_flag = false);

  /**
   * Debounced read of button. 
   *
   * Important: Should be called at minimum every 5ms (debounce_ms) for a reliable read.
   */
  bool read ();

  /**
   * Reads the raw value from the button. I don't recommend this.
   */
  bool read_raw ();

  /**
   * returns the pin of the button. Note that pin Cannot be changed.
   */
  int get_pin ();
  
  
private:
  int pin;
  unsigned long timer;
  unsigned long debounce_ms;
  bool debounce_flag;
  bool button_state;
  bool normally_high_flag;
  
};

#endif //BUTTON_HPP

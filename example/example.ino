/**
 * Example
 *
 * This example code will show how to use the library.
 * 
 * @author Christoffer Gustafsson
 * @date 2017-09-09
 */


#include "button.hpp"


//Here we initialize our button on pin D0
Button button(D0);


void setup () {
  Serial.begin(115200);
}


void loop () {
  //static makese it set state = false once only.
  static bool state = false;
  
  if (state != button.read()) {
    state = !state;

    Serial.print("Button state changed to: ");
    Serial.println(state);
  }
}

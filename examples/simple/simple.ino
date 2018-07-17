/**
 * Simple example, will print out "button pressed"
 * when you are holding down the button.
 *
 * For a guide on how to connect the button correctly
 * check the README on github or in the library folder.
 * [github link](https://github.com/dumheter/button)
 *
 * @Author Christoffer Gustafsson
 * @Date 2017-10-06
 */

/**
 * include the button library and declare a button class.
 */
#include <button.hpp>

// If arduino board, use digial pin 2.
#if defined(ARDUINO_ARCH_AVR)
# define button_pin 2
// If esp board, use digital pin D0.
#elif defined(ARDUINO_ARCH_ESP8266)
# define button_pin D0
#endif

// create our global button
Button button(button_pin);

/**
 * Code in setup will be run once.
 */
void setup()
{
  //initiate serial communication
  Serial.begin(115200);
  Serial.println();
  Serial.println("Ready");
}

/**
 * Code in loop will run continuously.
 */
void loop()
{
  //print button pressed when pressing button
  if (button.read()) {
    static int count = 0;
    Serial.print("button pressed #");
    Serial.println(count++);
  }
}

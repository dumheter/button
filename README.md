# button
Simple software debouncing button library for Arduino.

## Usage
To use the library drop the folder inside your library folder in arduino. If you
don't know where that folder resides, google "Arduino library folder". Then add
`#include <button.hpp>` at the top of your Arduino file.

__Or__ grab the two files `button.cpp` & `button.hpp` and put with your `.ino` file.
then `#include "button.hpp"` and you are ready to go!

Read button.hpp to learn how to use this library, or see example below or
in the exmaples folder.

## Example
Read example code below, or better yet: Read the button.hpp file.
```
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
```


## Wiring
How do you wire the button? See this picture:
![Image of Wiring](https://github.com/dumheter/button/blob/master/wiring_wikimediacommons.png)

## Disclaimer
I have only tested this library with an ESP8266 and not with an Arduino device.

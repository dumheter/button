# button
Simple software debouncing button library for arduino.

## Usage
Read button.hpp to learn how to use this library, or see example below.

## Example
See folder example for a usage example, or better yet: Read the button.hpp file.
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

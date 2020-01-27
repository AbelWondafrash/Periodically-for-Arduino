# Periodically
🎈 A breezy - air light class for Arduino that eliminates fundamental issues with the in-built function delay ().


# 🐢 delay () kinda sucks!
A lot actually. Using delay() has usually has unintended sideeffect of freezing everything. Whether you come from Arduino or Processing, it is only on certain situations that delay () becomes useful. In the way it works, Arduino or your Computer does nothing for a while when delay () runs. When it is the case that you want to run multiple indpendent things with their own time, using delay () won't do.

💉 Here's a common trouble with delay (). If the input you wanted to read happens while delay () does its thing (which is nothing really), you miss the input reading. For that, you might argue saying that one can use interrupts instead to go around that. But there are so few pins on Arduino supporting that and when it comes to Processing, there isn't any better.

🖋 To appreciate the importance of this concept, get two LEDs and plug them on your Arduino. Now write a code to make them blink with differing duration. One with 400 milliseconds and the other with 900. But not one after the other; instead, in their own time.

...

Ya! Not so straight. Perhaps you've used millis in the past and you're used to doing a calculation to determine duration. But with many variables, comes messy code. And the repitition is daunting. So let Periodically do that for you.

Let's solve the above exercise:

```
#include "Periodically.h"
Periodically blink1 (400);  // 400 milliseconds
Periodically blink2 (900);

void setup() {
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
}

void loop() {
  digitalWrite (12, blink1.getState ());
  digitalWrite (13, blink2.getState ());
}
```


# Processing Version
Click [here](naive.com) to get Periodically for Processing.


🛡 So scream "behold!" and turn that delay () infested program into a snappy one. Give it a shot and breeze.

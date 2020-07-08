### Update: Please note there is now a teensy 4 branch of the Smartmatrix library that can be used instead - https://github.com/pixelmatix/SmartMatrix/tree/teensy4

This is an Arduino LED Matrix library with Teensy 4.0 support (arbitrary data pin support) for 16x32, 32x32 and 64x64 RGB LED matrix panels. It's made from the Adafruit RGB-matrix-Panel libraries (https://github.com/adafruit/RGB-matrix-Panel) and an old unmerged pull request for Teensy (https://github.com/adafruit/RGB-matrix-Panel/pull/22/commits/4ad564be6bdb6f33c4303d124bb205222baa6597)

This is purely a simple example to get a matrix panel up and running on the Teensy 4.0 (since there's currently no libraries to do this as of this commit). It provides functionality to drive all pins arbitrarily and they don't need to belong to the same port (because the Teensy 4.0 is a pin pushing beast).

There's no changes to timing in the code so you'll need the Teensy 4.0 at 150MHz to get a stable image or tweak the code further (hint, some timely placed NOPs in the update display function should do the trick for different speed requirements).

Hopefully this will spur some further development elsewhere or you have fun with it!

This comes with no warranty.

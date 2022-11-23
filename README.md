# Stepper Piano
Uses a set of 3 stepper motors to play chords on a piano interface. Piano key strikes a switch that gets feed concurrently to with a set of 11 other keys to a parallel to serial shift register. The shift register converts each signal into binary and in doing so returns which of the keys is pressed. Given the pressed keys the arduino pulls out the specific rpm required to "sing" that specific key returns it to the stepper motor. 

## Materials
Built using an Arduino Uno, jumper cables, a parallel to serial shift register,  
3 nema 17 stepper motors + a4998 drivers, and a set of switches.

## TODO
Clean up code
* Make Piano a class/object
* Figure out how to loop such that you can play rapid changes in notes
* Add a song function that implements notes

## Components
* Arduino itself
    * Reqs:
        * Initialize all pins
        * 
* Input processor
* Stepper Motor output processing

## Issues
The current implementation will likely only use one motor since the arduino can basically only run one set of commands at a time

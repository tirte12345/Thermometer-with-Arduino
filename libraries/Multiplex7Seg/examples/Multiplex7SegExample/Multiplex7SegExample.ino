#include <Multiplex7Seg.h>

byte digitPins[] = {5, 4, 3, 1}; // LSB to MSB
byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; // seg a to g
//unsigned int adc;

void setup()
{
/* set(byte enableZB, byte _noOfDigits, byte digitPins, byte segmentPins)
   enableZB activates zero leading blanking on the digits. 1 == ON, 0 == OFF
   digitPins array stores the 7 segment digits from LSB (0 digit) to MSB (4 digit max)
   segmentPins array stores the segments of the digits from a to g
*/
  Multiplex7Seg::set(0, 4, digitPins, segmentPins); // initialize 
  
}

void loop()
{
  Multiplex7Seg::loadValue(9012); // load any int value
}

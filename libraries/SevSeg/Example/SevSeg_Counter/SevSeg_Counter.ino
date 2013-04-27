//Written by Dean Reading, 2012.  deanreading@hotmail.com

/*
This example is a centi-second counter to demonstrate the
 use of my SevSeg library.
 */

#include "SevSeg.h"

//Create an instance of the object.
SevSeg sevseg;

//Create global variables
unsigned long timer;
int CentSec=0;
int val = 0;
int pause = 0;
void setup() {
//I am using a common anode display, with the digit pins connected
//from 2-5 and the segment pins connected from 6-13
  sevseg.Begin(1,1,3,4,5,6,7,8,9,10,11,12,13);
  timer=millis();
  pinMode(0, INPUT);
}

void loop() {
  //Produce an output on the display
  sevseg.PrintOutput();
  val = digitalRead(0);
  if (val == 0 && pause == 0)
    pause = 1;
  else if (val == 0 && pause == 1)
    pause = 0;
    
  //Check if 36000ms has elapsed
  unsigned long mils=millis();
  if (mils-timer>=36000) {
    timer=mils;
    if(pause == 0)
      CentSec++;
    //Update the number to be displayed, with a decimal
    //place in the correct position.
    
  }
  sevseg.NewNum(CentSec,(byte) 2);
}


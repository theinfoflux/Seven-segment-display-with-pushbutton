#include "SevSeg.h"
SevSeg sevseg;
byte CommonPins[] = {};            // common pin numbers for multi-digit display 
byte SegPins[] = {7, 6, 4, 2, 1, 9, 10, 5};  // 7-segment display pins in the order,{a,b,c,d,e,f,g,dp}
int btn=12;   //button for increment
int cnt=0;
int incPrev;

void setup()
{
  
  // begin(COMMON_CATHODE, NumberOfDigits, CommonPins[], SevenSegPins[], resistorUsed); 
  sevseg.begin(COMMON_CATHODE, 1, CommonPins, SegPins, 1);
  pinMode(btn, INPUT_PULLUP);
}

void loop()
{
    int inc = digitalRead(btn);
    //Increment
    if((inc == HIGH) && (cnt < 10) && (inc != incPrev ))
    {
      delay(100);
      cnt++;
      if(cnt==10)
      {
        cnt=0;
        }
    }

    //Logic to print digit/character on 7 segment display
   sevseg.setNumber(cnt);
   sevseg.refreshDisplay();
    delay(100);
    //storing the button states
    incPrev = inc;
 

}

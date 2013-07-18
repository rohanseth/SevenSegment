
/* SevenSegment Library
 Written by Rohan Seth, 2013
 
 Version 1.0; 
 
 Direct any questions or suggestions to rohanscar@gmail.com

I would like to thank Prof Dhananjay V. Gadre, Co-ordinator CEDT,NSIT and Rohit Dureja (Undergraduate Student, NSIT ) for their continuous guidance and support during the development of the library.
 
 Thanks to Dean Readings , Mark Chambers and Nathan Seidle for help  used from their library SevenSeg,2013 to code this segment.

Before This take a look at Readme included in the folder.

*/



#ifndef SevenSegment_h
#define SevenSegment_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class SevenSegment
{

public:
SevenSegment();                    //Constructor
 

void Display();

void Sendnumber(char number1,char number2,char number3,char number4, byte DecPlace_in);		 

 void Setup(boolean mode_in, byte D1, byte D2, byte D3, byte D4, byte S1, byte S2, byte S3, byte S4, byte S5, byte S6, byte S7, byte S8); 
    //Public Variables


private:
 

//Private Functions
  void CreateArray();


//Private Variables
  boolean mode,DigitOn,DigitOff,SegOn,SegOff;
  int numeral;  
  byte DigitPins[4];
  byte SSDPins[8];
  boolean ssd[4][8];
  byte nums[4];
  int num1;
  int num2;  
  int num3;
  int num4;
  byte DecPlace;

};

#endif


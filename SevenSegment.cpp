
/* SevenSegment Library V_1.0
 Written by Rohan Seth, 2013
 
 Version 1.0; 
 
 Direct any questions or suggestions to rohanscar@gmail.com

I would like to thank Prof Dhananjay V. Gadre, Co-ordinator CEDT,NSIT and Rohit Dureja (Undergraduate Student, NSIT ) for their continuous guidance and support during the development of the library.
 
 Thanks to Dean Readings , Mark Chambers and Nathan Seidle for help  used from their library SevenSeg,2013 to code this segment.

Before This take a look at Readme included in the folder.
*/


#include "SevenSegment.h"

SevenSegment::SevenSegment()              //constructor
{
  
  num1=0;					        //initialized to 0000
  num2=0;
  num3=0;
  num4=0;
  DecPlace=0;
}

void SevenSegment::Setup(boolean mode_in, byte D1, byte D2, byte D3, byte D4, byte S1, byte S2, byte S3, byte S4, byte S5, byte S6, byte S7, byte S8){
	
  numeral=4;      //this variable demonstrates the number of SSD
  mode=mode_in;		//Common Anode with Transistor Connected
  if (mode==1){
    DigitOn=LOW;      // pnp connection
    DigitOff=HIGH;
    SegOn=LOW;
    SegOff=HIGH;
  }
  else {			//Common Cathode With Transistor Connected
    DigitOn=HIGH;     // npn connection
    DigitOff=LOW;
    SegOn=HIGH;
    SegOff=LOW;
  }

  DigitPins[0]=D1;    //Pin Assignments of DigitPins
  DigitPins[1]=D2;    
  DigitPins[2]=D3;
  DigitPins[3]=D4;
  SSDPins[0]=S1;      //Pin Assignment of Segment Pins.
  SSDPins[1]=S2;
  SSDPins[2]=S3;
  SSDPins[3]=S4;
  SSDPins[4]=S5;
  SSDPins[5]=S6;
  SSDPins[6]=S7;
  SSDPins[7]=S8;      //Pin assignment of DP.


  for (byte digit=0;digit<4;digit++) 
  {
    pinMode(DigitPins[digit], OUTPUT);  //Assigning pin as output
  }
  for (byte seg=0;seg<8;seg++) 
  {
    pinMode(SSDPins[seg], OUTPUT);
  }

  for (byte digit=0;digit<4;digit++) 
  {
    digitalWrite(DigitPins[digit], DigitOff);
  }

  for (byte seg=0;seg<8;seg++)
  {
    digitalWrite(SSDPins[seg], SegOff);
  }
}






void SevenSegment::Display(){
  for (byte seg=0;seg<8;seg++)
  {
 
    digitalWrite(SSDPins[seg],SegOn);

    for (byte digit=0;digit<numeral;digit++){

      if (ssd[digit][seg]==1) 
      {
        digitalWrite(DigitPins[digit],DigitOn);
      }
  }

        for (byte digit=0;digit<numeral;digit++){
      digitalWrite(DigitPins[digit],DigitOff);
    }

    //Turn the relevant segment off
    digitalWrite(SSDPins[seg],SegOff);
  }
}

void SevenSegment::Sendnumber(char number1,char number2,char number3,char number4,byte DecPlace_in)
{
  //Feed the inputs into the library's variables
  nums[0]=number1;   //the parameter is so that it can recieve 				    //RAW DATA as well 
  nums[1]=number2;
  nums[2]=number3;
  nums[3]=number4;
  DecPlace=DecPlace_in;
  CreateArray();
}





void SevenSegment::CreateArray() {
  for (byte digit=0;digit<4;digit++) {
    switch (nums[digit]){
    case 0:
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=0;
      break;
    case 48:                    //ASCII equivalent of 0.
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=0;
      break;    
    case 1:
      ssd[digit][0]=0;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=0;
      ssd[digit][4]=0;
      ssd[digit][5]=0;
      ssd[digit][6]=0;
      break;
    case 49:
      ssd[digit][0]=0;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=0;
      ssd[digit][4]=0;
      ssd[digit][5]=0;
      ssd[digit][6]=0;
      break;
    case 2:
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=0;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=0;
      ssd[digit][6]=1;
      break;
   case 50:
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=0;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=0;
      ssd[digit][6]=1;
      break; 
   case 3:            //Cases so designed such that int and char 					//both can be handled.
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=0;
      ssd[digit][5]=0;
      ssd[digit][6]=1;
      break;
   case 51:
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=0;
      ssd[digit][5]=0;
      ssd[digit][6]=1;
      break;
   case 4:
      ssd[digit][0]=0;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=0;
      ssd[digit][4]=0;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break; 
   case 52:
      ssd[digit][0]=0;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=0;
      ssd[digit][4]=0;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;
   case 5:
      ssd[digit][0]=1;
      ssd[digit][1]=0;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=0;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;
   case 53:
      ssd[digit][0]=1;
      ssd[digit][1]=0;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=0;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break; 
   case 6:
      ssd[digit][0]=1;
      ssd[digit][1]=0;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;
   case 54:
      ssd[digit][0]=1;
      ssd[digit][1]=0;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;
   case 7:
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=0;
      ssd[digit][4]=0;
      ssd[digit][5]=0;
      ssd[digit][6]=0;
      break;
   case 55:
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=0;
      ssd[digit][4]=0;
      ssd[digit][5]=0;
      ssd[digit][6]=0;
      break; 
   case 8:
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;
   case 56:
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break; 
   case 9:
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=0;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break; 
   case 57:
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=0;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break; 
   case 97:                    //To check lowercase letters.
      ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=0;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;
   case 65:                    //To check uppercase letters.
       ssd[digit][0]=1;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=0;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;
   case 66:
      ssd[digit][0]=0;
      ssd[digit][1]=0;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;

    case 98:
      ssd[digit][0]=0;
      ssd[digit][1]=0;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;

 case 67:
      ssd[digit][0]=1;
      ssd[digit][1]=0;
      ssd[digit][2]=0;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=0;
      break;

 case 99:
      ssd[digit][0]=1;
      ssd[digit][1]=0;
      ssd[digit][2]=0;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=0;
      break;


 	case 68:
      ssd[digit][0]=0;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=0;
      ssd[digit][6]=1;
      break;

 	case 100:
      ssd[digit][0]=0;
      ssd[digit][1]=1;
      ssd[digit][2]=1;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=0;
      ssd[digit][6]=1;
      break;

    	case 69:
      ssd[digit][0]=1;
      ssd[digit][1]=0;
      ssd[digit][2]=0;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;

    	case 101:
      ssd[digit][0]=1;
      ssd[digit][1]=0;
      ssd[digit][2]=0;
      ssd[digit][3]=1;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;

 	case 70:
      ssd[digit][0]=1;
      ssd[digit][1]=0;
      ssd[digit][2]=0;
      ssd[digit][3]=0;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;


 	case 102:
      ssd[digit][0]=1;
      ssd[digit][1]=0;
      ssd[digit][2]=0;
      ssd[digit][3]=0;
      ssd[digit][4]=1;
      ssd[digit][5]=1;
      ssd[digit][6]=1;
      break;

 default:                       // any other parameter beyond                         						   //this leaves SSD Blank.
      ssd[digit][0]=0;
      ssd[digit][1]=0;
      ssd[digit][2]=0;
      ssd[digit][3]=0;
      ssd[digit][4]=0;
      ssd[digit][5]=0;
      ssd[digit][6]=0;
      break;
    }

    //Set the decimal place ssd
    if (-1-digit+numeral==DecPlace)     //To adjust decimal point
    {                                  //To remove Decimal point  						//give number greater than 4.
      ssd[digit][7]=1;
    }
    else 
    {
      ssd[digit][7]=0;
    }
  }
}





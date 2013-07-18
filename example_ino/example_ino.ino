
#include "QuadSevenSeg.h"                        //Inclusion of our library.

QuadSevenSeg Test;                              //Create an instance of the object


void setup() {
  Test.Setup(0,10,11,12,13,8,7,6,5,4,3,2,9);     //The parameters here are for two SSD's , though it allows upto seven SSD's. 
                                                /*Parameter Sequence : 1)First : 0/1 for cathode , anode respectively
                                                                       2)Second-Fifth:The Arduino Digital Pins of common connection.
                                                                       4)Sixth-thirteenth:The Segment Pins in Higher to Lower order and DP being Last.*/
    
}

void loop() 
{

  Test.Sendnumber('A',' ','3','d',(byte) 0);                 //To update the number send in the parameters .. IT can receive char as well as int arguments .. TO leave any ssd blank supply any argument beyong 0-9 or a-f.
  
  Test.Display();                                          //Call this to Produce an output on the display. REMEMBER : Default value is 0000 so if you use this without updating the number then you would get 0000 as display.
 
}


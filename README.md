SevenSegment
============

Arduino Library to handle upto four Seven Segment Displays in any plausible configuration with Hexadecimal display.

********************Seven Segment Library V_1.0*******************

This library has been developed at CEDT,NSIT for the easy handling of Seven Segment displays connected with Arduino in any plausible fashion which can be either common anode or common cathode later of which is demonstrated  in the undermentioned figure(Fig 1).
Hardware Requirements: 
1)13 Digital Pins distributed in the fashion (4 Common Pins (either cathode or anode) and 9 segment Pins (0-8 – a-g and last one for DP).
2)Common pins are connected via NPN/PNP transistors to increase the current carrying capacity.
3)The segment pins are connected to the Digital pins vide the current limiting resistors.

 
 
For figure refer to the instructions in the repository
Fig 1 .Four Seven Segments connected in common cathode fashion.



Software : 

INSTRUCTIONS TO SET UP THE LIBRARY : 
1) Download the folder from the Git Repository and then copy the same in the libraries section of your Arduino folder to get the library working.
2) The folder also comes with an example folder containing a sample sketch demonstrating the syntactical use of the library.


What All Can This Library Do: 

1) This Library supports upto four seven segment displays connected in the multiplexed fashion as demonstrated earlier in the figure included.
2) Each of the Seven Segment Display can display any of the hexadecimal character including an option to leave any of the Seven Segment Displayed (Referred to as the SSD hereafter) , as blank.
3) The library call can handle ” Raw Data “ as well for example if you want to send a as a parameter then you just need to send ‘a’ and the library at the backend can handle it by itself.
4) Besides handling characters, library can also handle integer variables.
5) To leave any of the SSD blank you just need to pass ‘g’ as a parameter and that SSD Would be shut off to display.


 SOFTWARE EXPLANATION  :

Although example code included in the repository is self explanatory , yet we describe the functions with there parameters and there role. 

1)  void Setup(boolean mode_in, byte D1, byte D2, byte D3, byte D4, byte S1, byte S2, byte S3, byte S4, byte S5, byte S6, byte S7, byte S8) : 

This function is always called in the beginning preferably in the setup() of the sketch to let library know the pin mapping of your hardware created . 

a)The first parameter is used to change the mode : 0 for Common Cathode and 1 for Common Anode.
b)The Second – fifth parameter is to handle the common pins of the setup in lower to higher order.
c)The next eight parameters receive the segment pins in the order a-g and then DP further on.

2)	void Sendnumber(char number1,char number2,char number3,char number4, byte DecPlace_in) :

This function is used to update the number to be displayed by sending five parameters as explained underneath

a)Parameter one – four are to update with each of the number in the Quad Seven Segment Display.
b)Parameter five is to tell the location of the decimal point.
To hide the decimal point we send in a parameter greater than four .

3)	void Display();

This functions makes the final formality of displaying the number with whatever has been updated in the Sendnumber parameter. TO REM : By default the number is initialized to 0000 so when no number is updated and display() is called that makes it to display 0000 on the Four SSD’s.
 

Acknowledgments : 

 SevenSegment Library
 Written by Rohan Seth, 2013
 
 Version 1.0; 
 
 Direct any questions or suggestions to rohanscar@gmail.com

I would like to thank Prof Dhananjay V. Gadre, Co-ordinator CEDT,NSIT and Rohit Dureja (Undergraduate Student, NSIT ) for their continuous guidance and support during the development of the library.
 
 Thanks to Dean Readings , Mark Chambers and Nathan Seidle for help  used from their library SevenSeg,2013 to code this segment.
 




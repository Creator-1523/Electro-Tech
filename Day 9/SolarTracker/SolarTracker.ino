#include <Servo.h> //includes the servo library

Servo myservo;

#define ldr1 A0 // set ldr 1 Analog input pin of East ldr as an integer
#define ldr2 A1 // set ldr 2 Analog input pin of West ldr as an integer

int pos = 90; // initial position of the Horizontal movement controlling servo motor

void setup(){
myservo.attach(11); // attaches the servo on digital pin 2 to the horizontal movement servo motor 
pinMode(ldr1, INPUT); //set East ldr pin as an input
pinMode(ldr2, INPUT); //set West ldr pin as an input
myservo.write(pos); // write the starting position of the horizontal movement servo motor 

delay(300); // 1 second delay to allow the solar panel to move to its staring position before comencing solar tracking
}

void loop(){  
 
int a = analogRead(ldr1); // read the value of ldr 1
int b = analogRead(ldr2); // read the value of ldr 2
 
if(a > b) // if ldr1 senses more light than ldr2 
{
pos = pos+1; // decrement the 90 degree poistion of the horizontal servo motor - this will move the panel position Eastward
}
if(a < b) // if ldr2 senses more light than ldr1
{
pos = pos-1; // increment the 90 degree position of the horizontal motor - this will move the panel position Westward
}

if(pos > 180) 
{
 pos = 180;
} // reset the horizontal postion of the motor to 180 if it tries to move past this point
if(pos < 0) {
 pos = 0;
} // reset the horizontal position of the motor to 0 if it tries to move past this point
myservo.write(pos); // write the starting position to the horizontal motor
delay(100);

}

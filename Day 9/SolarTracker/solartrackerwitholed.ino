#include <Servo.h> //includes the servo library
//OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Servo myservo;
//OLED define
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define ldr1 A4 // set ldr 1 Analog input pin of East ldr as an integer
#define ldr2 A5 // set ldr 2 Analog input pin of West ldr as an integer

int pos = 90; // initial position of the Horizontal movement controlling servo motor

void setup(){
myservo.attach(9); // attaches the servo on digital pin 2 to the horizontal movement servo motor 
pinMode(ldr1, INPUT); //set East ldr pin as an input
pinMode(ldr2, INPUT); //set West ldr pin as an input
myservo.write(pos); // write the starting position of the horizontal movement servo motor 

delay(300); // 1 second delay to allow the solar panel to move to its staring position before comencing solar tracking

 //For OLED I2C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display(); //Display logo
  delay(1000); 
  display.clearDisplay();
}

void loop(){      
int val1 = analogRead(ldr1); // read the value of ldr 1
int val2 = analogRead(ldr2); // read the value of ldr 2


if(val1 > val2) // if ldr1 senses more light than ldr2 
{
pos = pos+1; // decrement the 90 degree poistion of the horizontal servo motor - this will move the panel position Eastward
Serial.print("Move towards East");
display.clearDisplay();
 oledDisplayHeader1();

}
if(val1 < val2) // if ldr2 senses more light than ldr1
{
pos = pos-1; // increment the 90 degree position of the horizontal motor - this will move the panel position Westward
 
 Serial.print("Move towards West");
 display.clearDisplay();
 oledDisplayHeader2();
 }
if(pos > 180) {
  pos = 180;
  } // reset the horizontal postion of the motor to 180 if it tries to move past this point
if(pos < 0) {
  pos = 0;
  } // reset the horizontal position of the motor to 0 if it tries to move past this point
myservo.write(pos); // write the starting position to the horizontal motor
delay(100);

}
void oledDisplayHeader1(){
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(0, 0);
 display.print("Move towards East");

}
void oledDisplayHeader2(){
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(0, 0);
 display.print("Move towards West");

}

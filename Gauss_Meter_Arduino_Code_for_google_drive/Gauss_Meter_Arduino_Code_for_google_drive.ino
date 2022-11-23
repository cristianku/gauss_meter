/*
 * This is the Arduino code for  Voltage Sensor
 * you will measure voltage using this module which eliminate use extra resistors
 in the video also you will learn how to measure any voltages.

 * Watch the video instruction for Arduino Voltage sensor https://youtu.be/FaoKzi7tgME
 *  * 

 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 */
/*
 * Written by Ahmad Shamshiri for Robojax
 * on Feb 07, 2018 at 20:05, Ajax, Ontario, Canada
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //need this text to work

//int Gauss;
int Gauss;
double Gauss_tmp;

int offset =06 ;// set the correction offset value
void setup() {
  // Robojax.com voltage sensor
  Serial.begin(9600);
{
  // initialize the LCD
   lcd.begin(16,2);

  // Turn on the blacklight and print a message.
   lcd.backlight();
 
}
}

void loop() {
  // Robojax.com voltage sensor
  int volt = analogRead(A0);// read the input
  double voltage = map(volt,0,1023, 0, 2500) + offset;// map 0-1023 to 0-2500 and add correction offset
  
  voltage /=100;// divide by 100 to get the decimal values
  Serial.print("Voltage: ");
  Serial.print(voltage);//print the voltge
  Serial.print("V  -  ");

//Gauss = (voltage - 2.5) * 1300;
Gauss_tmp = (voltage - 2.52) * 666.666667 ;
Gauss = abs(int(Gauss_tmp));

   lcd.setCursor(0,0);
   lcd.print("GAUSS");
   lcd.setCursor(11,0);
   lcd.print(Gauss);
   Serial.print("GAUSS:");
   Serial.print(Gauss);
   
   lcd.setCursor(0,1) ;

   lcd.print(voltage);
   lcd.print("V");

   lcd.setCursor(11,1) ;
  if ( Gauss > 1 ) { 
    if (voltage < 2.52)Serial.println(" - NORTH");
      else Serial.println(" - SOUTH");
   }
   else {
    Serial.println("");
   }
   ;  
   

  if ( Gauss > 1 )
  {
    if (voltage < 2.52)lcd.print("NORTH");
      else lcd.print("SOUTH");
  };
  
  Gauss_tmp = 0;
  Gauss = 0;

  
delay(1000);
  
 lcd.clear();
}

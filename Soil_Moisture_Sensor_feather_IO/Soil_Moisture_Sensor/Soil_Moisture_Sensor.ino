#include "config.h"
AdafruitIO_Feed *moister = io.feed("moister");
int msensor = A0; // moisture sensor is connected with the analog pin A1 of the Arduino
int msvalue = 0; // moisture sensor value on board LED 
int led = 13; 
boolean flag = false; 
void setup() {
  Serial.begin(115200);
  pinMode(msensor, INPUT);
  pinMode(led, OUTPUT);  
}
// code sourced from https://www.electroniclinic.com/arduino-soil-moisture-sensor-getting-started-tutorial/
void loop() {
  io.run();
  msvalue = analogRead(msensor);
msvalue = map(msvalue, 0, 900, 0, 200);
Serial.println(msvalue);
analogWrite(2, msvalue);

  if ( (msvalue >= 500  ) && ( flag == false ) )
{
  digitalWrite(led, HIGH); 
  flag = true; 
  delay(1000); 
}
 
  if ( (msvalue <= 300  ) && ( flag == true ) )
{
  digitalWrite(led, LOW); 
  flag = false; 
  delay(60000); 
}
 
  delay(3000);      
  moister->save(msvalue);
}

/* 
 
 MODIFIED BY Aaron Yeoh.
 
 For use with the Adafruit Motor Shield v2 
 ---->	http://www.adafruit.com/products/1438
 */
#ifndef STUFF
#define STUFF

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

#endif

#include "ClassBot.h"

int led = 13;
Bot bot;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");
  pinMode(led, OUTPUT);  
  bot.Init();
}
int i;
void loop() {
  digitalWrite(led, HIGH);
  Serial.println("Stepper test222222!");
  bot.Forward(500);
  delay(1000);
  bot.Backward();
  bot.Left(425);
  bot.Backward(125);
  bot.Right();
  bot.RotCW();
  bot.RotCCW();
  digitalWrite(led, LOW);
  delay(5000);
  while(1) {} //Stops everything.


}

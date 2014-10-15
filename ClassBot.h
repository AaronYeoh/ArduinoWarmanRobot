//Author: Aaron YH Yeoh

#ifndef STUFF
#define STUFF

#include <Wire.h>
#include <Adafruit_MotorShield.h> 
#include "utility/Adafruit_PWMServoDriver.h"


#endif
using namespace std;
//class Bot ()  Now controls all steppers with methods for movement in 3 axes 
//- Forward, Backward, L, R, Rotate Left & RIght.  //Attach ArmMotor to pin #10 and
//PayloadMotor to pin #11
class Bot 
{
  
  public:
    Bot();  
    void Forward(int, int);
    void Backward(int, int);
    void Left(int);
    void Right(int);
    void RotCCW(int);
    void RotCW(int); 
	void Init(void);	
	
	void RaiseArms(int);
	void TransferPayload(int);
  private:
    Adafruit_MotorShield AFMStop;
    Adafruit_MotorShield AFMSbot;
    int ArmMotor;
	int PayloadMotor;
    Adafruit_StepperMotor *myMotor1;
	Adafruit_StepperMotor *myMotor2;
	Adafruit_StepperMotor *myMotor3;
	Adafruit_StepperMotor *myMotor4;
};

Bot::Bot(){
}

void Bot::Init(){
     Serial.println("Initialise start!!!!");
	ArmMotor = 10; PayloadMotor = 11;
	pinMode(ArmMotor, OUTPUT); 
	pinMode(PayloadMotor, OUTPUT); 
	AFMStop = Adafruit_MotorShield(0x61); 
    AFMSbot = Adafruit_MotorShield(0x60); 
	
	//Attach the front left steppr to motor port 1 (M1 M2) of bottom shield
	myMotor1 = AFMSbot.getStepper(200, 1);

	//Connect the front right stepper with 200 steps per revolution (1.8 degree)
	// to motor port #2 (M3 and M4)
	myMotor2 = AFMSbot.getStepper(200, 2);

	//TOP shield:
	//Attach the back right steppr to motor port 1 (M1 M2) 
	myMotor3 = AFMStop.getStepper(200, 1);

	//Attach the back left steppr to motor port 2 (M3 M4) 
	myMotor4 = AFMStop.getStepper(200, 2);
	
  AFMSbot.begin();
  AFMStop.begin();

  
  myMotor1->setSpeed(60);
  myMotor2->setSpeed(60);
  myMotor3->setSpeed(60);
  myMotor4->setSpeed(60);

  Serial.println("Initialise end!!!!");

}
void Bot::RaiseArms (int del= 10000){
	Serial.println("It's time to party!!");
	digitalWrite(ArmMotor, HIGH);
	delay(del);
	digitalWrite(ArmMotor, LOW);
}

void Bot::TransferPayload (int del = 10000){
	Serial.println("Up and over...");
	digitalWrite(PayloadMotor, HIGH);
	delay(del);
	digitalWrite(PayloadMotor, LOW);
}
void Bot::Forward(int steps = 100, int skip =0){
char str[15];
 for (int i =0; i<steps; i++){
   myMotor1->onestep(BACKWARD, DOUBLE);
   myMotor2->onestep(FORWARD, DOUBLE);
   myMotor3->onestep(BACKWARD, DOUBLE);
   myMotor4->onestep(FORWARD, DOUBLE);
   //delay(1); // uncomment if not printing
   sprintf(str, "Forward!! %d\0", i);
   Serial.println(str);
 }
} 

void Bot::Backward(int steps = 100, int skip =0){
char str[15];
 for (int i =0; i<steps; i++){
   myMotor1->onestep(FORWARD, DOUBLE);
   myMotor2->onestep(BACKWARD, DOUBLE);
   myMotor3->onestep(FORWARD, DOUBLE);
   myMotor4->onestep(BACKWARD, DOUBLE);
   //delay(1); // uncomment if not printing
   sprintf(str, "Backwards! %d\0", i);
   Serial.println(str);
 }
} 

void Bot::Left(int steps = 100){
char str[15];
 for (int i =0; i<steps; i++){
   myMotor1->onestep(FORWARD, DOUBLE);
   myMotor2->onestep(FORWARD, DOUBLE);
   myMotor3->onestep(BACKWARD, DOUBLE);
   myMotor4->onestep(BACKWARD, DOUBLE);
   //delay(1); // uncomment if not printing
   sprintf(str, "2daLeft! %d\0", i);
   Serial.println(str);
 }
} 

void Bot::Right(int steps = 100){
char str[15];
 for (int i =0; i<steps; i++){
   myMotor1->onestep(BACKWARD, DOUBLE);
   myMotor2->onestep(BACKWARD, DOUBLE);
   myMotor3->onestep(FORWARD, DOUBLE);
   myMotor4->onestep(FORWARD, DOUBLE);
   //delay(1); // uncomment if not printing
   sprintf(str, "2daRite! %d\0", i);
   Serial.println(str);
 }
} 

void Bot::RotCCW(int steps = 100){
char str[15];
 for (int i =0; i<steps; i++){
   myMotor1->onestep(FORWARD, DOUBLE);
   myMotor2->onestep(FORWARD, DOUBLE);
   myMotor3->onestep(FORWARD, DOUBLE);
   myMotor4->onestep(FORWARD, DOUBLE);
   //delay(1); // uncomment if not printing
   sprintf(str, "SpinCCW! %d\0", i);
   Serial.println(str);
 }
} 

void Bot::RotCW(int steps = 100){
char str[15];
 for (int i =0; i<steps; i++){
   myMotor1->onestep(BACKWARD, DOUBLE);
   myMotor2->onestep(BACKWARD, DOUBLE);
   myMotor3->onestep(BACKWARD, DOUBLE);
   myMotor4->onestep(BACKWARD, DOUBLE);
   //delay(1); // uncomment if not printing
   sprintf(str, "SpinCW! %d\0", i);
   Serial.println(str);
 }
} 

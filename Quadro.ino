/* 
aih yah so many edits that i had to make but didnt have time
-kalie 4.18

This is code for the TC team:
Quadro

What it does:
- sets up IR remote to control two different motors
- motors raise and lower bridge

-kalie 2.24.17
Questions: contact kaliefaith@gmail.com
*/

// Calling the libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
// #include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Motor on port M1: right
Adafruit_DCMotor *driveMotor1 = AFMS.getMotor(1);
// Motor on port M2: left
Adafruit_DCMotor *driveMotor2 = AFMS.getMotor(2);
// Motor on port M1: right
Adafruit_DCMotor *reelMotor1 = AFMS.getMotor(3);
// Motor on port M2: left
Adafruit_DCMotor *reelMotor2 = AFMS.getMotor(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("DC Motor test");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  driveMotor1->setSpeed(180);
  driveMotor1->run(FORWARD);
  // turn on motor
  driveMotor1->run(RELEASE);

  // Set the speed to start, from 0 (off) to 255 (max speed)
  driveMotor2->setSpeed(180);
  driveMotor2->run(FORWARD);
  // turn on motor
  driveMotor2->run(RELEASE);

  // Set the speed to start, from 0 (off) to 255 (max speed)
  reelMotor1->setSpeed(180);
  reelMotor1->run(FORWARD);
  // turn on motor
  reelMotor1->run(RELEASE);

  // Set the speed to start, from 0 (off) to 255 (max speed)
  reelMotor2->setSpeed(180);
  reelMotor2->run(FORWARD);
  // turn on motor
  reelMotor2->run(RELEASE);
}

void loop() {

  //
  
  Serial.println("Go forward: meet edge of first table");
  driveMotor1->run(FORWARD);
  driveMotor2->run(FORWARD);
  delay(2250);
  
  //
  
  Serial.println("Lower bridge: first chasm");
  reelMotor1->run(FORWARD);
  reelMotor2->run(FORWARD);
  delay(10000);

  //

  Serial.println("Go forward: cross bridge");
  driveMotor1->run(FORWARD);
  driveMotor2->run(FORWARD);
  delay(5500);
  //

  Serial.println("Drive motors in rest (just in case)");
  driveMotor1->run(RELEASE);
  driveMotor2->run(RELEASE);
  delay(1000);

  //

  Serial.println("Raise bridge");
  reelMotor1->run(BACKWARD);
  reelMotor2->run(BACKWARD);
  delay(10000);
  
  //

  // There may be distance that will need to be travelled between these two steps.

  Serial.println("180");
  driveMotor1->run(FORWARD);
  driveMotor2->run(BACKWARD);
  delay(10000);

  //

  Serial.println("Drive motors in rest (just in case)");
  driveMotor1->run(RELEASE);
  driveMotor2->run(RELEASE);
  delay(1000);

  //

  /* From this point on, the drive motors must be reversed because the robot has turned around. */

  Serial.println("Go forward: meet the edge of second table");
  driveMotor1->run(BACKWARD);
  driveMotor2->run(BACKWARD);
  delay(5500);

  //

  // This is a guess, must be tested
  Serial.println("Lower bridge: second chasm");
  reelMotor1->run(FORWARD);
  reelMotor2->run(FORWARD);
  delay(10000);

  //

  Serial.println("Go forward: cross bridge");
  driveMotor1->run(BACKWARD);
  driveMotor2->run(BACKWARD);
  delay(5500);

  //

  Serial.println("Drive motors in rest (just in case)");
  driveMotor1->run(RELEASE);
  driveMotor2->run(RELEASE);
  delay(1000);

  //

  // This is a guess, must be tested
  Serial.println("Raise bridge");
  reelMotor1->run(BACKWARD);
  reelMotor2->run(BACKWARD);
  delay(10000);

  //

  Serial.println("Go forward: to end of last table");
  driveMotor1->run(BACKWARD);
  driveMotor2->run(BACKWARD);
  delay(5500);
}



#include <Servo.h>

//Identifies servos

Servo s1;
Servo s2;
Servo s3;
Servo s4;

//Defines pins in which servos are located

int S1_pin = 6;
int S2_pin = 9;
int S3_pin = 10;
int S4_pin = 11;

//Defines pins in which the axes of both joysticks are located

int Left_Y_pin = 0;
int Left_X_pin = 1;

int Right_Y_pin = 2;
int Right_X_pin = 3;

//Defines initial position values of the servos (halfway)

int S1_pos = 90;
int S2_pos = 70;
int S3_pos = 105;
int S4_pos = 35;

//Defines position variables of joystick axes

int Left_Y_pos;
int Left_X_pos;
int Right_Y_pos;
int Right_X_pos;

//Defines velocity variables of joystick axes

int Left_Y_vel;
int Left_X_vel;
int Right_Y_vel;
int Right_X_vel;

void setup() {

  //Starts serial monitor (to display values in case of testing)

  Serial.begin(9600);

  //Relates each servo with its pin
  
  s1.attach(S1_pin);
  s2.attach(S2_pin);
  s3.attach(S3_pin);
  s4.attach(S4_pin);
}

void loop() {

  //Reads axes values from joystick pins into axes position values
  
  Left_Y_pos = analogRead(Left_Y_pin);
  Left_X_pos = analogRead(Left_X_pin);
  Right_Y_pos = analogRead(Right_Y_pin);
  Right_X_pos = analogRead(Right_X_pin);

  //Converts Axes position values to velocity values

  Left_Y_vel = map(Left_Y_pos,1023,0,-4,5);
  Left_X_vel = map(Left_X_pos,0,1023,-4,5);
  Right_Y_vel = map(Right_Y_pos,1023,0,-4,5);
  Right_X_vel = map(Right_X_pos,0,1023,-5,5);

  //Adds velocity values to servo position values
  
  S1_pos += Right_X_vel;
  S2_pos += Right_Y_vel;
  S3_pos += Left_Y_vel;
  S4_pos += Left_X_vel;

  //Constrains position values of servos to specific maximum and minimum positions

  if (S1_pos < 0) S1_pos = 0;
  if (S1_pos > 180) S1_pos = 180;
  
  if (S2_pos < 0) S2_pos = 0;
  if (S2_pos > 140) S2_pos = 140;

  if (S3_pos < 30) S3_pos = 30;
  if (S3_pos > 180) S3_pos = 180;

  if (S4_pos < 0) S4_pos = 0;
  if (S4_pos > 70) S4_pos = 70;
  
  //Transmits position values to servos
  
  s1.write(S1_pos);
  s2.write(S2_pos);
  s3.write(S3_pos);
  s4.write(S4_pos);
  delay(15);
}

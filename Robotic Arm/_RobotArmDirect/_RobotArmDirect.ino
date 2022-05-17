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

  //Converts axes position values to servo position values
   //for reference on the values, check the servotest files

  S1_pos = map(Right_X_pos,0,1023,0,180);
  S2_pos = map(Right_Y_pos,1023,0,0,140);
  S3_pos = map(Left_Y_pos,1023,0,30,180);
  S4_pos = map(Left_X_pos,0,1023,0,70);

  //Transmits position values to servos
  
  s1.write(S1_pos);
  s2.write(S2_pos);
  s3.write(S3_pos);
  s4.write(S4_pos);
}

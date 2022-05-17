#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;

int pos = 0;

void setup() {

  Serial.begin(9600);
  
  s1.attach(6);
  s2.attach(9);
  s3.attach(10);
  s4.attach(11);
}

void loop() {

  //Test for S3(Vertical Movement)

  //from 30 to 180
  
  for (pos = 30; pos <= 180; pos += 1) {
    // in steps of 1 degree
    s3.write(pos);
    Serial.println(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 30; pos -= 1) {
    s3.write(pos);
    Serial.println(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

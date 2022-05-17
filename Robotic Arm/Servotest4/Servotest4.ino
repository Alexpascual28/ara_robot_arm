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

  //Test for S4(Claws)

  //from 0 to 70
  
  for (pos = 0; pos <= 70; pos += 1) {
    // in steps of 1 degree
    s4.write(pos);
    Serial.println(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 70; pos >= 0; pos -= 1) {
    s4.write(pos);
    Serial.println(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

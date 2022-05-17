int Left_Y_pin = 0;
int Left_X_pin = 1;

int Right_Y_pin = 2;
int Right_X_pin = 3;

void setup() {
  Serial.begin(9600);
}

void loop() {

  //Test for joysticks
  //Prints values in serial monitor
  
  Serial.print("Left X-axis: ");
  Serial.print(analogRead(Left_X_pin));
  Serial.print("\n");
  Serial.print("Left Y-axis: ");
  Serial.println(analogRead(Left_Y_pin));
  Serial.print("\n");
  
  Serial.print("Right X-axis: ");
  Serial.print(analogRead(Right_X_pin));
  Serial.print("\n");
  Serial.print("Right Y-axis: ");
  Serial.println(analogRead(Right_Y_pin));
  Serial.print("\n\n\n");
  
  delay(500);
}

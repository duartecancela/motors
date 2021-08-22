/*
  motors.ino
  Duarte Cancela
  15/08/2021
  ----
  DFC-77 robot motors control code
*/

// initialize pins for the L298N motors driver
// Right motor
int rightMotorsEn = 9;
int rightMotorsIn1 = 4;
int rightMotorsIn2 = 5;
// left motor
int leftMotorsEn = 10;
int leftMotorsIn3 = 6;
int leftMotorsIn4 = 7;

int motorsSpeedLeft = 0;
int motorsSpeedRight = 0;

void setup()
{
  Serial.begin(9600);
  // Define output pins
  pinMode(rightMotorsIn1, OUTPUT);
  pinMode(rightMotorsIn2, OUTPUT);
  pinMode(leftMotorsIn3, OUTPUT);
  pinMode(leftMotorsIn4, OUTPUT);
}

// Rotate right motor forward
void rotateRightMotorsFWD(){
  Serial.println("Rotate right motors forward");
  analogWrite(rightMotorsEn, 50); // speed
  digitalWrite(rightMotorsIn1, HIGH);
  digitalWrite(rightMotorsIn2, LOW);
  delay(4000);
}

// Rotate  left motor forward
void rotateLeftMotorsFWD(){
  Serial.println("Rotate  left motors forward");
  analogWrite(leftMotorsEn, 50); // speed
  digitalWrite(leftMotorsIn3, HIGH);
  digitalWrite(leftMotorsIn4, LOW);
  delay(4000);
}

// Rotate right motors backward
void rotateRightMotorsBWD(){
  Serial.println("Rotate right motors backward");
  digitalWrite(rightMotorsIn1, LOW);
  digitalWrite(rightMotorsIn2, HIGH);
  delay(4000);
}

//Rotate left motor backward
void rotateLeftMotorsBWD(){
  Serial.println("Rotate left motors backward");
  digitalWrite(leftMotorsIn3, LOW);
  digitalWrite(leftMotorsIn4, HIGH);
  delay(4000);
}

// Stop right motors
void stopRightMotors(){
  Serial.println("Stop right motors");
  digitalWrite(rightMotorsIn1, HIGH);
  digitalWrite(rightMotorsIn2, HIGH);
  delay(500);
}

// Stop left motors
void stopLeftMotors(){
  Serial.println("Stop left motors");
  digitalWrite(leftMotorsIn3, HIGH);
  digitalWrite(leftMotorsIn4, HIGH);
  delay(500);
}

void loop()
{
  int xAxis = analogRead(A0); // Read Joysticks X-axis
  int yAxis = analogRead(A1); // Read Joysticks Y-axis

  Serial.print("xAxis = ");
  Serial.print(xAxis);
  Serial.print(" | yAxis = ");
  Serial.print(yAxis);
  Serial.println();

//  rotateRightMotorsFWD();
//  stopRightMotors();
//  rotateLeftMotorsFWD();
//  stopLeftMotors();
//  rotateRightMotorsBWD();
//  stopRightMotors();
//  rotateLeftMotorsBWD();
//  stopLeftMotors();
}

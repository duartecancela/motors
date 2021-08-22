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

int motorsSpeedRight = 0;
int motorsSpeedLeft= 0;

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
  analogWrite(rightMotorsEn, motorsSpeedRight); // speed
  digitalWrite(rightMotorsIn1, HIGH);
  digitalWrite(rightMotorsIn2, LOW);
}

// Rotate  left motor forward
void rotateLeftMotorsFWD(){
  Serial.println("Rotate  left motors forward");
  analogWrite(leftMotorsEn, motorsSpeedLeft); // speed
  digitalWrite(leftMotorsIn3, HIGH);
  digitalWrite(leftMotorsIn4, LOW);
}

// Rotate right motors backward
void rotateRightMotorsBWD(){
  Serial.println("Rotate right motors backward");
  analogWrite(rightMotorsEn, motorsSpeedRight); // speed
  digitalWrite(rightMotorsIn1, LOW);
  digitalWrite(rightMotorsIn2, HIGH);
}

//Rotate left motor backward
void rotateLeftMotorsBWD(){
  Serial.println("Rotate left motors backward");
  analogWrite(leftMotorsEn, motorsSpeedLeft); // speed
  digitalWrite(leftMotorsIn3, LOW);
  digitalWrite(leftMotorsIn4, HIGH);
}

// Stop right motors
void stopRightMotors(){
  Serial.println("Stop right motors");
  digitalWrite(rightMotorsIn1, LOW);
  digitalWrite(rightMotorsIn2, LOW);
}

// Stop left motors
void stopLeftMotors(){
  Serial.println("Stop left motors");
  digitalWrite(leftMotorsIn3, LOW);
  digitalWrite(leftMotorsIn4, LOW);
}

void loop()
{
  int xAxis = analogRead(A0); // Read Joysticks X-axis
  int yAxis = analogRead(A1); // Read Joysticks Y-axis

  // debug joystik output
  Serial.print("xAxis = ");
  Serial.print(xAxis);
  Serial.print(" | yAxis = ");
  Serial.print(yAxis);
  Serial.print(" | Right Speed = ");
  Serial.print(motorsSpeedRight);
  Serial.print(" | Left Speed = ");
  Serial.print(motorsSpeedLeft);
  Serial.println();

  // Y-axis used for forward and backward control
  if (yAxis < 470) {
    // Set right motors backward
    rotateRightMotorsBWD();
    // Set left Motors backward
    rotateLeftMotorsBWD();
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorsSpeedRight = map(yAxis, 470, 0, 0, 255);
    motorsSpeedLeft = map(yAxis, 470, 0, 0, 255);
  }
  else if (yAxis > 550) {
    // Set Motor A forward
    rotateRightMotorsFWD();
    // Set Motor B forward
    rotateLeftMotorsFWD();
    // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorsSpeedRight = map(yAxis, 550, 1023, 0, 255);
    motorsSpeedLeft = map(yAxis, 550, 1023, 0, 255);
  }
  // If joystick stays in middle the motors are not moving
  else {
    stopRightMotors();
    stopLeftMotors();
    motorsSpeedRight= 0;
    motorsSpeedLeft = 0;
  }

//  rotateRightMotorsFWD();
//  stopRightMotors();
//  rotateLeftMotorsFWD();
//  stopLeftMotors();
//  rotateRightMotorsBWD();
//  stopRightMotors();
//  rotateLeftMotorsBWD();
//  stopLeftMotors();
}

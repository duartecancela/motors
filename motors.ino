/* 
motors.ino
Duarte Cancela
15/08/2021 
----
DFC-77 robot motors control code
*/
 
// initialize pins
// Right motor
int rightMotorEn = 9;
int rightMotorIn1 = 4;
int rightMotorIn2 = 5;
// left motor
int leftMotorEn = 10;
int leftMotorIn3 = 6;
int leftMotorIn4 = 7;
  
void setup()
{
 // Define output pins
 pinMode(rightMotorIn1, OUTPUT);
 pinMode(rightMotorIn2, OUTPUT);
 pinMode(leftMotorIn3, OUTPUT);
 pinMode(leftMotorIn4, OUTPUT);
}
  
void loop()
{
 // Rotate right motor clockwise
 analogWrite(rightMotorEn, 125);
 digitalWrite(rightMotorIn1, HIGH);
 digitalWrite(rightMotorIn2, LOW);
 delay(4000);
 // Stop right motor
 digitalWrite(rightMotorIn1, HIGH);
 digitalWrite(rightMotorIn2, HIGH);
 delay(500);
 // Rotate  left motor clockwise
 digitalWrite(leftMotorIn3, HIGH);
 digitalWrite(leftMotorIn4, LOW);
 delay(4000);
 // Stop left motor
 digitalWrite(leftMotorIn3, HIGH);
 digitalWrite(leftMotorIn4, HIGH);
 delay(500);
 
 // Rotate right motor counterclockwise
 digitalWrite(rightMotorIn1, LOW);
 digitalWrite(rightMotorIn2, HIGH);
 delay(4000);
 // Stop right motor
 digitalWrite(rightMotorIn1, HIGH);
 digitalWrite(rightMotorIn2, HIGH);
 delay(500);
 //Rotate left motor counterclockwise
 digitalWrite(leftMotorIn3, LOW);
 digitalWrite(leftMotorIn4, HIGH);
 delay(4000);
 // Stop left motor
 digitalWrite(leftMotorIn3, HIGH);
 digitalWrite(leftMotorIn4, HIGH);
 delay(500);
}


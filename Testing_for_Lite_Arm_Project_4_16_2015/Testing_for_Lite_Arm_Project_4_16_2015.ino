// Testing for Lite Arm Project  4/16/2015
//     http://www.thingiverse.com/thing:407800
#include <Servo.h>

Servo servobase;         
Servo servoshoulder;         
Servo servoforearm;

void setup() { 
  servobase.attach(9);  // Set servo to digital pin 9, min, max
  servoshoulder.attach(10);  // Set servo to digital pin 10, min, max
  servoforearm.attach(11); // Set servo to digital pin 11, min, max
} 

void loop() {            // Loop through motion tests
  middle();     //go to start pos           
  delay(2500); // Wait 1000 milliseconds (1 seconds)
  left();
  delay(2500);
  right();
  delay(2500);
}


void middle() {
  servobase.writeMicroseconds(1500); //1500 is the midpoint
  servoshoulder.writeMicroseconds(1500);
  servoforearm.writeMicroseconds(1500);
  
}
void left() {
  servobase.writeMicroseconds(1500); //1000 is all the way left
  servoshoulder.writeMicroseconds(1500);
  servoforearm.writeMicroseconds(1500);
  
}
void right() {
  servobase.writeMicroseconds(1500); //2000 is all the way right
  servoshoulder.writeMicroseconds(1500);
  servoforearm.writeMicroseconds(1500);
  
}

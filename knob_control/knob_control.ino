#include <Servo.h> 

//Servo base;  // create servo object to control a servo 
//Servo J1;
//Servo J2;

int potbase = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
int pot_J1 = A5;
int val_J1;
int pot_J2 = A4;
int val_J2;
//int pot_J2 = A2;
//int val_J2;

void setup() 
{ 
  //base.attach(9);  // attaches the servo on pin 9 to the servo object 
  //J1.attach(10);
  //J2.attach(11);
  Serial.begin(9600);
} 

void loop() 
{ 
  val_J1 = analogRead(pot_J1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val_J1 = map(val_J1, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  
  val_J2 = analogRead(pot_J2);            // reads the value of the potentiometer (value between 0 and 1023) 
  val_J2 = map(val_J2, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  
  //val = 90;
  //val_J1 = analogRead(pot_J1);
  //val_J1 = map(val_J1, 0, 1023, 0, 179);
  Serial.print("J1: ");
  Serial.print(val_J1);
  Serial.print("\t J2: ");
  Serial.println(val_J2);
  //base.write(val);                  // sets the servo position according to the scaled value 
  //J1.write(val_J1);
  delay(15);                           // waits for the servo to get there 
} 


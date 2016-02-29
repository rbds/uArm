#include <Servo.h> 

int potbase = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
int pot_J1 = A5;
int val_J1;
int pot_J2 = A4;
int val_J2;


void send_command(int servo_num, int servo_pos) {
  Serial.write(0xFF);
  Serial.write(0x00);
  Serial.write(0x0F);
  
//  Serial.print(255);
//  Serial.print(servo_num);
//  Serial.print(servo_pos);
//  
}

void setup() 
{ 
  //base.attach(9);  // attaches the servo on pin 9 to the servo object 
  //J1.attach(10);
  //J2.attach(11);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  
  Serial.begin(2400);
} 

void loop() 
{ 
  val_J1 = analogRead(pot_J1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val_J1 = map(val_J1, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  
  val_J2 = analogRead(pot_J2);            // reads the value of the potentiometer (value between 0 and 1023) 
  val_J2 = map(val_J2, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  
  send_command( 0, 0); 
  delay(100);                           // waits for the servo to get there 
} 



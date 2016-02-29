#include <SoftwareSerial.h>

// Arduino pin connected to Pololu Servo Controller
const int servoController = 1;  

// location of Servo plugged into Pololu Servo Controller (defaults 0-7)
const int servo0 = 0;  
const int J1 = 1;
const int J2 = 2;


#define rxPin 2
#define txPin 3
// set up a new serial port
SoftwareSerial ss =  SoftwareSerial(rxPin, txPin);

int potbase = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
int pot_J1 = A5;
int val_J1;
int pot_J2 = A4;
int val_J2;


void setup() {
   pinMode(rxPin, INPUT);
 digitalWrite(txPin, HIGH); // keeps pololu board from getting spurious signal
 pinMode(txPin, OUTPUT);
 
 // set the data rate for the hardware serial port
 Serial.begin(9600);
 // set the data rate for the SoftwareSerial port
 ss.begin(9600);
 
 
  servoSetSpeed(servo0,127);
}

void loop() {
  val_J1 = analogRead(pot_J1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val_J1 = map(val_J1, 0, 1023, 500, 5000);     // scale it to use it with the servo (value between 0 and 180) 
  
  val_J2 = analogRead(pot_J2);            // reads the value of the potentiometer (value between 0 and 1023) 
  val_J2 = map(val_J2, 0, 1023, 500, 5000);     // scale it to use it with the servo (value between 0 and 180) 
  
  servoMove(J1,val_J1);
  servoMove(J2, val_J2);
  delay(50);
  //servoMove(servo0,4000);
  Serial.print("J1: ");
  Serial.print(val_J1);
  Serial.print("\t J2: ");
  Serial.println(val_J2);
}

/*
    Move Servo using Pololu Servo Controller
    servo = servo number (default 0-7)
    hornPos = position (500-5500)  {Test your servos maximum positions}
*/
void servoMove(int servo, int pos)
{
  if( pos > 5500 || pos < 500 ) return;   

  // Build a Pololu Protocol Command Sequence 
  char cmd[6];   
  cmd[0] = 0x80;  // start byte   
  cmd[1] = 0x01;  // device id   
  cmd[2] = 0x04;  // command number   
  cmd[3] = servo; //servo number   
  cmd[4] = lowByte(pos >> 7);   // lower byte
  cmd[5] = lowByte(pos & 0x7f); // upper byte

  // Send the command to the Pololu Servo Controller
  for ( int i = 0; i < 6; i++ ){
    ss.write(cmd[i]);
  }

}

/*
*    Set Servo Speed using Pololu Servo Controller
*    servo = servo number (default 0-7)
*    speed = (1-127) (slowest - fastest) 0 to disable speed control
*/
void servoSetSpeed(int servo, int speed){

   // Build a Pololu Protocol Command Sequence
   char cmd[5];
   cmd[0] = 0x80;     // start byte
   cmd[1] = 0x01;     // device id
   cmd[2] = 0x01;     // command number
   cmd[3] = lowByte(servo);    // servo number
   cmd[4] = lowByte(speed);    // speed

  // Send the command to the Pololu Servo Controller
   for ( int i = 0; i < 5; i++ ){
      ss.write(cmd[i]);
   }
}

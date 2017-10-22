#include <Servo.h>
int servoPin = 9;
Servo spool;
int buttonPin = 8;
int pos_servo = 180;
int i=0;
int servoDelay = 10;
bool buttonState = false;
bool newButtonState;

void setup() {
pos_servo = 0;
Serial.begin(9600);
pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
 Serial.println(digitalRead(buttonPin));
 if (digitalRead(buttonPin) == 0){
  Serial.println("got here");
  Serial.println(digitalRead(buttonPin));
  pullChain();
  }

}

void pullChain(){
  spool.attach(servoPin);
  for(pos_servo >= 0; pos_servo<180;){
    spool.write(pos_servo);
    delay(servoDelay);
    pos_servo++;
   // Serial.println(pos_servo);
    }
  for(pos_servo<=180; pos_servo > 0;){
    spool.write(pos_servo);
    delay(servoDelay);
    pos_servo--;
  //  Serial.println(pos_servo);
    }
  spool.detach();
}//end pullChain


#include <Servo.h>
int servoPin = 9;
Servo spool;
int pos_servo = 180;
int i=0;
int servoDelay = 10;
void setup() {
  // put your setup code here, to run once:
pos_servo = 0;
Serial.begin(9600);

}

void loop() {
  if(i==0){
    pullChain();
    i = 1;
  }
}


void pullChain(){
  spool.attach(servoPin);
  for(pos_servo >= 0; pos_servo<180;){
    spool.write(pos_servo);
    delay(servoDelay);
    pos_servo++;
    Serial.println(pos_servo);
    }
  for(pos_servo<=180; pos_servo > 0;){
    spool.write(pos_servo);
    delay(servoDelay);
    pos_servo--;
    Serial.println(pos_servo);
    }
  spool.detach();
}//end pullChain


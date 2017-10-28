#include <Servo.h>

int servoPin = 9;
Servo spool;
int buttonPin = 8;
int pos_servo = 180;
int i=0;
int servoDelay = 10;
int relayPin = 4;
int pullSwitchPin = 7;
int incomingByte = 0;
bool state = false;

void setup() {
pos_servo = 0;
Serial.begin(9600);
pinMode(buttonPin, INPUT_PULLUP);
pinMode(relayPin, OUTPUT);
pinMode(pullSwitchPin, INPUT_PULLUP);
digitalWrite(relayPin, HIGH);
}

void loop() {
  switchPulled();
  if (Serial.available()>0){
   incomingByte = Serial.read();
   Serial.println("recieved command" + (char)incomingByte);
   if (incomingByte == 'o'){
    activateRelay();
    Serial.println("I'm pulling the chain");
   }
   else{
    Serial.println("invalid command!");
   }
   
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



void activateRelay(){
  if(digitalRead(relayPin) == 1){
    digitalWrite(relayPin, LOW);
    Serial.println("relay on");
  }
  else{
    digitalWrite(relayPin, HIGH);
    Serial.print("relay off");
  }
}//end activateRelay()




void switchPulled(){
  if (digitalRead(pullSwitchPin)== 0 && state == false){
    activateRelay();
    state = true;
  }
  else if(digitalRead(pullSwitchPin) == 1 && state == true){
    activateRelay();
    state = false;
  }
  
}


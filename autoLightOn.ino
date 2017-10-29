int relayPin = 4;
int pullSwitchPin = 2;
int incomingByte = 0;
bool state = false;

void setup() {
pos_servo = 0;
Serial.begin(9600);
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


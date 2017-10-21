#include <Servo.h>
int servoPin = 9;
Servo spool;
int pos_servo = 180;
int i;

void setup() {
  // put your setup code here, to run once:
spool.attach(servoPin);
i = 0;
pos_servo = 0;
Serial.begin(9600);
}

void loop() {
if ( i == 0){
for(pos_servo >= 0; pos_servo<180;){
  spool.write(pos_servo);
  delay(50);
  pos_servo++;
  Serial.println(pos_servo);
    }
    i=1;
  }
  if (i == 1){
    for(pos_servo<=180; pos_servo > 1;){
      spool.write(pos_servo);
      delay(50);
      pos_servo--;
      Serial.println(pos_servo);
    }
    i=2;
  }
else{
  Serial.println("what the frick");
  
}
}



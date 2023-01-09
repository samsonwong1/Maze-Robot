//Maze Robot 2

#include <Servo.h>;

Servo pingServo;
const int pingServoPin= 11;


const int pingPinT=10;
const int pingPinE=9;

int duration;
int cm;
int distance;

int leftdistance;
int rightdistance;



Servo servoLeft;
Servo servoRight;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(pingPinT,OUTPUT);
  pinMode(pingPinE,INPUT);

  pingServo.attach(pingServoPin);


  servoLeft.attach(13);
  servoRight.attach(12);

  tone(4,3000,2000);



}




void loop() {
  
  // put your main code here, to run repeatedly:
  
  pingServo.writeMicroseconds (1500);
  distance=detect();

  if (distance>=10){
   servoLeft.writeMicroseconds(1700);
   servoRight.writeMicroseconds(1300);

  delay(20);
    
  }
  else{


   servoLeft.writeMicroseconds(1500);
   servoRight.writeMicroseconds(1500);

  delay(20);
    

    pingServo.writeMicroseconds (1500);
    delay(3000);


    pingServo.writeMicroseconds (0);
    distance=detect();
    rightdistance=distance;
    delay(3000);

    pingServo.writeMicroseconds (1500);
    delay(3000);

    pingServo.writeMicroseconds (2300);
    distance=detect();
    leftdistance=distance;
    delay(3000);

    if (rightdistance>=leftdistance){
    
      for (int i=0; i<= 28; i++ ){

 
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);

  delay(20);
  
  }

  
      
    }


else if (rightdistance<leftdistance){
for (int i=0; i<= 28; i++ ){

 
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);

  delay(20);
  
  }

}
    
  }

}



int detect(){

  digitalWrite(pingPinT,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinT,HIGH);
  delayMicroseconds (10);
  digitalWrite(pingPinT,LOW);

  duration=pulseIn(pingPinE,HIGH,25000);

  cm=duration*0.034/2;

return cm;

}

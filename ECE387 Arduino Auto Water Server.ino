//www.elegoo.com
#include <Servo.h>

Servo servobottom;
Servo servoleft;          
Servo servoright; 
Servo servotop; 

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define LED 13

unsigned char carSpeed = 150;
bool state = LOW;
char getstr;

void forward(){ 
  digitalWrite(ENA,150);
  digitalWrite(ENB,100);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  Serial.println("Forward");
}

void back(){
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  Serial.println("Back");
}

void left(){
  analogWrite(ENA,carSpeed);
  analogWrite(ENB,carSpeed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH); 
  Serial.println("Left");
}

void right(){
  analogWrite(ENA,carSpeed);
  analogWrite(ENB,carSpeed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  Serial.println("Right");
}

void stop(){
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("Stop!");
}

void stateChange(){
  state = !state;
  digitalWrite(LED, state);
  Serial.println("Light");  
}
void pick(){
  
  servotop.write(90);
  delay(2000);
  servotop.write(180);
  delay(2000);
  servoright.write(120);
  delay(2000);
  servotop.write(0);
  delay(2000);
  servoright.write(0);
  delay(2000);
  
  
}
void pick2(){

  servobottom.write(180);
  delay(2000);
  servoright.write(120);
  delay(2000);
  servotop.write(180);
  delay(2000);
  servoright.write(0);
  delay(2000);
  servotop.write(0);
  delay(2000);
  servobottom.write(90);
  delay(2000);
  
  
}





void setup() { 
  Serial.begin(9600);
  pinMode(LED, OUTPUT); 
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  stop();
  servotop.attach(10);
  servoleft.attach(1);
  servoright.attach(3);
  servobottom.attach(4); 
}

void loop() { 

  getstr = Serial.read();
  switch(getstr){
    case 'A':
    servoright.write(0);
    forward();
    delay(3000);
    stop();
    delay(1000);
    pick();
    back();
    delay(2000);
    stop();
    delay(1500);
    pick2();
    back();
    delay(1000);
    stop();
    break;
  

    case 'B':
    servoright.write(0);
    forward();
    delay(3000);
    stop();
    delay(1000);
    pick();
    back();
    delay(3000);
    stop();
    delay(1500);
    pick2();
    stop();
    break;


    case 'C':
    servoright.write(0);
    forward();
    delay(3000);
    stop();
    delay(1000);
    pick();
    back();
    delay(4000);
    stop();
    delay(1500);
    pick2();
    forward();
    delay(1000);
    stop();
    break;
  }
    
    
}


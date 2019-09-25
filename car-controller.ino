#include <SoftwareSerial.h>
#include <Servo.h>

#define motor 6
#define pinServo 8
#define farolFrontal 2

SoftwareSerial serial(10, 11);
Servo servo;

void setup() {
  // put your setup code here, to run once:
  serial.begin(9600);
  Serial.begin(9600);
  servo.attach(pinServo);
  pinMode(motor, OUTPUT);
  pinMode(farolFrontal, OUTPUT);
  digitalWrite(motor, LOW);
  digitalWrite(farolFrontal, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte dados;
  if(serial.available()) {
    dados = serial.read();
    Serial.println(dados);
    
    if(dados == 83){
      servo.write(90);  
      digitalWrite(motor, LOW);
    }else if(dados == 76) {
      servo.write(150);
      digitalWrite(motor, LOW);
    }else if(dados == 82) {
      servo.write(30);
      digitalWrite(motor, LOW);
    }else if(dados == 70) {
      servo.write(90);
      digitalWrite(motor, HIGH);
    }else if(dados == 71) {
      servo.write(150);
      digitalWrite(motor, HIGH);
    }else if(dados == 73) {
      servo.write(30);
      digitalWrite(motor, HIGH);
    }else{
      servo.write(90);
      digitalWrite(motor, LOW);
    }

    if(dados == 87) {
      digitalWrite(farolFrontal, HIGH);
    }

    if(dados == 119) {
      digitalWrite(farolFrontal, LOW);
    }
    
  }
  delay(10);
}

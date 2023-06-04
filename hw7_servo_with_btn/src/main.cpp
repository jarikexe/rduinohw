#include <Arduino.h>
#include <NanitLib.h>

Servo servo;

void setup() {
  Nanit_Base_Start();
  Serial.begin(9600);
  servo.attach(P4_4);
  pinMode(P4_3, INPUT);
  pinMode(P4_2, INPUT_PULLUP);
  pinMode(P4_1, INPUT_PULLUP);
  servo.write(0);
}

void loop() {
  if(digitalRead(P4_1)) {
    servo.write(60);
  }
  if(digitalRead(P4_2)) {
    servo.write(120);
  }
    if(digitalRead(P4_3)) {
    servo.write(180);
  }
}
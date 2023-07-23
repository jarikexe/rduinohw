#include <Arduino.h>

#define MICROPHONE_PIN A0
#define RED_PIN A1
#define GREEN_PIN A3
#define BLUE_PIN A2
void paintRGB(int r, int g, int b);
int diod_states[4][3] = {
  {0, 0, 0},
  {255, 0, 0},
  {0,255,0},
  {0, 0, 255},
};
int initial_diod_state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MICROPHONE_PIN, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  int noise_lvl = analogRead(MICROPHONE_PIN);
  if (noise_lvl > 302) {
    Serial.println(noise_lvl);
    paintRGB(diod_states[initial_diod_state][0], diod_states[initial_diod_state][1], diod_states[initial_diod_state][2]);
    if(initial_diod_state < 3) {
      initial_diod_state++;
    } else {
      initial_diod_state = 0;
    }
    delay(500);
  }
}

void paintRGB(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

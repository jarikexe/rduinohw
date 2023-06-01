#include <Arduino.h>
#include <NanitLib.h>

#define red P4_2
#define green P4_4
#define blue P4_3
#define potPin P4_1



void setup() {
  Nanit_Base_Start();
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(blue, OUTPUT);
}

void set_rgb(byte r, byte g, byte b);

void loop() {
  int pot = analogRead(potPin);
  int pot_map = map(pot, 0, 1023, 0, 1022);
  int base_devider = 146;
//red to yellow 
  if(pot_map < base_devider) {
    int pot_g = map(pot_map, 0, base_devider, 0, 255);
    set_rgb(255, pot_g, 0);
//yellow to green
  } else if(pot_map > base_devider && pot_map < base_devider*2) {
    int pot_g = map(pot_map, base_devider, base_devider*2, 0, 255);
    int fin_r = 255 - pot_g;
    set_rgb(fin_r, 255, 0);
//green to blue
  } else if(pot_map > base_devider * 2 && pot_map < base_devider*3) {
    int pot_g = map(pot_map, base_devider*2, base_devider*3, 0, 255);
    set_rgb(0, 255, pot_g);
  }
  // blue to dark blue 
  else if(pot_map > base_devider * 3 && pot_map < base_devider*4) {
    int pot_g = map(pot_map, base_devider*3, base_devider*4, 0, 255);
    
    set_rgb(0, 255 - pot_g, 255);
  }
  //blue to purple 
  else if(pot_map > base_devider * 4 && pot_map < base_devider*5) {
    int pot_g = map(pot_map, base_devider*4, base_devider*5, 0, 255);
    
    set_rgb(pot_g, 0, 255);
  }

  //blue to purple 
  else if(pot_map > base_devider * 5 && pot_map < base_devider*6) {
    int pot_g = map(pot_map, base_devider*5, base_devider*6, 0, 255);
    set_rgb(255, 0, 255 - pot_g);
  }
}

void set_rgb(byte r, byte g, byte b) {
  Serial.print(r);
  Serial.print(',');
  Serial.print(g);
  Serial.print(',');
  Serial.println(b);
  analogWrite(red,r);
  analogWrite(green,g);
  analogWrite(blue, b);
}

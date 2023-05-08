#include <bits/stdc++.h>
using namespace std;

const int LED_PINS[] = {25, 2, 27, 18};  // yellow, blue, green, red
const int BUTTON_PINS[] = {34, 35, 32, 13};  // yellow, blue, green, red
const int restart=4;
const int NUM_LEDS = 4;
const int NUM_BUTTONS = 4;
vector<int> player_sequence;
vector<int> sequence;
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);  // onboard LED
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }
  pinMode(restart,INPUT_PULLUP);
  Serial.begin(9600);
  
}
void resetESP32() {
  // Disable interrupts
  noInterrupts();

  // Restart the ESP32
  ESP.restart();

  // Wait for the restart to take effect
  while (true) {}
}


void machine_turn(vector<int>& psequence){
  int random_number = random(0, 4);
  psequence.push_back(random_number);
  for(int i=0;i<psequence.size();i++){
    digitalWrite(LED_PINS[psequence[i]],HIGH);
    delay(500);
    digitalWrite(LED_PINS[psequence[i]],LOW);
    delay(500);
  }
}


void player_turn(vector<int> psequence, vector<int> pplayer_sequence){
  player_sequence.clear();
  while(pplayer_sequence.size()<psequence.size()){
    if(digitalRead(BUTTON_PINS[0])==HIGH){
      pplayer_sequence.push_back(0);
      digitalWrite(LED_PINS[0],HIGH);
      delay(500);
       digitalWrite(LED_PINS[0],LOW);
      
    }  
    else if(digitalRead(BUTTON_PINS[1])==HIGH){
      pplayer_sequence.push_back(1);
      digitalWrite(LED_PINS[1],HIGH);
      delay(500);
       digitalWrite(LED_PINS[1],LOW);
    }
    
    else if(digitalRead(BUTTON_PINS[2])==HIGH){
      pplayer_sequence.push_back(2);
      digitalWrite(LED_PINS[2],HIGH);
      delay(500);
       digitalWrite(LED_PINS[2],LOW);
    }
    
    else if(digitalRead(BUTTON_PINS[3])==HIGH){
      pplayer_sequence.push_back(3);
      digitalWrite(LED_PINS[3],HIGH);
      delay(500);
       digitalWrite(LED_PINS[3],LOW);
    }
    else if(digitalRead(restart)==HIGH){
    resetESP32();
  }
    for(int i=0;i<pplayer_sequence.size();i++){
      if(pplayer_sequence[i]!=psequence[i]){
        gameover();
      }
    }
   
  }
  delay(500);
}
void gameover(){
  digitalWrite(LED_PINS[0],HIGH);
  digitalWrite(LED_PINS[1],HIGH);
  digitalWrite(LED_PINS[2],HIGH);
  digitalWrite(LED_PINS[3],HIGH);
  delay(1000);
  digitalWrite(LED_PINS[0],LOW);
  digitalWrite(LED_PINS[1],LOW);
  digitalWrite(LED_PINS[2],LOW);
  digitalWrite(LED_PINS[3],LOW);
  resetESP32();

}


void loop(){
  if(digitalRead(restart)==HIGH){
    resetESP32();
  }
  machine_turn(sequence);
  player_turn(sequence, player_sequence);
}
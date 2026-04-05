const int qizil1 = 2;
const int sariq1 = 3;
const int yashil1 = 4;
const int qizil2 = 5;
const int sariq2 = 6;
const int yashil2 = 7;
const int buzzer = 8;

void setup() {
  pinMode(qizil1, OUTPUT);
  pinMode(sariq1, OUTPUT);
  pinMode(yashil1, OUTPUT);
  pinMode(qizil2, OUTPUT);
  pinMode(sariq2, OUTPUT);
  pinMode(yashil2, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(yashil1, HIGH);
  digitalWrite(qizil2, HIGH);
  digitalWrite(qizil1, LOW);
  digitalWrite(sariq1, LOW);
  digitalWrite(sariq2, LOW);
  digitalWrite(yashil2, LOW);

  
  for (int i = 0; i < 13; i++) {
    tone(buzzer, 1000); 
    delay(100);
    noTone(buzzer);
    delay(100);
    
    tone(buzzer, 1000); 
    delay(100);
    noTone(buzzer);
    
    delay(500); 
  }

  digitalWrite(yashil1, LOW);
  digitalWrite(qizil2, LOW);
  digitalWrite(sariq1, HIGH);
  digitalWrite(sariq2, HIGH);
  delay(1500); 

  digitalWrite(sariq1, LOW);
  digitalWrite(sariq2, LOW);
  digitalWrite(qizil1, HIGH);
  digitalWrite(yashil2, HIGH);
  delay(20000); 

  digitalWrite(yashil2, LOW);
  digitalWrite(sariq1, HIGH);
  digitalWrite(sariq2, HIGH);
  delay(1000);
  
  digitalWrite(qizil1, LOW);
  digitalWrite(sariq1, LOW);
  digitalWrite(sariq2, LOW);
}


// Attention: You should have 2 red leds , 2 yellow leds and 2 green leds, buzzer (passive) and Arduino Uno or Nano 
// Schema:
// All led gnd connected to gnd
// 1 - traffic lights:
// red: d2
// yellow: d3
// green: d4
// 2- traffic lights:
// red: d5
// yellow: d6
// green: d7
// buzzer (it helps to cross the way for blind pedestrians):
// + (vcc) : d8
// - (gnd) : gnd


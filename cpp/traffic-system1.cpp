    // ====== 2 Svetofor + 2 IR + 1 PASSIVE Buzzer (faqat sezganda beep) ======

const int RA = 2;
const int YA = 3;
const int GA = 4;

const int RB = 5;
const int YB = 6;
const int GB = 7;

const int IR1 = 8;
const int IR2 = 9;

const int BUZZER = 10;  // passive buzzer

// Ko‘p IR obstacle sensorlarda: sezsa LOW bo‘ladi
// Agar sendagi teskari bo‘lsa, HIGH qil.
const int IR_ACTIVE = LOW;

// vaqtlar (millisekund)
const unsigned long RED_TIME    = 20000;
const unsigned long YELLOW_TIME = 2000;
const unsigned long GREEN_TIME  = 20000;

bool prevDetected = false; // oldingi holat

void setLights(bool red, bool yellow, bool green) {
  digitalWrite(RA, red);
  digitalWrite(YA, yellow);
  digitalWrite(GA, green);

  digitalWrite(RB, red);
  digitalWrite(YB, yellow);
  digitalWrite(GB, green);
}

bool objectDetected() {
  return (digitalRead(IR1) == IR_ACTIVE) ||
         (digitalRead(IR2) == IR_ACTIVE);
}

// Passive buzzer uchun beep (tone bilan)
void beepOnce() {
  tone(BUZZER, 2000);   // 2000 Hz
  delay(150);
  noTone(BUZZER);
}

void runPhase(unsigned long duration, bool isRedPhase) {
  unsigned long startTime = millis();

  while (millis() - startTime < duration) {

    bool nowDetected = objectDetected();

    if (isRedPhase) {
      // faqat yangi sezilganda (false -> true) beep
      if (nowDetected && !prevDetected) {
        beepOnce();
      }
      prevDetected = nowDetected;
    } else {
      // sariq/yashilda buzzer ishlamasin
      noTone(BUZZER);
      // xohlasang reset qilamiz:
      prevDetected = false;
    }

    delay(20);
  }

  noTone(BUZZER);
}

void setup() {
  pinMode(RA, OUTPUT);
  pinMode(YA, OUTPUT);
  pinMode(GA, OUTPUT);

  pinMode(RB, OUTPUT);
  pinMode(YB, OUTPUT);
  pinMode(GB, OUTPUT);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);

  setLights(true, false, false); // start: red
}

void loop() {
  // QIZIL 20s
  setLights(true, false, false);
  runPhase(RED_TIME, true);

  // SARIQ 2s
  setLights(false, true, false);
  runPhase(YELLOW_TIME, false);

  // YASHIL 20s
  setLights(false, false, true);
  runPhase(GREEN_TIME, false);
}
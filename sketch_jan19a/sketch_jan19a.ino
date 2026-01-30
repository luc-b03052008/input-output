#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pin definitions
const int BUTTON_PIN = 7;    
const int LED_PIN = 9;       
const int LED_BRIGHTNESS = 255;

// Speaker pin
const int SPEAKER_PIN = 8;

// Button debounce variabelen
int buttonState = HIGH;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;

const unsigned long debounceDelay = 50;

// LED toggle status
bool ledOn = true;

// ----------------------
// Melody from Arduino example
// ----------------------
#include "pitches.h"

int melody[] = { NOTE_E5, NOTE_G5, NOTE_C6, NOTE_G5, NOTE_E6, NOTE_C6, NOTE_D6, NOTE_B5, NOTE_G5, NOTE_C6, NOTE_E6 };
int noteDurations[] = { 8, 8, 4, 4, 4, 8, 8, 4, 8, 8, 2 };

void playMelody() {
  for (int i = 0; i < 11; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(SPEAKER_PIN, melody[i], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(SPEAKER_PIN);
  }
}

// ----------------------


void setup() {

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  
  analogWrite(LED_PIN, LED_BRIGHTNESS);
  
  Serial.begin(9600);
  Serial.println("Lighted Arcade Button Ready!");

  lcd.begin(16, 2);
  lcd.clear();

  lcd.print("begin spel");
  delay(2000);

  lcd.clear();
  lcd.print(" nummer 1");
  delay(1000);

  lcd.clear();
  lcd.print(" nummer 2");
  delay(1000);

  lcd.clear();
  lcd.print(" nummer 3 laatste");
  delay(1000);

  bool antwoordGoed = true;

  lcd.clear();
  if (antwoordGoed) {
    lcd.print("Goed!");
    delay(1500);
    lcd.clear();
    lcd.print("Gewonnen!");
  } else {
    lcd.print("Fout!");
    delay(1500);
    lcd.clear();
    lcd.print("Game Over");
  }

  delay(2000);

  lcd.clear();
  lcd.print("Einde spel");

  
  playMelody();
}

void loop() {

  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        ledOn = !ledOn;
      }
    }
  }

  lastButtonState = reading;
}

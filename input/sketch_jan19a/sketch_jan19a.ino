#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

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

  // Controle (voorbeeld)
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

  // Einde spel
  lcd.clear();
  lcd.print("Einde spel");
}

void loop() {
  // niets nodig
}


 

// include the library code:
#include <LiquidCrystal.h>
#include <math.h>
// Устанавливаем номера пинов к которым подключен дисплей
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Устанавливаем количество символов в строке (16) и количство строк (2) 
  lcd.begin(16, 2);
  // Выводим на дисплей надпись "хххххххх"
  lcd.print("Temp");
}



double Thermister(int RawADC) {
  double Temp;
  // See http://en.wikipedia.org/wiki/Thermistor for explanation of formula
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;           // Перевод в градусы Цельсия
  return Temp;
}

void printTemp(void) {
  double fTemp;
  double temp = Thermister(analogRead(0));  // чтение данных с аналогового выхода 1
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature is:");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.print(" C / ");
  fTemp = (temp * 1.8) + 32.0;    // Convert to USA
  lcd.print(fTemp);
  lcd.print(" F");
  if (fTemp > 68 && fTemp < 78) {
    lcd.setCursor(0,3);
    lcd.print("Very comfortable");
  }
}

void loop(void) {
  printTemp();
  delay(1000);
}








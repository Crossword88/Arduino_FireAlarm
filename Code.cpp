//подключение библиотеки для работы с LCD
#include <LiquidCrystal.h>

//инициализируем LCD с указанием контактов
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

//создаем свои символы

void setup()
{
//начало работы, с указанием размерности экрана
 lcd.begin(16, 2);
 lcd.setCursor(0,0);
 lcd.write("Normal");
 lcd.setCursor(0,1);
 lcd.write("temperature");
 pinMode(6, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(3, OUTPUT);
 digitalWrite(5, HIGH);
 pinMode(2, OUTPUT);
 pinMode(1, OUTPUT);
 pinMode(0, OUTPUT);
 digitalWrite(2, HIGH);
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
}

void loop()
{
 int const x = analogRead (A0);
 int const y = analogRead (A1);
 if (x > 306 && y == 306)
 {
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write("Alarm");
 lcd.setCursor(0,1);
 lcd.write("fire in room 1");
 digitalWrite(4, HIGH);
 digitalWrite(3, LOW);
 tone(13, 300);
 delay(250);
 noTone(13);
 delay(250);
 tone(13, 300);
 digitalWrite(6, HIGH);
 delay(300);
 digitalWrite(6, LOW);
 noTone(13);
 lcd.clear();
 }
  
 if (y > 306 && x == 306)
 {
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write("Alarm");
 lcd.setCursor(0,1);
 lcd.write("fire in room 2");
 digitalWrite(1, HIGH);
 digitalWrite(0, LOW); 
 tone(13, 300);
 delay(350);
 noTone(13);
 delay(350);
 tone(13, 300);
 digitalWrite(6, HIGH);
 delay(300);
 digitalWrite(6, LOW);
 noTone(13);
 lcd.clear();
 }
  
 if (x > 306 && y > 306)
 {
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write("Alarm");
 lcd.setCursor(0,1);
 lcd.write("fire in room 1 2");
 digitalWrite(4, HIGH);
 digitalWrite(3, LOW);
 digitalWrite(1, HIGH);
 digitalWrite(0, LOW); 
 tone(13, 300);
 delay(350);
 noTone(13);
 delay(350);
 tone(13, 300);
 digitalWrite(6, HIGH);
 delay(300);
 digitalWrite(6, LOW);
 noTone(13);
 lcd.clear();
 digitalWrite(4, LOW);
 digitalWrite(3, LOW);
 digitalWrite(1, LOW);
 digitalWrite(0, LOW); 
 }
 
 if (x == 306 && y == 306)
 {
 digitalWrite(4, LOW);
 digitalWrite(3, LOW);
 digitalWrite(1, LOW);
 digitalWrite(0, LOW);  
 lcd.setCursor(0,0);
 lcd.write("Normal");
 lcd.setCursor(0,1);
 lcd.write("temperature");
 }
}
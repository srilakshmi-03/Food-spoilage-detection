#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int redLed = 4;
int greenLed = 3;
int piezo = 2;
int gasSensor = A0;

int sensorThres = 400;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Food Spoilage ");
  delay(1000);
  lcd.clear();
  pinMode (redLed, OUTPUT);
  pinMode (greenLed, OUTPUT);
  pinMode (piezo, OUTPUT);
  pinMode (gasSensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(gasSensor);
  Serial.println(analogSensor);
  if (analogSensor < sensorThres)
  {
    digitalWrite(redLed, HIGH); 
    digitalWrite(greenLed, LOW); 
    lcd.setCursor(0,0);
    lcd.print("Food Spoiled"); 
    tone (piezo, 1000, 200);
  }
  else
  {
    digitalWrite (redLed, LOW);
    digitalWrite (greenLed, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Food not spoiled");
    noTone(piezo);
	}
delay(500);
}
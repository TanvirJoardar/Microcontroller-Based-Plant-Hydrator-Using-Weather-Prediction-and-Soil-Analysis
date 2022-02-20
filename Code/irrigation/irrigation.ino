#include<LiquidCrystal.h>

LiquidCrystal lcd(5,6,8,9,10,11); // RS,E,D4,D5,D6,D7

int SensorPin = A0;
int tempSensorPin = A1;
int relay = 7;
int ledLight = 3;
int sound = 4;
float temp, com = 30;
int pampVal = 0;

void setup() {
  
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);

  pinMode(sound, OUTPUT);
  digitalWrite(sound, LOW);

  pinMode(ledLight, OUTPUT);
  digitalWrite(ledLight, LOW);
  
  lcd.begin(20,4);

}

void loop() {
  int SensorValue = analogRead(SensorPin);
  SensorValue = map(SensorValue, 1019, 19, 0, 100);   
  float temp = analogRead(tempSensorPin);  
  temp = temp*5000/(1024*10); 

  lcd.setCursor(0,0);
  lcd.print("--SMART IRRIGATION--");
  lcd.setCursor(0,1);
  lcd.print("MOISTURE LEVEL:");
  lcd.setCursor(0,2);
  lcd.print("TEMPERATURE: ");
  lcd.setCursor(2,3);
  lcd.print("PAMP: ");

  if(SensorValue >= 70)
  {
      lcd.setCursor(16, 1);  
      lcd.print(SensorValue);
      lcd.print("%");
      lcd.setCursor(13, 2);  
      lcd.print(temp);     
      lcd.print(" C");
      lcd.setCursor(10, 3);
      lcd.print("OFF");

      digitalWrite(relay, LOW);
      digitalWrite(ledLight, LOW);
      digitalWrite(sound, LOW);

  }
    else if(SensorValue < 70 && temp < 40)
    {
      lcd.setCursor(16, 1);  
      lcd.print(SensorValue);
      lcd.print("%");
      lcd.setCursor(13, 2);  
      lcd.print(temp);     
      lcd.print(" C");
      lcd.setCursor(10, 3);
      lcd.print("ON");

      digitalWrite(relay, HIGH);
      digitalWrite(ledLight, HIGH);
      digitalWrite(sound, LOW);

    }
    else if(temp >= 40 && SensorValue < 70 )
    {
      lcd.setCursor(16, 1);  
      lcd.print(SensorValue);
      lcd.print("%");
      lcd.setCursor(13, 2);  
      lcd.print(temp);     
      lcd.print(" C");
      lcd.setCursor(10, 3);
      lcd.print("OFF");

      digitalWrite(relay, LOW);
      digitalWrite(ledLight, LOW);
      digitalWrite(sound, HIGH);

    }
    

  delay(5000);
  lcd.clear();


}

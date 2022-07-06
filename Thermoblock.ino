#include <Wire.h>
#include <Adafruit_MAX31865.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Use software SPI: CS, SDI, SDO, CLK
Adafruit_MAX31865 thermo = Adafruit_MAX31865(10,11,12,13);

#define RREF      4400
#define RNOMINAL  1000

#define Fan 2
#define heater 3
#define cooler 4 

float p;
float Temp;



void setup() {
  
  Serial.begin (9600);
  lcd.init();
  lcd.backlight();

  pinMode(A0,INPUT);
  pinMode(Fan, OUTPUT);
  pinMode(cooler, OUTPUT);
  pinMode(heater, OUTPUT); 
  digitalWrite(Fan, HIGH);
  digitalWrite(cooler, HIGH);
  digitalWrite(heater, HIGH); 
  
    thermo.begin(MAX31865_2WIRE);

}


void Func1H(){

  if (Temp>p){
    digitalWrite(Fan, LOW);
    digitalWrite(cooler, HIGH);
    digitalWrite(heater, HIGH);

    lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  }
  
  if (Temp<p){
    digitalWrite(Fan, HIGH);
    digitalWrite(cooler, HIGH);
    digitalWrite(heater, LOW);

    lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  }
    
  
}
void Func2C(){
  
     if (Temp>p){
    digitalWrite(Fan, LOW);
    digitalWrite(cooler, LOW);
    digitalWrite(heater, HIGH);

    lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  }
  
  if (Temp<p){
    digitalWrite(Fan, LOW);
    digitalWrite(cooler, HIGH);
    digitalWrite(heater, HIGH);

    lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  }
    
}
void wait(){
      lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);

   digitalWrite(Fan, HIGH);
   digitalWrite(cooler, HIGH);
   digitalWrite(heater, HIGH);

    
        lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);

}
  
void loop() {
   lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  
  uint16_t rtd = thermo.readRTD();
  float ratio = rtd;
  ratio /= 32768;
  Temp = thermo.temperature(RNOMINAL, RREF);
  p = analogRead(A0)/8;
  
  while (p>25){
      lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  
  uint16_t rtd = thermo.readRTD();
  float ratio = rtd;
  ratio /= 32768;
  Temp = thermo.temperature(RNOMINAL, RREF);
  p = analogRead(A0)/8;
 Func1H();
 
  }
      lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  
  wait();
  
    lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  

  
  ratio /= 32768;
  Temp = thermo.temperature(RNOMINAL, RREF);
  p = analogRead(A0)/8;
  delay(5000);
  
 while (p<25){
    lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  

  ratio /= 32768;
  Temp = thermo.temperature(RNOMINAL, RREF);
  p = analogRead(A0)/8;
  Func2C();
 }
     lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  
wait();

  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(7,0);
  lcd.print(Temp);

  p = analogRead(A0)/8;
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.setCursor(3, 1);
  lcd.print(p);
  


  ratio /= 32768;
  Temp = thermo.temperature(RNOMINAL, RREF);
  p = analogRead(A0)/8;
  delay(5000);
 
  
   


}

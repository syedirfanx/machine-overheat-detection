#include<LiquidCrystal.h>
float sinVal;
int toneVal;
unsigned long tepTimer ;
LiquidCrystal lcd(7,6,5,4,3,2); 
int pin = 0;
int value;
void setup() {
  pinMode(8, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}
void loop() {
  int val;
  double data;
  val=analogRead(0); 
  data = (double) val * (5/10.24);
  value = analogRead(pin);
  int volt = value*5.0/1024.0;
  double temp=volt*1000/10; 
  if(data>20){ 
    for(int x=0; x<180; x++){
    sinVal = (sin(x*(3.1412/180)));
    toneVal = 2000+(int(sinVal*1000));
    tone(8, toneVal);
    delay(2);
    }
  } else {                              
  noTone(8);                     
  }
  if(millis() - tepTimer > 50){
  tepTimer = millis();
  Serial.print("temperature: "); 
  Serial.print(data); 
  Serial.println("°C");
  lcd.setCursor(2,0);
  lcd.print("Temperature:");
  lcd.setCursor(4,1);
  lcd.print(data);
  lcd.print(" C");
  }
}

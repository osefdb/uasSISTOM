//Libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Pins Declaration
#define water 10
#define sugar 11
#define coffee 12
#define mixer 13
int button[]={2,3,4,5};
int motor[]={6,7,8,9};

//Variable Declaration
String flavour[]={"Latte","Cappucino","Espresso","Mocha"};
int price[]={5,5,8,8};

//Object Declaration
LiquidCrystal_I2C lcd(0x20,20,4);

//Setup Function
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<4;i++){
    pinMode(button[i],INPUT_PULLUP);
    pinMode(motor[i],OUTPUT);
  }
  pinMode(water,OUTPUT);
  pinMode(sugar,OUTPUT);
  pinMode(coffee,OUTPUT);
  pinMode(mixer,OUTPUT);
  lcd.init();
  //Print a message to the LCD
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("DO");
  lcd.setCursor(0,1);
  lcd.print("Projects");
  lcd.setCursor(0,2);
  lcd.print("Smart Coffee");
  lcd.setCursor(0,3);
  lcd.print("Machine");
  delay(1000);
  lcd.clear();
}

//Loop Function
void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<4;i++){
    lcd.setCursor(0,i);
    lcd.print(i+1);
    lcd.print(" for ");
    lcd.print(flavour[i]);
    lcd.setCursor(17,i);
    lcd.print(price[i]);
    lcd.print("/-");
  }
  for(int i=0;i<4;i++){
    if(digitalRead(button[i])==LOW){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Wait");
      lcd.setCursor(0,1);
      lcd.print("Collecting");
      lcd.setCursor(0,2);
      lcd.print("Ingredients");
      delay(1000);
      digitalWrite(water, HIGH);
      delay(2000);
      digitalWrite(water, LOW);
      digitalWrite(sugar, HIGH);
      delay(2000);
      digitalWrite(sugar, LOW);
      digitalWrite(coffee, LOW);
      digitalWrite(motor[i], HIGH);
      delay(2000);
      digitalWrite(motor[i], LOW);
      lcd.clear();
      delay(1000);
      lcd.setCursor(0,0);
      lcd.print("Wait");
      lcd.setCursor(0,1);
      lcd.print("Yours Rich");
      lcd.setCursor(0,2);
      lcd.print(flavour[i]);
      lcd.print("is");
      lcd.setCursor(0,3);
      lcd.print("gettin ready");
      digitalWrite(mixer, HIGH);
      delay(10000);
      digitalWrite(mixer, LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Your richs");
      lcd.setCursor(0,1);
      lcd.print(flavour[i]);
      lcd.print("is ready");
      lcd.setCursor(0,2);
      lcd.print("collect it");
      lcd.setCursor(0,3);
      lcd.print("yours amount");
      lcd.print(price[i]);
      lcd.print("/-");
      delay(5000);
      lcd.clear();
    }
  }
}

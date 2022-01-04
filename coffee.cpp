//Import Libraries
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
int sen_pin=A0;
int t_c;
float t_f;
float v_t;

//Object Declaration
LiquidCrystal_I2C lcd(0x20,20,4); //size display

//Setup Function
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<4;i++){
    pinMode(button[i],INPUT_PULLUP); //input button
    pinMode(motor[i],OUTPUT); //output motor
    pinMode(sen_pin, INPUT); //input sensor lm35
    pinMode(0,OUTPUT); //output heater
  }
  pinMode(water,OUTPUT);
  pinMode(sugar,OUTPUT);
  pinMode(coffee,OUTPUT);
  pinMode(mixer,OUTPUT);
  lcd.init();
  //Print a message to the LCD
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Kelompok DOM");
  lcd.setCursor(0,1);
  lcd.print("Projects UAS");
  lcd.setCursor(0,2);
  lcd.print("Mesin Kopi");
  lcd.setCursor(0,3);
  lcd.print("Otomatis");
  delay(1000);
  lcd.clear();
}

//Loop Function
void loop() {
  v_t=analogRead(sen_pin);
  v_t=(v_t*500)/1023; //konversi voltage to temperature
  t_c=v_t;
  t_f=(v_t*1.8)+32; //konversi celcius to fahrenheit
  Serial.println(" Deg_c=");
  Serial.println(t_c);
  delay(500);
  // put your main code here, to run repeatedly:
  for(int j=0;j<4;j++){
    lcd.setCursor(0,j);
    lcd.print(j+1);
    lcd.print(" untuk ");
    lcd.print(flavour[j]);
  }
  for(int k=0;k<4;k++){
    if(digitalRead(button[k])==LOW){
      if(t_c>=80){
        digitalWrite(0,LOW);
        }
      if(t_c<80 && t_c>=0){
        digitalWrite(0,HIGH);
        }
        delay(5000); //manasin air
        digitalWrite(0,LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Mohon Tunggu");
      lcd.setCursor(0,1);
      lcd.print("Sedang Mengumpulkan");
      lcd.setCursor(0,2);
      lcd.print("Bahan-bahan");
      delay(1000);
      digitalWrite(water, HIGH);
      delay(2000);
      digitalWrite(water, LOW);
      digitalWrite(sugar, HIGH);
      delay(2000);
      digitalWrite(sugar, LOW);
      digitalWrite(coffee, HIGH);
      digitalWrite(motor[k], HIGH);
      delay(2000);
      digitalWrite(coffee, LOW);
      digitalWrite(motor[k], LOW);
      lcd.clear();
      delay(1000);
      lcd.setCursor(0,0);
      lcd.print("Mohon tunggu");
      lcd.setCursor(0,1);
      lcd.print("Kopi ");
      lcd.print(flavour[k]);
      lcd.setCursor(0,2);
      lcd.print("anda sedang");
      lcd.setCursor(0,3);
      lcd.print("disiapkan.");
      digitalWrite(mixer, HIGH);
      delay(10000);
      digitalWrite(mixer, LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kopi ");
      lcd.print(flavour[k]);
      lcd.setCursor(0,1);
      lcd.print("anda telah siap.");
      lcd.setCursor(0,2);
      lcd.print("Silahkan menikmati!");
      delay(5000);
      lcd.clear();
    }
  }
}

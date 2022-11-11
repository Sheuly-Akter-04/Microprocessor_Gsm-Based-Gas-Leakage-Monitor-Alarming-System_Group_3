#include<LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Servo.h>
Servo servo;
SoftwareSerial mySerial(9,10);
LiquidCrystal lcd(12 , 11 , 5 ,4 ,3 ,2);
int Gas = 8;
int redLed = 7;
int greenLed = 6;

void setup() {
      mySerial.begin(9600);
      Serial.begin(9600);
      pinMode(Gas , INPUT);
      servo.attach(9);
    
}

void loop() {

      if(digitalRead(Gas) == HIGH){
        lcd.setCursor(0,0);
        lcd.print(" Gas is Detected ");
        delay(1000);
        digitalWrite(7 , HIGH);
        digitalWrite(6, LOW);
        SendMessage ();
        if (mySerial.available()>0)
          Serial.write(mySerial.read());                           
        servo.write(90);               
        delay(15);
        lcd.setCursor(0,1);
        lcd.print("Gas gate is disconnected from the line ");
      }
      else{
        lcd.setCursor(0,0);
        lcd.print("No Gas Detected ");
        delay(1000);
        digitalWrite(6, HIGH);
        digitalWrite(7 ,LOW);
        servo.write(0);               
        delay(15);
        lcd.setCursor(0,1);
        lcd.print("Gas gate is connected to the line ");
      }
    delay (1000);
    lcd.clear();
}
 
 void SendMessage ()
{ 
   mySerial.println("AT+CMGF=1");
   delay (1000);
   mySerial.println("AT+CMGF=\"+8801676918878\"\r");
   delay(1000);
   mySerial.println("Hello NUHEL !!! The Gas has been leaked ! Please check ");
   mySerial.println((char)26); 
}

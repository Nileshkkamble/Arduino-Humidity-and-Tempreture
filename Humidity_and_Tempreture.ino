#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);  //sometimes the LCD adress is not 0x3f. Change to 0x27 if it dosn't work.
 DHT dht;
float humidity = dht.getHumidity();
 float temperature = dht.getTemperature();
void setup()
{
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("   Nilesh  ");
  lcd.setCursor(0,1);
  lcd.print("   Kamble ");
  delay(500);
  lcd.begin(16,2);
  lcd.clear();
  //lcd.setCursor(0,0);
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  dht.setup(7); // data pin 7
 
  

 
}
void loop()
{
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t");
  Serial.print(temperature, 1);
  Serial.print("\t");
  Serial.println(dht.toFahrenheit(temperature), 1);
  
  

  delay(dht.getMinimumSamplingPeriod());
/*  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
*/
lcd.clear();
  lcd.setCursor(0,0) ;
  lcd.print("humi.");
  lcd.print(humidity); 
  lcd.setCursor(0,1) ;
  lcd.print("temp."); 
  lcd.print(temperature);

}
  

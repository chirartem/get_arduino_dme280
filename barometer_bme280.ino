#include "Seeed_BME280.h"
#include <Wire.h>
 
BME280 bme280;
 
void setup()
{
  Serial.begin(115200);
  if(!bme280.init()){
    Serial.println("Device error!");
  }
}
 
void loop()
{
 
  Serial.println("{");
  //get and print temperatures
  Serial.print("\"t\": \"");
  Serial.print(bme280.getTemperature());
  Serial.println("\",");
 
  //get and print atmospheric pressure data
  Serial.print("\"p\": \"");
  Serial.print(bme280.getPressure());
  Serial.println("\",");

  //get and print humidity data
  Serial.print("\"h\": \"");
  Serial.print(bme280.getHumidity());
  Serial.println("\"");
  
  Serial.println("}");
 
  delay(1000);
}

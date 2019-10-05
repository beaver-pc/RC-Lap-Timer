/*Beaver's Hobby Channel presents
Idiotic Arduino Project #2v2, With Laser
Super simple lap timer
*/


#include <Wire.h>
#include <VL53L1X.h>

VL53L1X sensor;

double i = 0;
double a = millis();
double c ;
int lap = 0;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C

  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }
  
  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(20000);
  sensor.startContinuous(20);
}


void loop()
{
//  delay(10);
  if(sensor.read() < 1000)
   {
   c = millis();
   i = (c - a) / 1000;
   if(i > 1)
    { 
      lap++;
      Serial.print("Lap: ");
      Serial.print(lap);
      Serial.print("\t\t");
      Serial.println(i);
      a = millis();
    }
  }   
}

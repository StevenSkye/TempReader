#include "Adafruit_DHT.h"

// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#define DHTPIN 6     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11		// DHT 11 
//#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	
}

void loop() {

  //float h = 23.4454;
  //float t = 27.557345464;
  //float h = dht.getHumidity();
  float t = dht.getTempCelcius();
       	          	  
  // Use String to convert the float to a string
  String temperatureString =String(t);
       	  
  
  int length = temperatureString.length();
  char temperature[length];
       	  
  // Convert the string to char[]
  temperatureString.toCharArray(temperature, temperatureString.length());
       	  
  Particle.publish("Temp",temperature, PRIVATE);
  delay(30000);
}


#include "DHT.h"

#define DHTPIN 8     // Digital pin connected to the DHT sensor
#define DHT2PIN 9


#define DHTTYPE DHT11   // DHT 11


DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHT2PIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  dht.begin();
  dht2.begin();
  Serial.write(16);
  Serial.write(26);
  Serial.write(0);
  Serial.write(4);
  Serial.write(77);
  Serial.write(81);
  Serial.write(84);
  Serial.write(84);
  Serial.write(4);
  Serial.write(2);
  Serial.write(0);
  Serial.write(60);
  Serial.write(0);
  Serial.write(14);
  Serial.write(77);
  Serial.write(81);
  Serial.write(84);
  Serial.write(84);
  Serial.write(95);
  Serial.write(70);
  Serial.write(88);
  Serial.write(95);
  Serial.write(67);
  Serial.write(108);
  Serial.write(105);
  Serial.write(101);
  Serial.write(110);
  Serial.write(116);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(3000);

  float t = dht.readTemperature();
  int a = floor(t/10);
  int b = floor(t);
  int c = floor(t*10);
  int d = floor(t*100);
  b=b%10;
  c=c%10;
  d=d%10;

  float t2 = dht2.readTemperature();
  int a2 = floor(t2/10);
  int b2 = floor(t2);
  int c2 = floor(t2*10);
  int d2 = floor(t2*100);
  b2=b2%10;
  c2=c2%10;
  d2=d2%10;

  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.write("0");
  Serial.write(11);
  Serial.write(0);
  Serial.write(4);
  Serial.write(84);
  Serial.write(101);
  Serial.write(109);
  Serial.write(112);
  /////////////////////////////////////
//  Serial.print(F(" Temperature: "));
//  Serial.print(t);
//  Serial.print(F("°C "));
  Serial.print(a);
  Serial.print(b);
  Serial.write(46);
  Serial.print(c);
  Serial.print(d);

  if (isnan(t2)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.write("0");
  Serial.write(11);
  Serial.write(0);
  Serial.write(4);
  Serial.write(84);
  Serial.write(101);
  Serial.write(109);
  Serial.write(112);
  /////////////////////////////////////
//  Serial.print(F(" Temperature: "));
//  Serial.print(t);
//  Serial.print(F("°C "));
  Serial.print(a2);
  Serial.print(b2);
  Serial.write(46);
  Serial.print(c2);
  Serial.print(d2);
}

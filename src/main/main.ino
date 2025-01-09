#include "Wire.h"
#include "MAX17043.h"

void setup() {
  // put your setup code here, to run once:
  // Initialisation de la console série
  Serial.begin(9600); // Baud rate de 115200 (courant pour ESP8266)
  
  //

  // Attendre que la console soit prête
  delay(1000); 
  Serial.println("ESP8266 démarré !");

 Serial.println("Recherche des appareils I2C...");
  /*
  Wire.begin();
  for (byte i = 8; i < 120; i++) {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      Serial.print("Appareil trouvé à l'adresse 0x");
      Serial.println(i, HEX);
    }
  }
  */

  Wire.begin(SDA, SCL);
  if (!FuelGauge.begin(&Wire)) {
    Serial.println("MAX17043 NOT found.\n");
    while (true) {}
  }
  //FuelGauge.reset();
  //delay(250);
  // Recalbrer le MAX17043
  FuelGauge.quickstart();
  delay(125);

}

void loop() {
  Serial.println("Bonjour depuis l'ESP8266 !\n");

  // Attendre 1 seconde avant de répéter
  delay(1000);

  float volts = FuelGauge.voltage();
  float pcnt = FuelGauge.percent();
  Serial.printf("%.0fmV (%.1f%%)\n", volts, pcnt);
  delay(3000);

 
}

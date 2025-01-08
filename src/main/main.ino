void setup() {
  // put your setup code here, to run once:
  // Initialisation de la console série
  Serial.begin(9600); // Baud rate de 115200 (courant pour ESP8266)
  
  // Attendre que la console soit prête
  delay(1000); 
  Serial.println("ESP8266 démarré !");

}

void loop() {
  Serial.println("Bonjour depuis l'ESP8266 !\n");

  // Attendre 1 seconde avant de répéter
  delay(1000);
}

# Documentation : Fonction reset() pour MAX17043

## Description

La fonction reset() de la bibliothèque Adafruit_MAX17043 effectue une réinitialisation complète du capteur MAX17043. Cette commande renvoie le capteur à son état initial, effaçant tous les paramètres enregistrés, y compris les informations de calibration et les estimations de l'état de charge (SOC).

## Utilité

Cette fonction est utile dans les cas suivants :

Réinitialisation après un dysfonctionnement :
Si le capteur retourne des valeurs erronées (comme 256% pour le SOC), la fonction reset() peut le forcer à redémarrer correctement.
Calibration manuelle :
Après avoir branché une nouvelle batterie, il peut être nécessaire de réinitialiser le capteur pour qu'il commence à mesurer les données de la nouvelle batterie.
Développement et débogage :
Lors du prototypage, la réinitialisation garantit un comportement prévisible après chaque modification.
Fonctionnement

Lorsque la fonction reset() est appelée :

Le MAX17043 effectue une réinitialisation matérielle.
Toutes les données de suivi, y compris l'état de charge (SOC) et la tension de la batterie, sont réinitialisées.
Le capteur revient à ses paramètres d'usine.

## Exemple d'utilisation
```cpp
#include <Wire.h>
#include <Adafruit_MAX17043.h>

Adafruit_MAX17043 batteryMonitor;

void setup() {
  Serial.begin(115200);
  Wire.begin(); // Initialise I2C pour MAX17043

  if (!batteryMonitor.begin()) {
    Serial.println("Erreur : MAX17043 non détecté !");
    while (1); // Bloque le programme si le capteur n'est pas détecté
  }

  Serial.println("Réinitialisation du MAX17043...");
  batteryMonitor.reset();
  Serial.println("Le MAX17043 a été réinitialisé avec succès.");
}

void loop() {
  float voltage = batteryMonitor.getVoltage();
  float soc = batteryMonitor.getSoc();

  Serial.print("Tension de la batterie : ");
  Serial.print(voltage);
  Serial.println(" V");

  Serial.print("Pourcentage de batterie : ");
  Serial.print(soc);
  Serial.println(" %");

  delay(2000);
}
```

## Précautions

Efface toutes les données internes : Après un reset(), le capteur perd son historique de charge et doit recalibrer l'état de la batterie.
Utilisation limitée : N'utilisez pas cette fonction de manière répétée dans un programme normal. Préférez la commande quickStart() pour un recalibrage rapide sans perdre les données.
Temps de récupération : Après un reset(), le capteur peut nécessiter un certain temps pour recalculer correctement le SOC.
## Alternatives

quickStart() :
Réinitialise uniquement l'estimation de l'état de charge (SOC) sans effacer les autres paramètres.
Plus rapide et moins intrusif que reset().
## Résultat attendu

Après un appel à reset() :

Le capteur redémarre comme s'il venait d'être alimenté.
Les lectures de SOC et de tension sont réinitialisées et doivent se stabiliser après quelques cycles.
## Cas d'utilisation recommandé

Lors de la mise en place d'une nouvelle batterie.
Après des erreurs persistantes dans les lectures (ex. : SOC incohérent ou valeur bloquée).

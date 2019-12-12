## Nom : ESP32-Weather (version BlueDot)

## Numéro de version : 0.2

## Auteurs : Thierry Vaira (IR), Jérôme Beaumont (EC)

## Description

La carte ESP32-Weather est une sonde construite autour d'un ESP32 et équipée d'un module **BlueDot** I2C, qui intègre un capteur d'éclairement lumineux **TSL 2591** et un capteur **BME280** (température, humidité et pression atmosphétrique), et d'une Led Bicolore. Les mesures sont affichées périodiquement sur l'écran **OLED** de la carte.

Le programme embarque aussi un **serveur TCP** multi-clients via un réseau **WiFi**. Les clients connectés reçevront périodiquement les mesures de la sonde ainsi que l'état de la Led bicolore. Els peuvent aussi envoyer une requête pour commander la Led.

La sonde communique aussi via le Bluetooth et la liaison série. Le même protocole est utilisé pour les trois modes de communication. L'écran de la sonde affiche l'adresse IP et le numéro de port utilisés pour une communication WiFi et l'adresse MAC de l'interface Bluetooth.

![ESP32_WEATHER](https://github.com/ZaYFix/dev/blob/master/Mini-projet/ESP32-Weather-Bluedot/ESP32_weather_1.png)

## Protocole

```
SONDE;TEMPERATURE;UNITE;RESSENTIE;UNITE;HUMIDITE;UNITE;ECLAIREMENT;UNITE;PRESSION;UNITE;ALTITUDE;UNITE;\n
LED;ETAT LED ROUGE;ETAT LED VERTE;ETAT;COULEUR;\n
```

Exemple :

```
SONDE;20.8;C;20.0;C;41;%;997;lux;1007;hPa;52;m;\n -> Température 20,8 °C, Ressentie 20 °C, Humidité 41 %, un éclairement de 997 lux, une pression atmosphérique de 1007 hPa et d'une altitude évaluée à 52 m
LED;1;0;1;1;\n -> Le Led est allumée en rouge
```

_Remarques :_

- Les valeurs de température sont précisées au dixième de degré.
- Un booléen est égal à 0 pour false et 1 pour true.
- Les codes de couleur pour la Led sont : 
    - Aucune (éteinte) = 0
    - Rouge = 1
    - Verte = 2
    - Orange = 3

Les clients connectés ont la possibilité d'envoyer une requête pour commander la led :

```
SET LED commande\n
```

Le champ commande peut prendre les valeurs suivantes :

```
SET LED ON\n -> allume la Led dans sa couleur courante
SET LED OFF\n -> éteint la Led
SET LED 0\n -> éteint la Led
SET LED 1\n -> allume la Led en rouge
SET LED 2\n -> allume la Led en vert
SET LED 3\ -> allume la Led en orange
SET LED ROUGE\n -> allume la Led en rouge
SET LED VERT\n -> allume la Led en vert
SET LED VERTE\n -> allume la Led en vert
SET LED ORANGE\n -> allume la Led en orange
```

_Remarque : la requête est insensible à la casse._

Test de communication via la liaison série (logiciel cutecom) :

![CUTECOM](https://github.com/ZaYFix/dev/blob/master/Mini-projet/ESP32-Weather-Bluedot/screenshot-cutecom.png)

## PlatformIO

~~~ {.ini}
[env:lolin32]
platform = espressif32
board = lolin32
framework = arduino
lib_deps =
  ESP8266_SSD1306
  Adafruit Unified Sensor
  DHT sensor library
  Adafruit TSL2591 Library
  Adafruit BME280 Library
~~~

## ESP32-Weather

La carte ESP32-Weather est une sonde construite autour d'un ESP32 et équipée d'un module **BlueDot** I2C, qui intègre un capteur d'éclairement lumineux **TSL 2591** et un capteur **BME280** (température, humidité et pression atmosphétrique), et d'une Led Bicolore. Les mesures sont affichées périodiquement sur l'écran **OLED** de la carte.

Le programme embarque aussi un **serveur TCP** multi-clients via un réseau **WiFi**. Les clients connectés reçevront périodiquement les mesures de la sonde ainsi que l'état de la Led bicolore. Els peuvent aussi envoyer une requête pour commander la Led.

La sonde communique aussi via le Bluetooth et la liaison série. Le même protocole est utilisé pour les trois modes de communication. L'écran de la sonde affiche l'adresse IP et le numéro de port utilisés pour une communication WiFi et l'adresse MAC de l'interface Bluetooth.

![ESP32_WEATHER_1](https://github.com/ZaYFix/dev/blob/master/Mini-projet/ESP32-Weather-Bluedot/ESP32_weather.png)

Source : [ESP32-weather.zip](./ESP32-weather.zip)

### Table des matières
- README
- About
- Licence

### A propos
Author *Thierry Vaira (IR) <tvaira@free.fr>*
Author *Jérôme Beaumont (EC) <beaumontlasalle84@gmail.com>*
Version *0.1*
Date *2019*

### Licence GPL

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

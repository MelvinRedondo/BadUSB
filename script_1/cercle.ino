#include "Mouse.h"

const float rayon = 150.0; // le rayon du cercle, en pixels
const float deltaAngle = 0.1 ; // augmentation de la position angulaire à chaque passage dans la boucle
const int delai = 30; // plus c'est petit, pous le pointeur se déplacera rapidement

float angle = 0; // la position angulaire sur le cercle, en radians.

void setup() {
  // initialisation de l'émulation de souris
  Mouse.begin();
}

void loop() {

  if (digitalRead(2)) {  // pour permettre la reprogrammation facile de la carte, le sketch
    // ne s'exécute que si la broche 2 est à 5 V.  Relier la broche 2
    // à GND pour reprogrammer la carte.

    Mouse.move(round(rayon * (cos(angle + deltaAngle) - cos(angle))), round(rayon * (sin(angle + deltaAngle) - sin(angle))), 0);

    angle = angle + deltaAngle;
    if (angle >= (2 * PI)) {
      angle = angle - (2 * PI);
    }
    
    delay(delai);
  }

}

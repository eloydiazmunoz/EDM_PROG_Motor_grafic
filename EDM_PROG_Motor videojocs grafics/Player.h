// Previu a doble inclusió, assegurant que aquest arxiu d'encapçalament només sigui inclòs una vegada.
#ifndef PLAYER_H
#define PLAYER_H

// Inclou la biblioteca gràfica SFML per utilitzar tipus gràfics com sf::RectangleShape.
#include <SFML/Graphics.hpp>
// Inclou la biblioteca estàndard vector per utilitzar contenidors dinàmics.
#include <vector>
// Inclou la definició de la classe Bullet, que representa les bales disparades pel jugador.
#include "Bullet.h"

// Declara la classe Player, que gestiona el personatge del jugador dins del joc.
class Player {
public:
    sf::RectangleShape shape; // Forma gràfica del jugador, utilitzada per a la seva representació en pantalla.
    std::vector<Bullet> bullets; // Contenidor que emmagatzema les bales disparades pel jugador.

    Player(); // Constructor de la classe Player que inicialitza el jugador.
    void shoot(); // Mètode per disparar una bala. Afegeix una nova bala al vector bullets.
    void update(); // Mètode per actualitzar l'estat del jugador. Pot incloure la lògica per moure el jugador o gestionar les bales actives.
};

// Fi de la prevenció de doble inclusió.
#endif

// Previu a doble inclusi�, assegurant que aquest arxiu d'encap�alament nom�s sigui incl�s una vegada.
#ifndef PLAYER_H
#define PLAYER_H

// Inclou la biblioteca gr�fica SFML per utilitzar tipus gr�fics com sf::RectangleShape.
#include <SFML/Graphics.hpp>
// Inclou la biblioteca est�ndard vector per utilitzar contenidors din�mics.
#include <vector>
// Inclou la definici� de la classe Bullet, que representa les bales disparades pel jugador.
#include "Bullet.h"

// Declara la classe Player, que gestiona el personatge del jugador dins del joc.
class Player {
public:
    sf::RectangleShape shape; // Forma gr�fica del jugador, utilitzada per a la seva representaci� en pantalla.
    std::vector<Bullet> bullets; // Contenidor que emmagatzema les bales disparades pel jugador.

    Player(); // Constructor de la classe Player que inicialitza el jugador.
    void shoot(); // M�tode per disparar una bala. Afegeix una nova bala al vector bullets.
    void update(); // M�tode per actualitzar l'estat del jugador. Pot incloure la l�gica per moure el jugador o gestionar les bales actives.
};

// Fi de la prevenci� de doble inclusi�.
#endif

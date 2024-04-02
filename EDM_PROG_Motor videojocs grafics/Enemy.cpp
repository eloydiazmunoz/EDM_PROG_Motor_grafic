// Inclou la definició de la classe Enemy.
#include "Enemy.h"

// Constructor de la classe Enemy. Inicialitza un enemic amb una posició i aparença específiques.
Enemy::Enemy(float x, float y) {
    shape.setPosition(x, y); // Estableix la posició inicial de l'enemic dins de la finestra de joc.
    shape.setSize(sf::Vector2f(20.f, 20.f)); // Assigna les dimensions de la forma de l'enemic.
    shape.setFillColor(sf::Color::Green); // Defineix el color de l'enemic com a verd.
}

// Mètode per actualitzar l'estat de l'enemic.
void Enemy::update() {
    shape.move(-0.5f, 0); // Mou l'enemic cap a l'esquerra a cada actualització.
}

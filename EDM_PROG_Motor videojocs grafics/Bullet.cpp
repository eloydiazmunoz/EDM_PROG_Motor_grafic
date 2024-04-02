// Inclou la definici� de la classe Bullet.
#include "Bullet.h"

// Constructor de Bullet. Inicialitza una bala amb una posici�, velocitat i aparen�a espec�fiques.
Bullet::Bullet(float x, float y) : velocity(sf::Vector2f(0.5f, 0)) {
    shape.setPosition(x, y); // Estableix la posici� inicial de la bala dins de la finestra de joc.
    shape.setRadius(5.f); // Assigna el radi de la forma circular de la bala a 5 p�xels.
    shape.setFillColor(sf::Color::Red); // Defineix el color de la bala com a vermell.
}

// M�tode per actualitzar l'estat de la bala.
void Bullet::update() {
    shape.move(velocity); // Mou la bala en cada actualitzaci� basant-se en la seva velocitat.
}

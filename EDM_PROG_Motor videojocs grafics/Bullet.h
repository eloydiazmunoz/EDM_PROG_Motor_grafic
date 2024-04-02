// Prev� la doble inclusi� d'aquest arxiu d'encap�alament,
// assegurant-se que el codi dins d'aquest arxiu nom�s sigui incl�s una vegada.
#ifndef BULLET_H
#define BULLET_H

// Inclou el fitxer d'encap�alament de SFML necessari per utilitzar tipus gr�fics,
// com ara sf::CircleShape, que s'utilitzar� per dibuixar les bales.
#include <SFML/Graphics.hpp>

// Declara la classe Bullet, que �s responsable de representar les bales dins del joc.
class Bullet {
public:
    sf::CircleShape shape; // Membre p�blic de tipus sf::CircleShape per dibuixar la forma de la bala.
    sf::Vector2f velocity; // Vector de velocitat per controlar el moviment de la bala.

    // Constructor que pren dues coordenades (x, y) com a par�metres.
    // Aquest constructor inicialitza la posici� de la bala dins del m�n del joc.
    Bullet(float x, float y);

    // M�tode update que s'ha de cridar en cada fotograma del bucle del joc.
    // Aquest m�tode s'encarregar� d'actualitzar l'estat de la bala, com ara moure-la.
    void update();
};

// Finalitza la condici� de prevenci� de la doble inclusi�.
#endif

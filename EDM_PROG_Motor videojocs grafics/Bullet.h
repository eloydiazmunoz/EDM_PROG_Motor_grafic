// Prevé la doble inclusió d'aquest arxiu d'encapçalament,
// assegurant-se que el codi dins d'aquest arxiu només sigui inclòs una vegada.
#ifndef BULLET_H
#define BULLET_H

// Inclou el fitxer d'encapçalament de SFML necessari per utilitzar tipus gràfics,
// com ara sf::CircleShape, que s'utilitzarà per dibuixar les bales.
#include <SFML/Graphics.hpp>

// Declara la classe Bullet, que és responsable de representar les bales dins del joc.
class Bullet {
public:
    sf::CircleShape shape; // Membre públic de tipus sf::CircleShape per dibuixar la forma de la bala.
    sf::Vector2f velocity; // Vector de velocitat per controlar el moviment de la bala.

    // Constructor que pren dues coordenades (x, y) com a paràmetres.
    // Aquest constructor inicialitza la posició de la bala dins del món del joc.
    Bullet(float x, float y);

    // Mètode update que s'ha de cridar en cada fotograma del bucle del joc.
    // Aquest mètode s'encarregarà d'actualitzar l'estat de la bala, com ara moure-la.
    void update();
};

// Finalitza la condició de prevenció de la doble inclusió.
#endif

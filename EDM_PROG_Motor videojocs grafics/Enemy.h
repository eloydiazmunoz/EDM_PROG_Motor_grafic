// Prevé la doble inclusió d'aquest arxiu d'encapçalament,
// assegurant-se que el codi dins d'aquest arxiu només sigui inclòs una vegada.
#ifndef ENEMY_H
#define ENEMY_H

// Inclou el fitxer d'encapçalament de SFML necessari per utilitzar tipus gràfics,
// com ara sf::RectangleShape, que s'utilitzarà per dibuixar els enemics.
#include <SFML/Graphics.hpp>

// Declara la classe Enemy, que és responsable de representar els enemics dins del joc.
class Enemy {
public:
    sf::RectangleShape shape; // Membre públic de tipus sf::RectangleShape per dibuixar la forma de l'enemic.

    // Constructor que pren dues coordenades (x, y) com a paràmetres.
    // Aquest constructor inicialitza la posició de l'enemic dins del món del joc.
    Enemy(float x, float y);

    // Mètode update que s'ha de cridar en cada fotograma del bucle del joc.
    // Aquest mètode s'encarregarà d'actualitzar l'estat de l'enemic, com ara moure's.
    void update();
};

// Finalitza la condició de prevenció de la doble inclusió.
#endif

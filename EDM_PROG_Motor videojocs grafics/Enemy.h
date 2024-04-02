// Prev� la doble inclusi� d'aquest arxiu d'encap�alament,
// assegurant-se que el codi dins d'aquest arxiu nom�s sigui incl�s una vegada.
#ifndef ENEMY_H
#define ENEMY_H

// Inclou el fitxer d'encap�alament de SFML necessari per utilitzar tipus gr�fics,
// com ara sf::RectangleShape, que s'utilitzar� per dibuixar els enemics.
#include <SFML/Graphics.hpp>

// Declara la classe Enemy, que �s responsable de representar els enemics dins del joc.
class Enemy {
public:
    sf::RectangleShape shape; // Membre p�blic de tipus sf::RectangleShape per dibuixar la forma de l'enemic.

    // Constructor que pren dues coordenades (x, y) com a par�metres.
    // Aquest constructor inicialitza la posici� de l'enemic dins del m�n del joc.
    Enemy(float x, float y);

    // M�tode update que s'ha de cridar en cada fotograma del bucle del joc.
    // Aquest m�tode s'encarregar� d'actualitzar l'estat de l'enemic, com ara moure's.
    void update();
};

// Finalitza la condici� de prevenci� de la doble inclusi�.
#endif

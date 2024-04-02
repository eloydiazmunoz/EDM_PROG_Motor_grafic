// Inclou la biblioteca gràfica SFML per al desenvolupament de videojocs.
#include <SFML/Graphics.hpp>

// Inclou la biblioteca estàndard d'entrada/sortida per imprimir missatges.
#include <iostream>

// Inclou la definició de la classe Game, que gestiona la lògica principal del joc.
#include "Game.h"

// Utilitza l'espai de noms de SFML per facilitar l'ús de les seves funcionalitats.
using namespace sf;

// Funció principal que inicia l'execució del programa.
int main()
{
    // Crea una instància de Game, que encapsula tota la lògica del joc.
    Game game;

    // Inicia el bucle del joc cridant al mètode run de l'objecte game.
    game.run();

    // Finalitza correctament el programa.
    return 0;
}

// Inclou la biblioteca gr�fica SFML per al desenvolupament de videojocs.
#include <SFML/Graphics.hpp>

// Inclou la biblioteca est�ndard d'entrada/sortida per imprimir missatges.
#include <iostream>

// Inclou la definici� de la classe Game, que gestiona la l�gica principal del joc.
#include "Game.h"

// Utilitza l'espai de noms de SFML per facilitar l'�s de les seves funcionalitats.
using namespace sf;

// Funci� principal que inicia l'execuci� del programa.
int main()
{
    // Crea una inst�ncia de Game, que encapsula tota la l�gica del joc.
    Game game;

    // Inicia el bucle del joc cridant al m�tode run de l'objecte game.
    game.run();

    // Finalitza correctament el programa.
    return 0;
}

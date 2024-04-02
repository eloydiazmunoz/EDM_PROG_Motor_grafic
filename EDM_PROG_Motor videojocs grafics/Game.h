// Inclou la biblioteca SFML per a funcionalitats gr�fiques i de finestra.
#include <SFML/Graphics.hpp>
// Inclou la definici� de la classe Player, que gestiona el personatge del jugador.
#include "Player.h"
// Inclou la definici� de la classe Enemy, que gestiona els enemics del joc.
#include "Enemy.h"
// Inclou la biblioteca vector per a utilitzar contenidors de vectors din�mics.
#include <vector>

// Declara la classe Game, que cont� tota la l�gica principal del joc.
class Game {
public:
    Game(); // Constructor de Game que inicialitza l'estat inicial del joc.
    void run(); // Funci� que inicia el bucle principal del joc.

private:
    sf::RenderWindow mWindow; // Finestra on es renderitza el joc.
    Player mPlayer; // Objecte jugador.
    std::vector<Enemy> mEnemies; // Contenidor din�mic per a objectes Enemy.
    std::vector<Bullet> mBullets; // Contenidor per a les bales disparades pel jugador.
    bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight; // Estats de moviment del jugador.
    int mScore; // Puntuaci� actual del jugador.
    bool mGameOver; // Indicador si el joc ha acabat.
    int mTime=0; // Comptador de temps per a la generaci� d'enemics.

    void processEvents(); // Funci� per processar esdeveniments d'entrada (teclat, etc.).
    void update(sf::Time deltaTime); // Funci� per actualitzar l'estat del joc.
    void render(); // Funci� per a dibuixar els elements del joc a la finestra.
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed); // Funci� per gestionar l'entrada del jugador.
    void updateBullets(sf::Time deltaTime); // Actualitza l'estat de les bales disparades.
    void updateEnemies(sf::Time deltaTime); // Actualitza l'estat dels enemics.
    void checkCollisions(); // Comprova col�lisions entre bales, jugador i enemics.
};

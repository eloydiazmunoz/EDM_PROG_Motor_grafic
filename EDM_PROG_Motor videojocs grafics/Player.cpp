// Inclou la definició de la classe Player.
#include "Player.h"

// Constructor de la classe Player. Configura la forma i la posició inicial del jugador.
Player::Player() {
    shape.setSize(sf::Vector2f(50.f, 50.f)); // Estableix la mida de la forma del jugador a 50x50 píxels.
    shape.setPosition(400, 550); // Posiciona la forma del jugador a les coordenades (400, 550) dins de la finestra de joc.
    shape.setFillColor(sf::Color::Blue); // Assigna el color blau a la forma del jugador.
}

// Mètode perquè el jugador dispari una bala.
void Player::shoot() {
    // Crea una nova bala al centre superior de la forma del jugador i l'afegeix al vector de bales.
    bullets.push_back(Bullet(shape.getPosition().x + shape.getSize().x / 2 - 2.5f, shape.getPosition().y));
}

// Mètode per actualitzar l'estat del jugador, incloent la posició de les seves bales.
void Player::update() {
    for (int i = 0; i < bullets.size(); ++i) { // Itera sobre totes les bales disparades pel jugador.
        bullets[i].update(); // Actualitza la posició de cada bala basant-se en la seva velocitat.
        // Comprova si alguna bala ha sortit de la finestra de joc (assumint una amplada de finestra de 800 píxels).
        if (bullets[i].shape.getPosition().x > 800) {
            // Si la bala ha sortit de la pantalla, l'elimina del vector de bales.
            bullets.erase(bullets.begin() + i);
            --i; // Ajusta l'índex després d'eliminar un element del vector per evitar saltar-se la comprovació d'una bala.
        }
    }
}

// Inclou les capçaleres necessàries per utilitzar SFML, gestió de temps i generació de nombres aleatoris.
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include <cstdlib> // Per a funcions com rand() i srand()
#include <ctime> // Per a funcions relacionades amb el temps com time()
#include <SFML/Graphics.hpp> // Per a tot el relacionat amb gràfics de SFML

// Constructor de la classe Game. Inicialitza la finestra del joc, el jugador i variables de control.
Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Game"), mPlayer(), mIsMovingUp(false), mIsMovingDown(false), mIsMovingLeft(false), mIsMovingRight(false), mScore(0), mGameOver(false) {
    srand(time(NULL)); // Inicialitza el generador de nombres aleatoris utilitzant l'hora actual com a llavor.
    mPlayer.shape.setPosition(320.f - mPlayer.shape.getSize().x / 2, 480.f - mPlayer.shape.getSize().y - 10.f); // Col·loca el jugador a la part inferior centrada de la finestra.
}

// Funció run que conté el bucle principal del joc. Manté el joc en execució fins que es tanca la finestra o es produeix un game over.
void Game::run() {
    sf::Clock clock; // Relotge per controlar el temps entre frames.
    while (mWindow.isOpen() && !mGameOver) { // Bucle principal que s'executa mentre la finestra estigui oberta i no s'hagi produït un game over.
        sf::Time deltaTime = clock.restart(); // Restableix el rellotge i guarda el temps transcorregut des de l'últim restabliment.
        processEvents(); // Processa els esdeveniments d'entrada.
        update(deltaTime); // Actualitza l'estat del joc.
        checkCollisions(); // Comprova les col·lisions.
        render(); // Renderitza els gràfics del joc.
    }
}

// Gestiona els esdeveniments d'entrada, com ara tecles premudes o la finestra tancada.
void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) { // Recorre tots els esdeveniments pendents.
        switch (event.type) {
        case sf::Event::KeyPressed: // Si s'ha premut una tecla, crida a handlePlayerInput.
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased: // Si s'ha alliberat una tecla, també crida a handlePlayerInput.
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed: // Si l'esdeveniment és tancar la finestra, es tanca.
            mWindow.close();
            break;
        }
    }
}

// Actualitza l'estat del joc, incloent el moviment del jugador, les bales i els enemics.
void Game::update(sf::Time deltaTime) {
    sf::Vector2f movement(0.f, 0.f); // Vector per controlar el moviment del jugador.
    // Estableix la direcció del moviment basant-se en quines tecles estan premudes.
    if (mIsMovingUp) movement.y -= 1.f;
    if (mIsMovingDown) movement.y += 1.f;
    if (mIsMovingLeft) movement.x -= 1.f;
    if (mIsMovingRight) movement.x += 1.f;
    mPlayer.shape.move(movement * 100.f * deltaTime.asSeconds()); // Mou el jugador.

    // Actualitza les bales del jugador.
    for (auto& bullet : mPlayer.bullets) {
        bullet.update();
    }

    // Elimina les bales que surten de la pantalla.
    mPlayer.bullets.erase(std::remove_if(mPlayer.bullets.begin(), mPlayer.bullets.end(), [this](const Bullet& b) {
        return b.shape.getPosition().y < 0;
        }), mPlayer.bullets.end());

    // Genera enemics de forma aleatòria.
    // Generar enemigos
    if (mTime > 9500) {
        mEnemies.push_back(Enemy(mWindow.getSize().x, rand() % mWindow.getSize().y));
        mTime = 0;
    }
    else {
        mTime++;
    }

    // Actualitza els enemics.
    for (auto& enemy : mEnemies) {
        enemy.update();
    }

    // Elimina els enemics que surten de la pantalla.
    mEnemies.erase(std::remove_if(mEnemies.begin(), mEnemies.end(), [this](const Enemy& e) {
        return e.shape.getPosition().y > mWindow.getSize().y;
        }), mEnemies.end());
}

// Renderitza tots els elements del joc a la finestra.
void Game::render() {
    mWindow.clear(); // Neteja la finestra.
    mWindow.draw(mPlayer.shape); // Dibuixa el jugador.
    for (auto& bullet : mPlayer.bullets) { // Dibuixa cada bala.
        mWindow.draw(bullet.shape);
    }
    for (auto& enemy : mEnemies) { // Dibuixa cada enemic.
        mWindow.draw(enemy.shape);
    }
    mWindow.display(); // Mostra el contingut renderitzat a la pantalla.
}

// Gestiona l'entrada del jugador, ajustant les variables de moviment.
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W) mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S) mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::Space && isPressed) mPlayer.shoot();
}

// Comprova les col·lisions entre bales i enemics, i si un enemic arriba a la part inferior de la pantalla.
void Game::checkCollisions() {
    // Implementació de la detecció de col·lisions.
    for (auto bulletIt = mPlayer.bullets.begin(); bulletIt != mPlayer.bullets.end();) {
        bool bulletRemoved = false;
        for (auto enemyIt = mEnemies.begin(); enemyIt != mEnemies.end() && !bulletRemoved;) {
            if (bulletIt->shape.getGlobalBounds().intersects(enemyIt->shape.getGlobalBounds())) {
                bulletIt = mPlayer.bullets.erase(bulletIt);
                enemyIt = mEnemies.erase(enemyIt);
                mScore += 1; // Incrementa la puntuació.
                bulletRemoved = true;
            }
            else {
                ++enemyIt;
            }
        }
        if (!bulletRemoved) ++bulletIt;
    }

    // Verifica si algun enemic ha arribat al final de la pantalla.
    for (auto& enemy : mEnemies) {
        if (enemy.shape.getPosition().y + enemy.shape.getSize().y >= mWindow.getSize().y) {
            mGameOver = true; // Estableix el joc com a acabat.
            break;
        }
    }
}

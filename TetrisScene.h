#ifndef TETRISSCENE_H
#define TETRISSCENE_H

#include "MenuRejouer.h"

class TetrisScene{

private:
        sf::RenderWindow* fenetreDuJeu;
        sf::Clock timerDescente; //Gestion du temps.
        Grille grille;
        Piece piece;
        Joueur joueur;
        MenuRejouer menuRejouer;
public:
        TetrisScene(sf::RenderWindow& _window);
        virtual ~TetrisScene();
        void processEvents(sf::Event evt);
        void update();
        void render();
        void reset();
};

#endif // TETRISSCENE_H

#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <iostream>

#include "Cube.h"
#include "PauseDuJeu.h"
#include "Grille.h"
#include "Piece.h"
#include "Joueur.h"
#include "TetrisScene.h"
#include "ReadmeScene.h"
#include "ParticuleTetrominos.h"
#include "ExplosionParticule.h"
#include "MusiqueMenu.h"

class Application
{
private:
	sf::RenderWindow _window;
    TetrisScene  sceneTetris;
    PauseDuJeu   scenePauseDuJeu;
    ReadmeScene readme;
    ParticuleTetrominos particuleTetromino;
    MusiqueMenu musique;

public:
    Application();
    void run();

protected:
	void processEvents();
	void update();
	void render();


};
#endif

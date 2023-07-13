#include "ReadmeScene.h"

ReadmeScene::ReadmeScene()
{
    compteur =0;
    ReadmeSceneEvt="None";

    if( !font.loadFromFile("ressources/Font/Kenzo_Regular.otf"))
        exit(EXIT_FAILURE);

    std::string n="\t\t\tBienvenue\n Pour joueur a ce jeu:\n\tPivoter la piece: touche du haut\n\tDeplacer la piece: flèche <- ->\n\tAugmenter vitesse: Touche du bas\n\tChanger Musique: touche 1 à 0\n\tReduire son: touche -\n\tAugmenter son: touche +\n\tPause Musique: touche *";
    readme.setFont(font);
    readme.setStyle(65);
    readme.setString(n);
    readme.setColor(sf::Color::Black);
    readme.setPosition(sf::Vector2f(5.0f,50.0f));
    readme.setCharacterSize(40);

    quitter.setFont(font);
    quitter.setString("Appuyer sur n'importe quel touche pour commencer");
    quitter.setColor(sf::Color::Transparent);
    quitter.setPosition(sf::Vector2f(5.0f,500.0f));
    quitter.setCharacterSize(30);
}

ReadmeScene::~ReadmeScene(){}

void ReadmeScene::ReadmeSceneEvenement(sf::Event evt){
    if(evt.type==sf::Event::KeyPressed)
        ReadmeSceneEvt="Quitter";
}

void ReadmeScene::ReadmeSceneUpdate(){
    if(compteur%20==0)
        quitter.setColor(sf::Color::Transparent);
    else
         quitter.setColor(sf::Color::Black);
    compteur++;
}

void ReadmeScene::ReadmeSceneAfficher(sf::RenderWindow& _window){
    _window.draw(readme);
    _window.draw(quitter);
}
std::string  ReadmeScene::getReadmeSceneEvenement(){
    return ReadmeSceneEvt;
}

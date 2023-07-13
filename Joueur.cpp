#include "Application.h"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

Joueur::Joueur(std::string n)
{
    nom=n;
    score=0.0;
    level=0;
    nbLigne=0;

    font.loadFromFile("ressources/Font/Kenzo_Regular.otf");
    for(int i=0; i<3; i++){
        stats[i].setFont(font);
        stats[i].setCharacterSize(50);
        stats[i].setPosition(sf::Vector2f(320,350+70*i));
        stats[i].setColor(sf::Color::Black);
    }
}

void Joueur::joueurEvent(sf::Event evt){
    if(evt.type==sf::Event::KeyPressed){
        switch(evt.key.code){
            case sf::Keyboard::Left:
                event="Left";
            break;
            case sf::Keyboard::Right:
                event="Right";
            break;
            case sf::Keyboard::Up:
                event="Up";
            break;
            case sf::Keyboard::Down:
                event="Down";
            break;
            default:
            break;
        }
    }
}

void Joueur::joueurUpdate(Piece& piece, Grille& g){
    if(event=="Left")
        piece.bougerPieceGauche(g);
    if(event=="Right")
        piece.bougerPieceDroite(g);
    if(event=="Up")
        piece.rotationPiece(g);
    if(event=="Down")
        piece.faireDessendrePiece(g);
    event="none";
}

void Joueur::afficherStatsJoueur(sf::RenderWindow& window){
    for(int i=0; i<3; i++){
        if(i==0)
            stats[i].setString("Score : " + intToString(score) );
        else if(i==1)
            stats[i].setString("Level : " + intToString(level));
        else
            stats[i].setString("Ligne : " + intToString(nbLigne));
        window.draw(stats[i]);
    }
}

void Joueur::inccrementerScore(Grille& g){
    switch(g.getNombreLignePleine()){
        case 1:
            score+=40*(level+1);
        break;
        case 2:
            score+=100*(level+1);
        break;
        case 3:
            score+=300*(level+1);
        break;
        case 4:
            score+=1200*(level+1);
        break;
    }
    nbLigne+=g.getNombreLignePleine();
    g.setNombreLignePleine(0);
    inccrementerLevel();
}
void Joueur::inccrementerLevel(){
    level=(int)sqrt(score)/10;
}

std::string Joueur::intToString(int i) {
     std::ostringstream oss;
     oss << i;
     return oss.str();
}

/*********************SET/GET************************/

double Joueur::getScore(){
    return score;
}

void Joueur::setScore(double d){
    score=d;
}

int Joueur::getLevel(){
    return level;
}

void Joueur::setLevel(int i){
    level=i;
}

int Joueur::getNbLigne(){
    return nbLigne;
}

void Joueur::setNbLigne(int i){
    nbLigne=i;
}

std::string Joueur::getJoueurEvenement(){
    return event;
}

void Joueur::setJoueurEvenement(std::string n){
    event=n;
}

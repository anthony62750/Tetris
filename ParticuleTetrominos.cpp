#include "Application.h"

ParticuleTetrominos::ParticuleTetrominos()
{
    nombreParticule=100;
    for(int i=0; i<nombreParticule; i++){
        idParticules[i]=rand()%7;
        float vitesseParticulesX=vitesseParticule[rand()%2];
        float vitesseParticulesY=vitesseParticule[rand()%2];
        int positionX=rand()%(600-40);
        int positionY=rand()%(600-40);
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                vitesseParticules[i][j][k]=sf::Vector2f(vitesseParticulesX,vitesseParticulesY);
                tableauParticules[i][j][k].setPosition(sf::Vector2f(positionX+10*j,positionY+10*k));
                tableauParticules[i][j][k].setId(listePiece[idParticules[i]][1][j][k]);
                if(tableauParticules[i][j][k].getId()==1)
                    tableauParticules[i][j][k].setFillColor(couleurPiece[idParticules[i]]);
                else
                    tableauParticules[i][j][k].setFillColor(sf::Color::Transparent);
                tableauParticules[i][j][k].setOutlineThickness(0);
                tableauParticules[i][j][k].setSize(sf::Vector2f(10,10));
            }
        }
    }
}

void ParticuleTetrominos::afficherParticules(sf::RenderWindow& _window){
    for(int i=0; i<nombreParticule; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                _window.draw(tableauParticules[i][j][k]);
            }
        }
    }
}

void ParticuleTetrominos::particulesUpdate(){
    for(int i=0; i<nombreParticule; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                tableauParticules[i][j][k].setPosition(sf::Vector2f(tableauParticules[i][j][k].getPosition().x+vitesseParticules[i][j][k].x,tableauParticules[i][j][k].getPosition().y+vitesseParticules[i][j][k].y));
            }
        }
    }
    collisionParticules();
}

void ParticuleTetrominos::collisionParticules(){
    for(int i=0; i<nombreParticule; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                if(tableauParticules[i][j][k].getPosition().x < 0 || tableauParticules[i][j][k].getPosition().x > 600-10 && tableauParticules[i][j][k].getId()==1){
                    vitesseParticules[i][j][k].x=(vitesseParticules[i][j][k].x*-1);
                }
                if(tableauParticules[i][j][k].getPosition().y < 0 || tableauParticules[i][j][k].getPosition().y > 600-10 && tableauParticules[i][j][k].getId()==1){
                    vitesseParticules[i][j][k].y=(vitesseParticules[i][j][k].y*-1);
                }
            }
        }
    }
}

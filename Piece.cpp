#include "Application.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Piece::Piece(Grille& g)
{
    srand(time(NULL));
    idPiece=rand() % 7;
    rotation=0;
    positionX=3;
    positionY=0;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
           pieceActive[i][j]=listePiece[idPiece][rotation][j][i];
        }
    }
    position = g.grille[3][0].getPosition();
    couleur = couleurPiece[idPiece];
    initialiserNextPiece(rand()%7, rand()%7, rand()%7);
}

void Piece::initialiserNextPiece(int idPieceOne, int idPieceTwo, int idPieceThree){
    idNextPiece[0]=idPieceOne;
    idNextPiece[1]=idPieceTwo;
    idNextPiece[2]=idPieceThree;
    for(int k=0; k<3; k++){
        contourNextPiece[k].setSize(sf::Vector2f(21*4, 21*4));
        contourNextPiece[k].setPosition(sf::Vector2f(325,30+(k*100)));
        contourNextPiece[k].setOutlineThickness(7);
        contourNextPiece[k].setOutlineColor(sf::Color(255,204,0));
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                nextPiece[k][i][j].setId(listePiece[idNextPiece[k]][0][j][i]);
                if(nextPiece[k][i][j].getId()==1)
                    nextPiece[k][i][j].setFillColor(couleurPiece[idNextPiece[k]]);
                else
                    nextPiece[k][i][j].setFillColor(sf::Color(255,240,165));
                nextPiece[k][i][j].setSize(sf::Vector2f(21,21));
                nextPiece[k][i][j].setPosition(sf::Vector2f(325+21*i,30+(k*100)+21*j));
            }
        }
    }
}

void Piece::nouvellePiece(Grille& g){
    //initialisation piece principal.
    idPiece=idNextPiece[0];
    rotation=0;
    positionX=3;
    positionY=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
           pieceActive[i][j]=listePiece[idPiece][0][j][i];
        }
    }
    position = g.grille[3][0].getPosition();
    couleur = couleurPiece[idPiece];

    //initialisation nextPiece
    initialiserNextPiece(idNextPiece[1], idNextPiece[2], rand()%7);
}

void Piece::affichePiece(sf::RenderWindow& _window){
    sf::RectangleShape r(sf::Vector2f(25.0,25.0));
    for(int i=0; i<4; i++){
        for(int j=0;j<4;j++){
                r.setPosition(sf::Vector2f(position.x+(25.0*i), position.y+(25.0*j)));
                if(pieceActive[i][j]==1){
                    r.setFillColor(couleur);
                    r.setOutlineThickness(1);
                    r.setOutlineColor(sf::Color::Black);
                }
                else{
                    r.setFillColor(sf::Color::Transparent);
                    r.setOutlineColor(sf::Color::Transparent);
                }
                _window.draw(r);
        }
    }
}

void Piece::afficheNextPiece(sf::RenderWindow& _window){
    for(int k=0; k<3; k++){
        _window.draw(contourNextPiece[k]);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                _window.draw(nextPiece[k][i][j]);
            }
        }
    }
}

void Piece::faireDessendrePiece(Grille& g){
    if(conditionFaireDessendrePiece(g)){
        positionY++;
        position.y=position.y+25;
    }
    else{
        fixerPieceDansLaGrille(g);
        if(g.PartieEstTerminer()== false){
            nouvellePiece(g);
            g.verifieSiLignePleine();
        }
    }
}

void Piece::bougerPieceDroite(Grille& g){
    if(conditionBougerPieceDroite(g)){
        positionX++;
        position.x=position.x+25;
    }
}

void Piece::bougerPieceGauche(Grille& g){
    if(conditionBougerPieceGauche(g)){
        positionX--;
        position.x=position.x-25;
    }
}

bool Piece::conditionFaireDessendrePiece(Grille& g){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(pieceActive[i][j]==1)
                if(positionY+j>=21 || g.grille[positionX+i][positionY+j+1].getId()==1)
                    return false;
        }
    }
    return true;
}

bool Piece::conditionBougerPieceDroite(Grille& g){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(pieceActive[i][j]==1)
                if(positionX+i>8 || g.grille[positionX+i+1][positionY+j].getId()==1)
                    return false;
        }
    }
    return true;
}

bool Piece::conditionBougerPieceGauche(Grille& g){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(pieceActive[i][j]==1)
                if(positionX+i<1 || g.grille[positionX+i-1][positionY+j].getId()==1)
                    return false;
        }
    }
    return true;
}

void Piece::fixerPieceDansLaGrille(Grille& g){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(pieceActive[i][j]==1){
                g.grille[positionX+i][positionY+j].setId(1);
                g.grille[positionX+i][positionY+j].setFillColor(couleur);
            }
        }
    }
}

void Piece::rotationPiece(Grille& g){
    if(conditionRotationPiece(g)){
        rotation++;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
               pieceActive[i][j]=listePiece[idPiece][rotation%4][j][i];
            }
        }
    }
}

bool Piece::conditionRotationPiece(Grille& g){
    int rotationTemporaire = rotation+1;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(listePiece[idPiece][rotationTemporaire%4][j][i]==1){
                if(g.grille[positionX+i][positionY+j].getId()==1 || positionX+i<0 || positionX+i>9 || positionY+j>=22)
                    return false;
            }
        }
    }
    return true;
}

/*********************SET/GET************************/

int Piece::getRotation(){
    return rotation;
}

void Piece::setRotation(int i){
    rotation=i;
}

int Piece::getPositionX(){
    return positionX;
}

void Piece::setPositionX(int i){
    positionX=i;
}

int Piece::getPositionY(){
    return positionY;
}

void Piece::setPositionY(int i){
    positionY=i;
}

sf::Vector2f Piece::getPosition(){
    return position;
}

#include "Application.h"

Grille::Grille(){
    for(int i=0; i<11; i++){
        for(int j=0; j<22;j++){
            grille[i][j].setPosition(sf::Vector2f((25.0f+(25.0f*i)),(25.0f+(25.0f*j))));
        }
    }

    contour.setSize(sf::Vector2f(grille[0][0].getPosition().x + grille[8][0].getPosition().x, grille[10][21].getPosition().y));
    contour.setPosition(sf::Vector2f(25.0f, 25.0f));
    contour.setOutlineThickness(10);
    contour.setOutlineColor(sf::Color(130,130,130));
}

void Grille::afficherGrille(sf::RenderWindow & fenetre){
    fenetre.draw(contour);
    for(int i=0; i<10; i++){
        for(int j=0; j<22;j++){
            fenetre.draw(grille[i][j]);
        }
    }
    for(int i=0; i<explosion.size(); i++){
        explosion[i].render(fenetre);
    }
}

void Grille::explosionUpdate(){
    for(int i=0; i<explosion.size(); i++){
        explosion[i].update();
    }
}

void Grille::verifieSiLignePleine(){
    bool lignePleine = true;
    for(int i=0; i<22; i++){
        for(int j=0; j<10;j++){
            if(grille[j][i].getId()==0)
                lignePleine=false;
        }
        if(lignePleine==true){
            supprimeLaLignePleine(i);
            executerExplosion(i);
            nombreLignePleine++;
        }
        lignePleine=true;
    }
}

void Grille::executerExplosion(int l){
    explosion.clear();
    for(int i=0; i<11; i++)
        explosion.push_back(ExplosionParticule(grille[i][l].getPosition()));
}

void Grille::supprimeLaLignePleine(int l){
    for(int i=0; i<10; i++){
        grille[i][l].setId(0);
        grille[i][l].setFillColor(sf::Color::Black);
    }
    for(int i=0; i<l-1; i++){
        for(int j=0; j<10; j++){
            grille[j][l-i].setId(grille[j][l-i-1].getId());
            grille[j][l-i].setFillColor(grille[j][l-i-1].getFillColor());
        }
    }
}
 bool Grille::PartieEstTerminer(){
    int i=0;
    while(i<10){
        if(grille[i][1].getId() == 1){
            return true;
        }
        i++;
    }
    return false;
 }

 void Grille::recommencerPartie(){
    explosion.clear();
    for(int i=0; i<11; i++){
        for(int j=0; j<22;j++){
            if(grille[i][j].getId()==1)
                explosion.push_back(ExplosionParticule(grille[i][j].getPosition()));
                grille[i][j].setId(0);
                grille[i][j].setFillColor(sf::Color(227,227,227));
        }
    }
 }


/*********************SET/GET************************/
int Grille::getNombreLignePleine(){
    return nombreLignePleine;
}

void Grille::setNombreLignePleine(int n){
    nombreLignePleine=n;
}

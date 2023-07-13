#include "Application.h"

ExplosionParticule::ExplosionParticule(sf::Vector2f postionDepart)
{
     nombreParticule=10;
    for(int i=0; i<nombreParticule; i++){
        particuleExplosion[i].setPosition(postionDepart);
        particuleExplosion[i].setId(rand()%7);
        vitesseParticule[i].x=(((rand() % 30)*0.05)+0.1)*vitesse[rand()%2];
        vitesseParticule[i].y=(((rand() % 30)*0.05)+0.1)*vitesse[rand()%2];
        particuleExplosion[i].setSize(sf::Vector2f(3,3));
        particuleExplosion[i].setFillColor(couleurPiece[particuleExplosion[i].getId()]);
        particuleExplosion[i].setOutlineThickness(0);
    }
}

void ExplosionParticule::render(sf::RenderWindow& _window){
    if(particuleExplosion[0].getSize().x>0) {
        for(int i=0; i<nombreParticule; i++){
            _window.draw(particuleExplosion[i]);
        }
    }
}

void ExplosionParticule::update(){
    if(particuleExplosion[0].getSize().x>0) {
        for(int i=0; i<nombreParticule; i++){
            particuleExplosion[i].move(vitesseParticule[i].x,vitesseParticule[i].y);
            particuleExplosion[i].setSize(sf::Vector2f(particuleExplosion[i].getSize().x-0.001,particuleExplosion[i].getSize().y-0.001));
        }
    }
}


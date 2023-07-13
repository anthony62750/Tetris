#include "Application.h"

Cube::Cube()
{
    id=0;
    this->setSize(sf::Vector2f(25.0f,25.0f));
    this->setFillColor(sf::Color(227,227,227));
    this->setOutlineThickness(1);
    this->setOutlineColor(sf::Color::Black);
}


/*********************SET/GET************************/

sf::Vector2f Cube::getPositionCube(){
    return positionCube;
}

void Cube::setPositionCube(sf::Vector2f v){
    positionCube=v;
}

int Cube::getId(){
    return id;
}

void Cube::setId(int i){
    id=i;
}

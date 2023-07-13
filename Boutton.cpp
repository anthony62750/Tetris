#include <iostream>
#include "Boutton.h"

Boutton::Boutton(string titre, const sf::Vector2f position){
    if (!font.loadFromFile("ressources/Font/Kenzo_Regular.otf"))
      exit(EXIT_FAILURE);

    text.setString(titre);
    text.setFont(font);
    text.setPosition(position);
    text.setColor(sf::Color::Black);
    text.setCharacterSize(80);
}

void Boutton::processEvents(sf::RenderWindow& window, sf::Event evt ){
     sf::Vector2f position(sf::Mouse::getPosition(window));
    if(contains( position) ){
        text.setColor(sf::Color(255, 204, 0));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            evenementBoutton="Click";
    }
     else
            text.setColor(sf::Color::Black);
}

bool Boutton::contains(sf::Vector2f positionSouris){
    sf::FloatRect r=text.getGlobalBounds();
    return r.contains(positionSouris);
}

void Boutton::render(sf::RenderWindow& window){
    window.draw(text);
}

string Boutton::getEvenementBoutton(){
    return evenementBoutton;
}
void Boutton::setEvenementBoutton(std::string n){
    evenementBoutton=n;
}

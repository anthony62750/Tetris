#include "Application.h"
#include "MenuRejouer.h"

 MenuRejouer::MenuRejouer():
oui("oui", sf::Vector2f(200,300)),
non("non", sf::Vector2f(300,300))
{

    if (!font.loadFromFile("ressources/Font/Kenzo_Regular.otf"))
        exit(EXIT_FAILURE);

    text.setString("Voulez vous rejouer ?");
    text.setFont(font);
    text.setPosition(sf::Vector2f(10,200));
    text.setColor(sf::Color::Black);
    text.setCharacterSize(70);


    rectangle.setFillColor(sf::Color(220,220,220,100));
    rectangle.setSize(sf::Vector2f(600,200));
    rectangle.setPosition(sf::Vector2f(0,200));

    rejouer="None";
 }

void MenuRejouer::processEvents(sf::RenderWindow& _window, sf::Event evt ){
    oui.processEvents(_window, evt);
    non.processEvents(_window, evt);
}

void MenuRejouer::update(){
   if(oui.getEvenementBoutton()== "Click")
        rejouer="rejouer";
   else if(non.getEvenementBoutton()== "Click")
         rejouer="quitter";
   else
     rejouer="None";
}
void MenuRejouer::render(sf::RenderWindow& _window){
    _window.draw(rectangle);
    _window.draw(text);
    oui.render(_window);
    non.render(_window);
}

string MenuRejouer::getRejouer(){
    return rejouer;
}

void MenuRejouer::setRejouer(string b){
    oui.setEvenementBoutton("None");
    rejouer=b;
}

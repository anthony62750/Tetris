#ifndef BOUTTON_H_INCLUDED
#define BOUTTON_H_INCLUDED

#include <SFML/Graphics.hpp>

using namespace std ;

class Boutton{

private:
    sf::Text text;
    sf::Font font;
    string evenementBoutton;

public:
    Boutton(string titre, sf::Vector2f position);
    void processEvents(sf::RenderWindow& window, sf::Event evt);
	bool contains(sf::Vector2f positionSouris);
    void render(sf::RenderWindow& window);

    string getEvenementBoutton();
    void setEvenementBoutton(std::string n);
};

#endif // BOUTTON_H_INCLUDED

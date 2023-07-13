#ifndef MENUREJOUER_H
#define MENUREJOUER_H


class MenuRejouer
{
private:
    Boutton oui;
    Boutton non;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rectangle;
    string rejouer;

public:
    MenuRejouer();
    void processEvents(sf::RenderWindow& window, sf::Event evt );
	void update();
	void render(sf::RenderWindow& _window);
	string getRejouer();
	void setRejouer(string b);
};

#endif // MENUREJOUER_H

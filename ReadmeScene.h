#ifndef READMESCENE_H
#define READMESCENE_H

#include <SFML/Graphics.hpp>

class ReadmeScene{

private:
    sf::Font font;
    sf::Text readme;
    sf::Text quitter;
    int compteur;
    std::string ReadmeSceneEvt;

public:
    ReadmeScene();
    virtual ~ReadmeScene();
    void ReadmeSceneEvenement(sf::Event evt);
    void ReadmeSceneUpdate();
    void ReadmeSceneAfficher(sf::RenderWindow& _window);

    std::string getReadmeSceneEvenement();
};

#endif // READMESCENE_H

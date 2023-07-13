#ifndef PAUSEDUJEU_H
#define PAUSEDUJEU_H

#include "Boutton.h"

class PauseDuJeu
{
private:
    std::string menuPauseEvent;
    sf::RenderWindow* fenetrePause;
    Boutton rejouer;
    Boutton recommencer;
    Boutton quitter;

public:
    PauseDuJeu(sf::RenderWindow& _window);
    virtual ~PauseDuJeu();
    void MenuPauseEvenement(sf::Event evt);
    void MenuUpdate();
    void adfficherMenuPause();


    std::string getMenuPauseEvent();
    void setMenuPauseEvent(std::string n);
};

#endif // PAUSEDUJEU_H

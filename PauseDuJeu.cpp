#include "PauseDuJeu.h"

PauseDuJeu::PauseDuJeu(sf::RenderWindow& _window):
rejouer("Reprendre", sf::Vector2f(160.0f,150.0f) ),
recommencer("Recommencer",sf::Vector2f(100.0f,280.0f) ),
quitter("Quitter", sf::Vector2f(185.0f,400.0f) )
{
    menuPauseEvent="ReprendreLaPartie";
    fenetrePause=  &_window;
}

PauseDuJeu::~PauseDuJeu(){}

void PauseDuJeu::MenuPauseEvenement(sf::Event evt){
    rejouer.processEvents(*fenetrePause, evt);
    recommencer.processEvents(*fenetrePause, evt);
    quitter.processEvents(*fenetrePause, evt);
}
void PauseDuJeu::MenuUpdate(){
    if(rejouer.getEvenementBoutton()== "Click" )
       menuPauseEvent="ReprendreLaPartie";
    if(recommencer.getEvenementBoutton()== "Click" )
         menuPauseEvent="RecommencerLaPartie";
    if(quitter.getEvenementBoutton()== "Click" )
        (*fenetrePause).close();

    rejouer.setEvenementBoutton("None");
    recommencer.setEvenementBoutton("None");
    quitter.setEvenementBoutton("None");
}

void PauseDuJeu::adfficherMenuPause(){
    rejouer.render(*fenetrePause);
    recommencer.render(*fenetrePause);
    quitter.render(*fenetrePause);
}

/*********************SET/GET************************/
 std::string PauseDuJeu::getMenuPauseEvent(){
    return menuPauseEvent;
 }

void PauseDuJeu::setMenuPauseEvent(std::string n){
    menuPauseEvent=n;
}

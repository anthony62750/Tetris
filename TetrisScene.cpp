#include "Application.h"

TetrisScene::TetrisScene(sf::RenderWindow& _window):
grille(),
piece(grille),
joueur("Test"),
menuRejouer()
{
    fenetreDuJeu = &_window;
}

TetrisScene::~TetrisScene(){}

 void TetrisScene::processEvents(sf::Event evt){
    if(grille.PartieEstTerminer()==false)
        joueur.joueurEvent(evt);
    else
        menuRejouer.processEvents(*fenetreDuJeu, evt);
 }

void TetrisScene::update(){
    if(grille.PartieEstTerminer()==false){
        if(timerDescente.getElapsedTime().asSeconds() > 1/( (joueur.getLevel()*0.1)+1) ) { //Timer, il calcul la dernière distance du timer.
            piece.faireDessendrePiece(grille);
            timerDescente.restart(); //Restat le timer
        }
        joueur.joueurUpdate(piece,grille);
        joueur.inccrementerScore(grille);
        grille.explosionUpdate();
    }
    else{
        menuRejouer.update();
        if(menuRejouer.getRejouer()=="rejouer")
            reset();
        else if(menuRejouer.getRejouer()=="quitter")
            fenetreDuJeu->close();
    }
}

void TetrisScene::render(){
    grille.afficherGrille(*fenetreDuJeu);
    piece.affichePiece(*fenetreDuJeu);
    joueur.afficherStatsJoueur(*fenetreDuJeu);
    piece.afficheNextPiece(*fenetreDuJeu);

    if(grille.PartieEstTerminer()==true){
        menuRejouer.render(*fenetreDuJeu);
    }
}

 void TetrisScene::reset(){
    menuRejouer.setRejouer("None");
    grille.explosionUpdate();
    grille.recommencerPartie();
    joueur.setLevel(0);
    joueur.setScore(0);
    joueur.setNbLigne(0);
 }

#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <iostream>
#include <string>


class Joueur{
private:
    int level;
    double score;
    int nbLigne;
    sf::Text stats[3]; //1-score _ 2-level _ 3-nbLigne
    std::string nom;
    std::string event;
    sf::Font font;


public:
    /********METHODE********/
    Joueur(std::string n);
    void joueurEvent(sf::Event evt);
    void joueurUpdate(Piece& p, Grille& g);
    void afficherStatsJoueur(sf::RenderWindow& window);
    std::string intToString(int i);
    void inccrementerScore(Grille& g);
    void inccrementerLevel();

    /********SET/GET********/
    double getScore();
    void setScore(double d);
    int getLevel();
    void setLevel(int i);
    int getNbLigne();
    void setNbLigne(int i);
    std::string getJoueurEvenement();
    void setJoueurEvenement(std::string n);
};

#endif // JOUEUR_H_INCLUDED

#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

#include <vector>
#include "ExplosionParticule.h"

class Grille{
private:
    int nombreLignePleine;
    sf::RectangleShape contour;
    std::vector<ExplosionParticule> explosion;


public:
    Cube grille[11][24];

    /********METHODE********/
    Grille();
    void afficherGrille(sf::RenderWindow& fenetre);
    void verifieSiLignePleine();
    void supprimeLaLignePleine(int l);
    bool PartieEstTerminer();
    void explosionUpdate();
    void executerExplosion(int l);
    void recommencerPartie();

    /********SET/GET********/
    int getNombreLignePleine();
    void setNombreLignePleine(int n);
};

#endif // GRILLE_H_INCLUDED

#ifndef PARTICULETETROMINOS_H
#define PARTICULETETROMINOS_H


class ParticuleTetrominos
{
    private:
        int nombreParticule;
        Cube tableauParticules[100][4][4];
        int idParticules[100];
        sf::Vector2f positionParticules[100];
        sf::Vector2f vitesseParticules[100][4][4];

    public:
        ParticuleTetrominos();
        void afficherParticules(sf::RenderWindow& _window);
        void particulesUpdate();
        void collisionParticules();
};

static float vitesseParticule[2]={-1,1};

#endif // PARTICULETETROMINOS_H

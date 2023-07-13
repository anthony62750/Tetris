#ifndef EXPLOSIONPARTICULE_H
#define EXPLOSIONPARTICULE_H


class ExplosionParticule
{
    private:
        int                     nombreParticule;
        Cube                    particuleExplosion[10];
        sf::Vector2f            vitesseParticule[10];

    public:
        ExplosionParticule(sf::Vector2f postionDepart);
        void render(sf::RenderWindow& _window);
        void update();
};

static float vitesse[2]={-1,1};

#endif // EXPLOSIONPARTICULE_H


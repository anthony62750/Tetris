#ifndef CUBE_H
#define CUBE_H

class Cube : public sf::RectangleShape
{
    private:
        int id;
        sf::Vector2f positionCube;

    public:
        /********METHODE********/
        Cube();
        void afficherCube(sf::RenderWindow & fenetre);

        /********SET/GET********/
        sf::Vector2f getPositionCube();
        void setPositionCube(sf::Vector2f v);
        int getId();
        void setId(int i);
};

#endif // CUBE_H

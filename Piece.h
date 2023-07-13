#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

class Piece
{
    private:
        int idPiece;
        sf::Vector2f position;
        int rotation;
        sf::Color couleur;
        int positionX;
        int positionY;
        Cube nextPiece[3][4][4];
        int idNextPiece[3];
        sf::RectangleShape contourNextPiece[3];

    public:
        bool pieceActive[4][4];
        /********METHODE********/
        Piece(Grille& g);
        void nouvellePiece(Grille& g);
        void initialiserNextPiece(int pieceOne, int idPieceTwo, int idPieceThree);
        void affichePiece(sf::RenderWindow& _window);
        void afficheNextPiece(sf::RenderWindow& _window);
        void faireDessendrePiece(Grille& g);
        void bougerPieceGauche(Grille& g);
        void bougerPieceDroite(Grille& g);
        bool conditionBougerPieceDroite(Grille& g);
        bool conditionBougerPieceGauche(Grille& g);
        bool conditionFaireDessendrePiece(Grille& g);
        void fixerPieceDansLaGrille(Grille& g);
        void rotationPiece(Grille& g);
        bool conditionRotationPiece(Grille& g);

        /********SET/GET********/
        int getRotation();
        void setRotation(int i);
        int getPositionX();
        void setPositionX(int i);
        int getPositionY();
        void setPositionY(int i);
        sf::Vector2f getPosition();

};

        static int listePiece[7][4][4][4] =
        {
            { // O
                {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                }
            },

            { // I
                {
                    {0, 0, 0, 0},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 1, 0}
                },

                {
                    {0, 0, 0, 0},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 1, 0}
                }
            },

            { // S
                {
                    {0, 0, 0, 0},
                    {0, 0, 1, 1},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 1, 0},
                    {0, 0, 1, 1},
                    {0, 0, 0, 1},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 0, 0},
                    {0, 0, 1, 1},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 1, 0},
                    {0, 0, 1, 1},
                    {0, 0, 0, 1},
                    {0, 0, 0, 0}
                }
            },

            { // Z
                {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 0, 1, 1},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 0, 1},
                    {0, 0, 1, 1},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 0, 1, 1},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 0, 1},
                    {0, 0, 1, 1},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
                }
            },

            { // L
                {
                    {0, 0, 0, 0},
                    {0, 1, 1, 1},
                    {0, 1, 0, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 1, 1},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 0, 0},
                    {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {0, 0, 0, 0}
                },

                {
                    {0, 1, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
                }
            },

            { // J
                {
                    {0, 0, 0, 0},
                    {0, 1, 1, 1},
                    {0, 0, 0, 1},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 1, 1},
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 1, 1, 1},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                }
            },

            { // T
                {
                    {0, 0, 0, 0},
                    {0, 1, 1, 1},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 1, 0},
                    {0, 0, 1, 1},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 1, 0},
                    {0, 1, 1, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
                },

                {
                    {0, 0, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
                }
            }
        };

        static sf::Color couleurPiece[7]={sf::Color::Yellow, sf::Color::Blue, sf::Color::Magenta, sf::Color::Cyan, sf::Color::Green, sf::Color(191,60,17), sf::Color::Red};

#endif // PIECE_H_INCLUDED

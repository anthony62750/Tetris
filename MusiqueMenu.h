#ifndef MUSIQUEMENU_H
#define MUSIQUEMENU_H


class MusiqueMenu
{
   private:
       sf::Music music;
       std::string nomMusique;
       std::string eventMusique;
       std::string rang;
       int level;

   public:
       MusiqueMenu();
       void processEvents(	sf::Event evt);
       void update();


};
#endif // MUSIQUEMENU_H

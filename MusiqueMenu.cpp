#include "Application.h"

MusiqueMenu::MusiqueMenu(){
    rang="0";
    level=100;
    eventMusique="changer";
    music.setVolume(level);
    music.setLoop(true);
}

void MusiqueMenu::processEvents(sf::Event evt){
    if (evt.type == sf::Event::KeyPressed){
            switch (evt.key.code){
                case sf::Keyboard::Num0:
                    rang="0";
                    eventMusique="changer";
                break;
                  case sf::Keyboard::Num1:
                    rang="1";
                    eventMusique="changer";
                break;
                case sf::Keyboard::Num2:
                    rang="2";
                    eventMusique="changer";
                break;
                case sf::Keyboard::Num3:
                    rang="3";
                    eventMusique="changer";
                break;
                case sf::Keyboard::Num4:
                    rang="4";
                    eventMusique="changer";
                break;
                case sf::Keyboard::Num5:
                    rang="5";
                    eventMusique="changer";
                break;
                case sf::Keyboard::Num6:
                    rang="6";
                    eventMusique="changer";
                break;
                case sf::Keyboard::Num7:
                    rang="7";
                    eventMusique="changer";
                break;
                case sf::Keyboard::Num8:
                    rang="8";
                    eventMusique="changer";
                break;
                case sf::Keyboard::Num9:
                    rang="9";
                    eventMusique="changer";
                break;
                case sf::Keyboard::Subtract:
                    eventMusique="reduireMusique";
                break;
                case sf::Keyboard::Add:
                    eventMusique="augmenterMusique";
                break;
                case sf::Keyboard::Multiply :
                    eventMusique="etatMusique";
                break;
                default:
                    eventMusique="none";
                break;
            }
    }
}

void MusiqueMenu::update(){
    nomMusique= "ressources/Musique/theme" +rang+".ogg";
    if (eventMusique=="changer" && !music.openFromFile(nomMusique) )
        exit(EXIT_FAILURE);
    if( eventMusique=="changer")
          music.play();
    if(eventMusique=="reduireMusique" && level >0)
        level-=5;
    if(eventMusique=="augmenterMusique" && level<100)
        level+=5;
    if( eventMusique=="etatMusique"){
        if(music.getStatus()==sf::Music::Paused)
            music.play();
        else
            music.pause();
        eventMusique="none";
    }
    music.setVolume(level);
    eventMusique="none";
}

#include "application.h"

Application::Application():
_window(sf::VideoMode(600, 600), "Tetris", sf::Style::Close),
sceneTetris(_window),
scenePauseDuJeu(_window),
readme(),
musique()
{
    _window.setFramerateLimit(60);
    sf::Image icon;

    if(!icon.loadFromFile("ressources/Images/TetrisLogo.png"))
        exit(EXIT_FAILURE);

    _window.setIcon(32,32,icon.getPixelsPtr());
}

void Application::run()
{
	while (_window.isOpen())
	{
	    processEvents();
		update();
		render();
	}
}


void Application::processEvents()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
	    if (event.type == sf::Event::Closed)
                _window.close();
        musique.processEvents(event);
	    if(readme.getReadmeSceneEvenement()== "None")
            readme.ReadmeSceneEvenement(event);

        if(readme.getReadmeSceneEvenement()== "Quitter"){
            if(event.type==sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape)
                    scenePauseDuJeu.setMenuPauseEvent("Pause");
            }
            if(scenePauseDuJeu.getMenuPauseEvent()=="Pause")
                scenePauseDuJeu.MenuPauseEvenement(event);
            if(scenePauseDuJeu.getMenuPauseEvent()=="ReprendreLaPartie")
                sceneTetris.processEvents(event);
        }
	}
}

void Application::update()
{
    musique.update();
    if(readme.getReadmeSceneEvenement()== "None")
        readme.ReadmeSceneUpdate();
    if(readme.getReadmeSceneEvenement()== "Quitter" && scenePauseDuJeu.getMenuPauseEvent()=="Pause")
        scenePauseDuJeu.MenuUpdate();
    if(readme.getReadmeSceneEvenement()== "Quitter" && scenePauseDuJeu.getMenuPauseEvent()=="ReprendreLaPartie")
        sceneTetris.update();
    particuleTetromino.particulesUpdate();
}

void Application::render()
{
	_window.clear(sf::Color::White);
	particuleTetromino.afficherParticules(_window);
	if(readme.getReadmeSceneEvenement()== "Quitter" && scenePauseDuJeu.getMenuPauseEvent()=="Pause")
        scenePauseDuJeu.adfficherMenuPause();
	if(readme.getReadmeSceneEvenement()== "Quitter" && scenePauseDuJeu.getMenuPauseEvent()=="RecommencerLaPartie"){
        sceneTetris.reset();
        scenePauseDuJeu.setMenuPauseEvent("ReprendreLaPartie");
	}
    if(readme.getReadmeSceneEvenement()== "Quitter" && scenePauseDuJeu.getMenuPauseEvent()=="ReprendreLaPartie")
        sceneTetris.render();
    if(readme.getReadmeSceneEvenement()== "None")
        readme.ReadmeSceneAfficher(_window);
	_window.display();
}

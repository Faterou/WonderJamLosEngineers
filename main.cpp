#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <ctime>
#include <iostream>
#include "Destination.h"
#include<fstream>
#include<string>
#include<cctype>
#include <Map.h>
#include "Scene.h"
#include "RaceScene.h"
#include "Voiture.h"

Scene* current_scene = new RaceScene();

sf::RenderWindow window;
Voiture* player1;
Voiture* player2;


/**
    Function to handle events of the main loop, like the one to close the window.
*/
void processGlobalEvents()
{
    sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
}

int main()
{

    int window_width = 1000;
    int window_height = 500;
    window.create(sf::VideoMode(window_width, window_height), "SFML works bitch!");
    player1 = new Voiture("voitureRouge.png");
    player2 = new Voiture("voitureRouge.png");

    while (window.isOpen())
    {
        processGlobalEvents();
        current_scene->process();
    }

    return 0;
}

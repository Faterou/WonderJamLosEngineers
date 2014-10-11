#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <ctime>
#include <iostream>
#include<fstream>
#include<string>
#include<cctype>
#include <Map.h>

sf::RenderWindow window(sf::VideoMode(640, 480), "LoadmapTest");//




int main()
{

    Map map1;


    sf::SoundBuffer buffer;
    buffer.loadFromFile("musiqueBackground.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        map1.draw();
        window.display();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

    }

    return 0;
}

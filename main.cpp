#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <windows.h>
#include "voiture.h"



int main()
{
    voiture player1("voitureRouge.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                std::cout << "baloney" << std::endl;
                player1.getSprite()->move(-10, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                player1.getSprite()->move(10, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                player1.getSprite()->move(0, -10);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                player1.getSprite()->move(0, 10);
            }

            window.clear();
            window.draw(*player1.getSprite());
            //player1.drawCar();
            window.display();

        }
    }

    return 0;
}

#include "MenuScene.h"
#include "Map.h"
#include "Destination.h"
#include "StatsScene.h"
#include "EndScene.h"
#include "voiture.h"
#include <stdlib.h>



MenuScene::MenuScene()
{
    //ctor
}

MenuScene::~MenuScene()
{
    //dtor
}

void MenuScene::update(){}

void MenuScene::inputs()
{
    sf::Event event1;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        std::cout << "allo" << std::endl;
        if (selectedItemIndex - 1 >= 0)
        {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
        }
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
     {
        std::cout << selectedItemIndex << std::endl;

            std::cout << selectedItemIndex << std::endl;
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex++;
            menu[selectedItemIndex].setColor(sf::Color::Red);
     }



}

void MenuScene::draw()
{
    window.clear();

    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile("imageMenu.png"))
    {
        std::cout << "Ca marche pas gros mongole" << std::endl;
    }

    sprite.setTexture(texture);

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "erreur" << std::endl;
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(450, 125));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Help");
    menu[1].setPosition(sf::Vector2f(450, 200));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Setting");
    menu[2].setPosition(sf::Vector2f(425, 275));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setPosition(sf::Vector2f(450, 350));

    window.draw(sprite);
    for (int i = 0; i < 4; i++)
    {
        window.draw(menu[i]);
    }

    window.display();

}




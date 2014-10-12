#include "MenuScene.h"
#include "Map.h"
#include "Destination.h"
#include "StatsScene.h"
#include "EndScene.h"
#include "voiture.h"
#include <stdlib.h>



MenuScene::MenuScene()
{
    window.clear();
    sf::Text menuPlay;
    sf::Text menuExit;
    sf::Text menuAide;
    sf::Text menuSetting;

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
}

MenuScene::~MenuScene()
{
    //dtor
}


void MenuScene::update(){}

void MenuScene::inputs()
{
    sf::Event event1;
    //Peut être grandement amélioré, pour ralentir la saisie.


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {

        if (selectedItemIndex > 0)
        {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex--;
            menu[selectedItemIndex].setColor(sf::Color::Red);
            std::cout << "allo" << std::endl;
        }
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
     {
            if(selectedItemIndex  < 3)
            {
                std::cout << selectedItemIndex << std::endl;
                menu[selectedItemIndex].setColor(sf::Color::White);
                selectedItemIndex++;
                menu[selectedItemIndex].setColor(sf::Color::Red);
            }

            else
            {
                std::cout << "TU peux pas y aller!!!" << std::endl;
            }
     }

     Sleep(100);
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
    window.draw(sprite);
    for (int i = 0; i < 4; i++)
    {
        window.draw(menu[i]);
    }


    window.display();

}




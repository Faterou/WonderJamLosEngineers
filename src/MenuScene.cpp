#include "MenuScene.h"
#include "Map.h"
#include "Destination.h"
#include "StatsScene.h"
#include "EndScene.h"
#include "Scene.h"
#include "RaceScene.h"
#include "AideScene.h"
#include "StatsScene.h"
#include "voiture.h"
#include <stdlib.h>

extern Voiture* player1;
extern Voiture* player2;

MenuScene::MenuScene()
{
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


void MenuScene::update()
{


}

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
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
     {
         Sleep(200);
         switch(selectedItemIndex)
         {
         case 0:        //Attention, ici la prochaine étape serait d'aller à une StatsScene
         {
            Scene* next_scene = new StatsScene(*player1, *player2, 20000);
            this->changeScene(next_scene);
            break;
         }
         case 1:
             {
                Scene* next_scene= new AideScene();
                this->changeScene(next_scene);
                break;
             }

         case 2:
            std::cout << "case 2 \n";
            break;

         case 3:
             window.close();
            break;

         }


     }

    //Pour ralentir la saisie
     Sleep(50);
}

void MenuScene::draw()
{
    window.clear();
    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile("imageMenu.png"))
    {
        std::cout << "L'image de fond ne peut être chargé" << std::endl;
    }

    sprite.setTexture(texture);
    window.draw(sprite);
    for (int i = 0; i < 4; i++)
    {
        window.draw(menu[i]);
    }


    window.display();

}




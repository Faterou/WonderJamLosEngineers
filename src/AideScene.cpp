#include "AideScene.h"
#include <iostream>

extern sf::RenderWindow window;

AideScene::AideScene()
{
    //ctor
}

AideScene::~AideScene()
{
    //dtor
}

void AideScene::inputs()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        Scene* next_scene = new MenuScene();
        this->changeScene(next_scene);
    }
}

void AideScene::draw()
{
    window.clear();
    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile("zombie_teacher.png"))
    {
        std::cout << "L'image de fond ne peut être chargé" << std::endl;
    }

    sprite.setTexture(texture);
    window.draw(sprite);

    window.display();

}

void AideScene::update(){}

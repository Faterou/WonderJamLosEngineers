#include "AideScene.h"
#include <iostream>

extern sf::RenderWindow window;

AideScene::AideScene()
{

    if (!backgroundBuffer.loadFromFile("menuBackground.wav"))
    {
       std::cout << "impossible de loader la musique background \n";
    }

    m_sound.setBuffer(backgroundBuffer);

    m_sound.setLoop(true);

    m_sound.play();
}

AideScene::~AideScene()
{
    //dtor
}

void AideScene::inputs()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        m_sound.stop();
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

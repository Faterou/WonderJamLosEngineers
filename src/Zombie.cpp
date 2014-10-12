#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
#include "Zombie.h"
#include "Scene.h"
using namespace std;
extern sf::RenderWindow window;
extern Scene* current_scene;

//Constructeur
Zombie::Zombie(string nomPhoto) : GameObject(sf::Sprite(),ZOMBIE), points()
{
    GameObject::setTexture(TextureManager::getInstance().getTexture(nomPhoto));
    getSprite()->setOrigin(getSprite()->getGlobalBounds().width/2,getSprite()->getGlobalBounds().height/2);
}
//Destructeur
Zombie::~Zombie()
{
    //dtor
}

///////////////////////////////////////////////////////////////////////////////////////
//Accesseurs et mutateurs
///////////////////////////////////////////////////////////////////////////////////////
sf::Sprite* Zombie::getSprite()
{
    return GameObject::getSprite();
}

void Zombie::setSprite(sf::Sprite* monSprite)
{
    GameObject::setSprite(*monSprite);
}

bool Zombie::getDeath()
{
    return death;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Fonctions
///////////////////////////////////////////////////////////////////////////////////////////////


void Zombie::draw()
{
    GameObject::draw();
}

sf::Vector2f Zombie::getHeading()
{
    float teta = getSprite()->getRotation();
    float x = cos(teta*M_PI/180);
    float y = sin(teta*M_PI/180);

    return sf::Vector2f(x,y);
}

void Zombie::move()
{
    int random = rand() % 100;
    if(random < 5)
    {
        bool clockwise = rand()%2;
        if(clockwise)
            getSprite()->rotate(rand()%15);
        else
            getSprite()->rotate(-rand()%15);
    }
    getSprite()->move(0.2f*getHeading());
}

void Zombie::drawPoints()
{
    sf::Clock clock;
    while(clock.getElapsedTime().asSeconds() < 3)
    {
        window.draw(*getSpritePoints());
        window.display();
    }
}

void Zombie::onCollision(GameObject* collidedTo)
{
    if(collidedTo->getType() == GameObject::CAR)
    {
        death = true;
        GameObject::setTexture(TextureManager::getInstance().getTexture("blood1.png"));
//        *points = sf::Sprite(*(TextureManager::getInstance().getTexture("petrolepoint.png")));
//        points->setPosition(getSprite()->getPosition());
//        current_scene->getGameObjects()->push_back(new GameObject(*points,GameObject::POINTS));
//        current_scene->getGameObjects()->at(current_scene->getGameObjects()->size()-1);
    }
}


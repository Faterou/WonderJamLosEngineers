#include "GameObject.h"
using namespace std;
extern sf::RenderWindow window;

GameObject::GameObject() : sprite(), type()
{
}

GameObject::GameObject(sf::Sprite sprite, Type type) : sprite(sprite), type(type)
{

}

void GameObject::onCollision(GameObject*) {}
//void GameObject::onCollision(Map::TypeTerrain) {}

void GameObject::draw()
{
    window.draw(sprite);
}


GameObject::~GameObject()
{
    //dtor
}

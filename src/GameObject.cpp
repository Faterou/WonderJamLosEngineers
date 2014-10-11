#include "GameObject.h"
using namespace std;

GameObject::GameObject() : sprite(), name()
{

}

GameObject::GameObject(sf::Sprite sprite) : sprite(sprite), name()
{

}

void GameObject::onCollision(GameObject* object)
{

}

void GameObject::setName(string name)
{
    this->name = name;
}

void GameObject::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

GameObject::~GameObject()
{
    //dtor
}

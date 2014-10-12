#include "GameObject.h"
#include <iostream>
using namespace std;
extern sf::RenderWindow window;

GameObject::GameObject() : sprite(), type()
{
}

GameObject::GameObject(sf::Sprite sprite, Type type) : sprite(sprite), type(type)
{

}

void GameObject::onCollision(GameObject* object) {

}

void GameObject::draw()
{
    window.draw(sprite);
}


GameObject::~GameObject()
{
    //dtor
}

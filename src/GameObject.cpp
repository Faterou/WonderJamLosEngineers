#include "GameObject.h"
using namespace std;

GameObject::GameObject() : sprite(), type()
{
}

GameObject::GameObject(sf::Sprite sprite, Type type) : sprite(sprite), type(type)
{

}

GameObject::~GameObject()
{
    //dtor
}

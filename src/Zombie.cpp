#include "Zombie.h"

extern sf::Window window;

//Constructeur
Zombie::Zombie()
{
    //ctor
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

sf::Texture* Zombie::getTexture()
{
    return GameObject::getTexture();
}

void Zombie::setTexture(sf::Texture* maTexture)
{
    GameObject::setTexture(*maTexture);
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Fonctions
///////////////////////////////////////////////////////////////////////////////////////////////


void Zombie::draw()
{
    GameObject::draw();
}

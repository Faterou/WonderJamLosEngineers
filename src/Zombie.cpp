#include "Zombie.h"

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
    //Pour déssiner un zombie, il faut d'abod que le Sprite aie une position et une textureRect
    window.draw(*(GameObject::getSprite()));
}

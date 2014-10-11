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
sf::Sprite Zombie::getSprite()
{
    return GetObject::getSprite();
}

void Zombie::setSprite(sf::Sprite monSprite)
{
    GetObject::setSprite(monSprite);
}

sf::Texture Zombie::getTexture()
{
    return GetObject::getTexture();
}

void Zombie::setTexture(sf::Texture maTexture)
{
    GetObject::setTexture(maTexture);
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Fonctions
///////////////////////////////////////////////////////////////////////////////////////////////


void Zombie::draw()
{
    //Pour déssiner un zombie, il faut d'abod que le Sprite aie une position et un textureRect
    window.draw(GetObject::getSprite());
}

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



///////////////////////////////////////////////////////////////////////////////////////////////
//Fonctions
///////////////////////////////////////////////////////////////////////////////////////////////


void Zombie::draw()
{
    GameObject::draw();
}

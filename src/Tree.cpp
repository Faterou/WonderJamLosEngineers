#include "Tree.h"

#include <iostream>

Tree::Tree()
{

}

Tree::Tree(sf::Sprite monSprite)
{
    GameObject::setSprite(monSprite);
    sf::Texture texture;

    if (!texture.loadFromFile("Tree1.png"))
    {
        std::cout << "Erreur chargement d'arbre" << std::endl;
    }

    GameObject::setTexture(texture);
}

Tree::~Tree()
{
    //dtor
}

//Fonctions
sf::Sprite Tree::getSprite()
{
   // return treeSprite;
}


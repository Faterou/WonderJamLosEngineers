#include "Tree.h"

Tree::Tree()
{
    //ctor
}

Tree::Tree(sf::Sprite monSprite)
{
    treeSprite = monSprite;
}

Tree::~Tree()
{
    //dtor
}

//Fonctions
sf::Sprite Tree::getSprite()
{
    return treeSprite;
}


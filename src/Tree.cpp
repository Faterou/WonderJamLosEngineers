#include "Tree.h"

#include <iostream>
#include <TextureManager.h>

Tree::Tree()
{

}

Tree::Tree(sf::Sprite monSprite) : GameObject(monSprite,TREE)
{
    GameObject::setTexture(TextureManager::getInstance().getTexture("Tree1.png"));
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


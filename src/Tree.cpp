#include "Tree.h"

#include <iostream>
#include <TextureManager.h>

Tree::Tree()
{

}

Tree::Tree(sf::Sprite monSprite)
{
    GameObject::setSprite(monSprite);

<<<<<<< HEAD
    if (!texture.loadFromFile("Tree1.png"))
    {
        std::cout << "Erreur chargement d'arbre" << std::endl;
    }

    GameObject::setTexture(texture);
    GameObject::setType(TREE);
=======
    GameObject::setTexture(TextureManager::getInstance().getTexture("Tree1.png"));
>>>>>>> c9250b66272705e059090c7b64188e43ed7885c2
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


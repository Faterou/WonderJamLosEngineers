#ifndef TREE_H
#define TREE_H

#include "GameObject.h"


class Tree : public GameObject
{
    public:
        Tree();
        Tree(sf::Sprite);
        sf::Sprite getSprite();
        virtual ~Tree();
    protected:
    private:

};

#endif // TREE_H

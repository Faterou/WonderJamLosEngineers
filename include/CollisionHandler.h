#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "GameObject.h"
#include "OrientedBoundingBox.h"
#include <list>

class CollisionHandler
{
    public:
        CollisionHandler();
        bool checkAllCollisions();
        bool checkCollision(GameObject*,GameObject*);
        bool checkCollisionMenu(MenuItem*,sf::Vector2i);
        virtual ~CollisionHandler();
    protected:
    private:
        bool OrientedBoundingBoxTest(const sf::Sprite*, const sf::Sprite*);
        bool AABBCollisionTest(const sf::Sprite*, sf::Vector2i)
};

#endif // COLLISIONHANDLER_H

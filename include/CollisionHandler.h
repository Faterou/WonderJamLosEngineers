#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "GameObject.h"
#include "OrientedBoundingBox.h"

class CollisionHandler
{
    public:
        CollisionHandler();
        bool checkAllCollisions();
        bool checkCollision(GameObject*,GameObject*);
        virtual ~CollisionHandler();
    protected:
    private:
        bool OrientedBoundingBoxTest(const sf::Sprite* Object1, const sf::Sprite* Object2);
};

#endif // COLLISIONHANDLER_H

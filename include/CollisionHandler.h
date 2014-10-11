#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "GameObject.h"
#include "MenuItem.h"
#include "OrientedBoundingBox.h"
#include <list>
#include <vector>

extern std::vector<GameObject*> gameObjects;
std::vector<GameObject*> gameObjects; //BIDON, à supprimer losque les scènes seront prêtes

class CollisionHandler
{
    public:
        CollisionHandler();
        bool checkAllCollisions();
        bool checkCollision(GameObject*,GameObject*);
        virtual ~CollisionHandler();
    protected:
    private:
        bool OrientedBoundingBoxTest(const sf::Sprite*, const sf::Sprite*);
        bool AABBCollisionTest(const sf::Sprite*, sf::Vector2i);
};

#endif // COLLISIONHANDLER_H

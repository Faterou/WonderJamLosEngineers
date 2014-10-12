#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "GameObject.h"
#include "MenuItem.h"
#include "OrientedBoundingBox.h"
#include <list>
#include <vector>
#include "Scene.h"

extern Scene* current_scene;

class CollisionHandler
{
    public:
        CollisionHandler();
        bool checkAllCollisions();
        bool checkAllCollisions(GameObject* go, std::vector<GameObject*> *objects);
        bool checkCollision(GameObject*,GameObject*);
        virtual ~CollisionHandler();
    protected:
    private:
        bool OrientedBoundingBoxTest(const sf::Sprite*, const sf::Sprite*);
        bool AABBCollisionTest(const sf::Sprite*, sf::Vector2i);
};

#endif // COLLISIONHANDLER_H

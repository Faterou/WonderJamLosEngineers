#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{

}

bool CollisionHandler::checkAllCollisions()
{

}

bool CollisionHandler::checkCollision(GameObject* object1, GameObject* object2)
{
    return OrientedBoundingBoxTest(object1->getSprite(),object2->getSprite());
}

bool CollisionHandler::OrientedBoundingBoxTest(const sf::Sprite* Object1, const sf::Sprite* Object2) {
    OrientedBoundingBox OBB1 (*Object1);
    OrientedBoundingBox OBB2 (*Object2);

    // Create the four distinct axes that are perpendicular to the edges of the two rectangles
    sf::Vector2f Axes[4] = {
        sf::Vector2f (OBB1.getPoint(1).x-OBB1.getPoint(0).x,
        OBB1.getPoint(1).y-OBB1.getPoint(0).y),
        sf::Vector2f (OBB1.getPoint(1).x-OBB1.getPoint(2).x,
        OBB1.getPoint(1).y-OBB1.getPoint(2).y),
        sf::Vector2f (OBB2.getPoint(0).x-OBB2.getPoint(3).x,
        OBB2.getPoint(0).y-OBB2.getPoint(3).y),
        sf::Vector2f (OBB2.getPoint(0).x-OBB2.getPoint(1).x,
        OBB2.getPoint(0).y-OBB2.getPoint(1).y)
    };

    for (int i = 0; i<4; i++) // For each axis...
    {
        float MinOBB1, MaxOBB1, MinOBB2, MaxOBB2;

        // ... project the points of both OBBs onto the axis ...
        OBB1.ProjectOntoAxis(Axes[i], MinOBB1, MaxOBB1);
        OBB2.ProjectOntoAxis(Axes[i], MinOBB2, MaxOBB2);

        // ... and check whether the outermost projected points of both OBBs overlap.
        // If this is not the case, the Seperating Axis Theorem states that there can be no collision between the rectangles
        if (!((MinOBB2<=MaxOBB1)&&(MaxOBB2>=MinOBB1)))
            return false;
    }
    return true;
}

bool CollisionHandler::checkCollisionMenu(MenuItem* item,sf::Vector2i mousePosition)
{

}

bool CollisionHandler::AABBCollisionTest(const sf::Sprite* itemSprite, sf::Vector2i mousePosition)
{
    if(itemSprite->getGlobalBounds().left <=  mousePosition.x &&
       itemSprite->getGlobalBounds().top >= mousePosition.y &&
       itemSprite->getGlobalBounds().left + itemSprite->getGlobalBounds().width > mousePosition.x &&
       itemSprite->getGlobalBounds().top + itemSprite->getGlobalBounds().width < mousePosition.y)
        return true;
    else
        return false;
}

CollisionHandler::~CollisionHandler()
{
    //dtor
}

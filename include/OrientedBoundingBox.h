#ifndef ORIENTEDBOUNDINGBOX_H
#define ORIENTEDBOUNDINGBOX_H

#include <SFML/Graphics.hpp>

class OrientedBoundingBox // Used in the BoundingBoxTest
    {
    public:
        OrientedBoundingBox (const sf::Sprite& Object); // Calculate the four points of the OBB from a transformed (scaled, rotated...) sprite
        void ProjectOntoAxis (const sf::Vector2f& Axis, float& Min, float& Max); // Project all four points of the OBB onto the given axis and return the dotproducts of the two outermost points
        sf::Vector2f getPoint(int x) {return Points[x];};

    private:
        sf::Vector2f Points[4];
};

#endif // ORIENTEDBOUNDINGBOX_H

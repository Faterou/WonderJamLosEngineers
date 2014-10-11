#include "OrientedBoundingBox.h"

OrientedBoundingBox::OrientedBoundingBox (const sf::Sprite& Object) // Calculate the four points of the OBB from a transformed (scaled, rotated...) sprite
{
    sf::Transform trans = Object.getTransform();
    sf::IntRect local = Object.getTextureRect();
    m_Points[0] = trans.transformPoint(0.f, 0.f);
    m_Points[1] = trans.transformPoint(local.width, 0.f);
    m_Points[2] = trans.transformPoint(local.width, local.height);
    m_Points[3] = trans.transformPoint(0.f, local.height);
}

void OrientedBoundingBox::ProjectOntoAxis (const sf::Vector2f& Axis, float& Min, float& Max) // Project all four points of the OBB onto the given axis and return the dotproducts of the two outermost points
{
    Min = (m_Points[0].x*Axis.x+m_Points[0].y*Axis.y);
    Max = Min;
    for (int j = 1; j<4; j++)
    {
        float Projection = (m_Points[j].x*Axis.x+m_Points[j].y*Axis.y);

        if (Projection<Min)
            Min=Projection;
        if (Projection>Max)
            Max=Projection;
    }
}

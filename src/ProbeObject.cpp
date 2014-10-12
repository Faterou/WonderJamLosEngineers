#include "ProbeObject.h"

ProbeObject::ProbeObject(int x, int y): collided(false)
{
    GameObject::getSprite()->setPosition(x,y);
}

ProbeObject::~ProbeObject()
{
    //dtor
}

void ProbeObject::onCollision(GameObject* go)
{
    collided = true;
}

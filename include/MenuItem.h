#ifndef MENUITEM_H
#define MENUITEM_H

#include "GameObject.h"

class MenuItem : GameObject
{
    public:
        MenuItem();
        MenuItem(sf::Sprite);
        virtual void onCollision(GameObject*);
        virtual void draw()
        virtual ~MenuItem();
    protected:
    private:
};

#endif // MENUITEM_H

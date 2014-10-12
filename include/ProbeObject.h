#ifndef PROBEOBJECT_H
#define PROBEOBJECT_H

#include <GameObject.h>


class ProbeObject : public GameObject
{
    public:
        ProbeObject(int x, int y);
        virtual ~ProbeObject();
        void onCollision(GameObject*);
        bool collided;
    protected:
    private:

};

#endif // PROBEOBJECT_H

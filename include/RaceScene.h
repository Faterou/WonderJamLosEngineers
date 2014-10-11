#ifndef RACESCENE_H
#define RACESCENE_H

#include "Scene.h"

class RaceScene : public Scene
{
    public:
        RaceScene();
        virtual void inputs();
        virtual void update();
        virtual void draw();
        void drawObjects();
        virtual ~RaceScene();
    protected:
    private:
};

#endif // RACESCENE_H

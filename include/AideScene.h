#ifndef AIDESCENE_H
#define AIDESCENE_H

#include <Scene.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include "MenuScene.h"


class AideScene : public Scene
{
    public:
        AideScene();
        virtual ~AideScene();
        virtual void inputs();
        virtual void update();
        virtual void draw();

    protected:
    private:
};

#endif // AIDESCENE_H

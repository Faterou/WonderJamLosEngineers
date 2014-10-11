#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <Scene.h>


class MenuScene : public Scene
{
    public:
        MenuScene();
        virtual ~MenuScene();

        virtual void inputs();
        virtual void update();
        virtual void draw();
    protected:
    private:
};

#endif // MENUSCENE_H

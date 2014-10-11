#ifndef STATSSCENE_H
#define STATSSCENE_H

#include <Scene.h>


class StatsScene : public Scene
{
    public:
        StatsScene();
        virtual ~StatsScene();

        virtual void inputs();
        virtual void update();
        virtual void draw();
    protected:
    private:
};

#endif // STATSSCENE_H

#ifndef RACESCENE_H
#define RACESCENE_H

#include "Scene.h"
#include "Map.h"

#define MAX_ROUND 5

class RaceScene : public Scene
{
    public:
        RaceScene();
        virtual void inputs();
        virtual void update();
        virtual void draw();
        virtual ~RaceScene();
        void end_race(GameObject* winner, GameObject* loser, int time_difference);
        void drawObjects();
    protected:
    private:
        void populate();
        Map map;
        static int round;
};

#endif // RACESCENE_H

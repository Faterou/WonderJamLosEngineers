#ifndef RACESCENE_H
#define RACESCENE_H

#include "Scene.h"
#include "Map.h"
#include "CollisionHandler.h"

#define MAX_ROUND 5

class RaceScene : public Scene
{
    public:
        RaceScene();
        virtual void inputs();
        virtual void update();
        virtual void draw();
        virtual ~RaceScene();
        void checkCollisions();
        void end_race(GameObject* winner, GameObject* loser, int time_difference);
        void drawObjects();
    protected:
    private:
        CollisionHandler chandler;
        void populate();
        Map map;
        sf::View view_player1;
        sf::View view_player2;
        static int round;
        sf::Thread m_thread;
};

#endif // RACESCENE_H

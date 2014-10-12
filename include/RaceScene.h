#ifndef RACESCENE_H
#define RACESCENE_H

#include "Scene.h"
#include "Map.h"
#include "CollisionHandler.h"

#define MAX_ROUND 5

class RaceScene : public Scene
{
    public:
        RaceScene(GameObject* last_winner, GameObject* last_loser, int delta);
        virtual void inputs();
        virtual void update();
        virtual void draw();
        virtual ~RaceScene();
        void checkCollisions();
        void end_race(GameObject* winner, GameObject* loser, int time_difference);
        void drawObjects();
        void first_player_finished(GameObject*);
    protected:
    private:
        CollisionHandler chandler;
        void populate();
        Map map;
        sf::View view_player1;
        sf::View view_player2;
        static int round;
        sf::Thread m_thread;
        bool terminate_thread;
        GameObject* winner;
        GameObject* destination;
        void sort_trees();
        sf::Font font;
        GameObject* last_winner;
        GameObject* last_loser;
        int delta;
        sf::Clock clock;
};

#endif // RACESCENE_H

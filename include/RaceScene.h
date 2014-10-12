#ifndef RACESCENE_H
#define RACESCENE_H

#include "Scene.h"
#include "Map.h"
#include "CollisionHandler.h"
#include <SFML/Audio.hpp>

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

        sf::Sound m_sound;
        sf::SoundBuffer backgroundBuffer;





};

#endif // RACESCENE_H

#ifndef STATSSCENE_H
#define STATSSCENE_H

#include <Scene.h>

extern sf::RenderWindow window;

class StatsScene : public Scene
{
    public:
        StatsScene(GameObject winner, GameObject loser, int time_difference);
        virtual ~StatsScene();

        virtual void inputs();
        virtual void update();
        virtual void draw();
    protected:
    private:
};

#endif // STATSSCENE_H

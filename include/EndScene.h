#ifndef ENDSCENE_H
#define ENDSCENE_H

#include <Scene.h>


class EndScene : public Scene
{
    public:
        EndScene(GameObject* winner, GameObject* loser, int time_difference);
        virtual ~EndScene();

        virtual void inputs();
        virtual void update();
        virtual void draw();
    protected:
    private:
        std::string results;

        sf::Sound m_sound;
        sf::SoundBuffer backgroundBuffer;
};

#endif // ENDSCENE_H

#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "GameObject.h"

class Scene
{
    public:
        virtual ~Scene();
        virtual void process();
        virtual void inputs() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        void changeScene(Scene*);

        std::vector< GameObject* >* getGameObjects() {return &gameObjects;};
    protected:
    private:
        std::vector< GameObject* > gameObjects;
};

#endif // SCENE_H

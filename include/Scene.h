#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "GameObject.h"
#include "Zombie.h"

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
        std::vector<GameObject*>::iterator addObjectToVector(GameObject*);
        void deleteObjectFromVector(std::vector<GameObject*>::iterator);
        std::vector<Zombie*>* getZombies() {return &zombies;};
    protected:
    private:
        std::vector< GameObject* > gameObjects;
        std::vector<Zombie*> zombies;
};

#endif // SCENE_H

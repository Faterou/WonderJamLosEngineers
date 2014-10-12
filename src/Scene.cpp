#include "Scene.h"
#include <iostream>
using namespace std;

extern Scene* current_scene;

Scene::~Scene()
{
    for(int i=0; i < gameObjects.size(); i++)
    {
        delete gameObjects[i];
    }
}

void Scene::process()
{
    inputs();
    update();
    draw();
}

void Scene::changeScene(Scene* scene)
{
    current_scene = scene;
}

vector<GameObject*>::iterator Scene::addObjectToVector(GameObject* object)
{
    gameObjects.push_back(object);
    vector<GameObject*>::iterator it = gameObjects.end()-1;
    return it;
}

void Scene::deleteObjectFromVector(vector<GameObject*>::iterator objectPos)
{
    gameObjects.erase(objectPos);
}

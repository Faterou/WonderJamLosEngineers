#include "Scene.h"

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

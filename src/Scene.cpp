#include "Scene.h"

extern Scene* current_scene;

Scene::~Scene() {}

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

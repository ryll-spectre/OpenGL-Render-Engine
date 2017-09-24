
#include "Scene.hpp"

Scene::~Scene(){
    for (int i=0;i<sceneObjects.size();i++)
    {
        delete sceneObjects[i];
    }
    sceneObjects.clear();
}


void Scene::render(Camera* camera){
    
    for (int i=0;i<sceneObjects.size();i++)
    {
        sceneObjects[i]->render(camera);
    }
}

void Scene::addObject(Object *object){
    sceneObjects.push_back(object);
    
}


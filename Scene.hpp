/*
 * Scene.hpp
 *
 *  Class for representing a scene. Can have multiple child nodes (objects).
 *  Has a rendering function that takes care of rendering all objects in the scene.
 *  by Stefanie Zollmann
 *
 */
#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "Object.hpp"


//!  Scene.
/*!
 Basic scene represenation consisting of a couple of objects
 */
class Scene{
    
    public:
        Scene(){};
        ~Scene();
        //! render
        /*! Render all objects in the scene. Will call individal render methods. */
        void render(Camera* camera);
        //! addObject
        /*! Add an object to the scene. */
        void addObject(Object *object);
    
    private:
        std::vector<Object*> sceneObjects;
    
    
};


#endif


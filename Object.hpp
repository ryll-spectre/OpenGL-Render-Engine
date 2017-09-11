/*
 * Object.hpp
 *
 * Class for representing scenegraph objects, e.g. simple ones like triangles, quads, but also more complex meshes.
 Each object has a tranformation.
 * by Stefanie Zollmann
 *
 */
#ifndef OBJECT_HPP
#define OBJECT_HPP

// Include GLM
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
#include "Shader.hpp"
#include "Texture.hpp"
#include "Camera.hpp"


//!  Object.
/*!
 Basic object base class that has a tranformation
 */
class Object{
    public:
        //! Default constructor
        /*! Setting up default object. */
        Object();
        //! Destructor
        /*! Delete all related ressources. */
        virtual ~Object(){
            
            delete shader;
        }
        //! setShader
        /*! Set a shader object that will be used during the rendering of this object. */
        void setShader(Shader* newshader);
        
        //! getTransform
        /*! Get the transform matrix 4x4 of this object. */
        glm::mat4 getTransform();
        
        //! addTransform
        /*! Add a transform matrix (4x4) to this object. */
        void addTransform(glm::mat4 mat);
       
        //! render
        /*! Virtual render method, needs to be defined for each geometry class */
        virtual void render(Camera* camera)=0;
        
        //! setTranslate
        /*! Set defined translate this object. */
        void setTranslate(glm::vec3 translateVec);
        //! setScale
        /*! Set defined scale this object. */
        void setScale(float scale);
        //! bindShaders
        /*! Bind shader of this object. */
        void bindShaders();
        //! unBindShader
        /*! Unbind shader of this object. */
        void unBindShader();
        
    private:
        std::string name;       //!< name of object
        glm::mat4 transform;    //!< transform matrix of the object
        glm::mat4 rotMat;       //!< rotation matrix
        glm::mat4 transMat;     //!< translation matrix
        glm::mat4 scaleMat;     //!< scale matrix
        
    protected:
        Shader* shader;         //!< each object can have a shader
        
    
};

#endif


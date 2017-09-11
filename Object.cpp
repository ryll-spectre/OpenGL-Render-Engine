

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
#include "Object.hpp"
//basic object base class that has a tranformation
Object::Object(){
    // set identity
    // Build the model matrix -get from object
    rotMat = glm::mat4(1.0f);
    transMat = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, 0.0f));
    scaleMat = glm::scale(glm::mat4(), glm::vec3(1.0f, 1.0f, 1.0f));
    transform = transMat * rotMat * scaleMat;
    
    shader = NULL;
    
}
void Object::setShader(Shader* newshader){
    if(shader!=NULL)
        delete shader;
    
    shader = newshader;
    
}
glm::mat4 Object::getTransform(){return transform;}
void Object::addTransform(glm::mat4 mat){
    transform = mat;
}
void Object::setTranslate(glm::vec3 translateVec){
    transMat = glm::translate(glm::mat4(), translateVec);
    // Build the model matrix -get from object
    transform = transMat * rotMat * scaleMat;
    
}
void Object::setScale(float scale){
    scaleMat = glm::scale(glm::mat4(), glm::vec3(scale));
    // Build the model matrix -get from object
    transform = transMat * rotMat * scaleMat;
    
}
void Object::bindShaders(){
    // Use our shader
    shader->bind();
}

void Object::unBindShader(){
    
}

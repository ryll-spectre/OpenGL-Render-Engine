


//!  Camera.
/*!
 Contains decriptions for a setting up a render camera.
 */

#include "Camera.hpp"


Camera::Camera(){
    
    m_position = glm::vec3( 0, 0, -1 );
    m_horizontalAngle = 3.14f;
    m_verticalAngle = 0.0f;
    m_foV = 45.0f;
    m_lookat =glm::vec3( 0, 0, 0.0 );
    m_up =glm::vec3( 0, 1, 0.0 );
    m_projectionMatrix = glm::perspective(m_foV, 4.0f / 3.0f, 0.1f, 1000.0f);
    m_viewMatrix = glm::lookAt(
                               m_position, // Camera is here
                               glm::vec3( 0, 0, 0.0 ), // and looks here
                               glm::vec3( 0, 1, 0 )  // Head is up (set to 0,-1,0 to look upside-down)
                               );
    
}
//! Constructor
/*! Setting up camera with certain parameters. */
Camera::Camera(glm::mat4 projectionMat, glm::mat4 viewMat){
    m_projectionMatrix = projectionMat;
    m_viewMatrix=viewMat;
}
//! Access viewprojection matrix
/*!  Access viewprojection matrix. */
glm::mat4 Camera::getViewProjectionMatrix(){
    
    return m_projectionMatrix * m_viewMatrix;
}
//! Access view matrix
/*!  Access view matrix. */
glm::mat4 Camera::getViewMatrix(){
    
    return m_viewMatrix;
}
//! Access projection matrix
/*!  Access projection matrix. */
glm::mat4 Camera::getProjectionatrix(){
    
    return m_projectionMatrix;
}

//! Access camera position
/*!  Access camera position. Retruns a vec3 */
glm::vec3 Camera::getPosition(){
    return m_position;
    
}

//! Set camera orientation
/*!  Set camera orientation based on vertical and horizontal angle */
void Camera::setCameraOrientation(float vertAngle, float horzAngle){
    
    m_verticalAngle = vertAngle;
    m_horizontalAngle = horzAngle;
    updateAngles();
}
//! Set lookat vector
/*!  Set lookat vector only. */
void Camera::setLookAt(glm::vec3 lookAt){
    m_lookat=lookAt;
    m_viewMatrix       = glm::lookAt(
                                     m_position,           // Camera is here
                                     m_lookat, // and looks here : at the same position, plus "direction"
                                     m_up                  // Head is up (set to 0,-1,0 to look upside-down)
                                     );
}
//! Set lookat vector
/*!  Set lookat configuration by setting position, lookat vector and up vector. */
void Camera::setLookAt(glm::vec3 pos,glm::vec3 lookAt, glm::vec3 up){
    m_position=pos;
    m_lookat=lookAt;
    m_up=up;
    m_viewMatrix       = glm::lookAt(
                                     m_position,           // Camera is here
                                     m_lookat, // and looks here : at the same position, plus "direction"
                                     m_up                  // Head is up (set to 0,-1,0 to look upside-down)
                                     );
}
//! Set position
/*!  Set position. */
void Camera::setPosition(glm::vec3 pos){
    m_position=pos;
    m_viewMatrix       = glm::lookAt(
                                     m_position,           // Camera is here
                                     m_lookat, // and looks here : at the same position, plus "direction"
                                     m_up                  // Head is up (set to 0,-1,0 to look upside-down)
                                     );
}

//! Update angles.
/*!  Set after setting the angles the camera settings neeed to be updated. */
void Camera::updateAngles(){
    
    // Direction : Spherical coordinates to Cartesian coordinates conversion
    glm::vec3 direction(
                        cos(m_verticalAngle) * sin(m_horizontalAngle),
                        sin(m_verticalAngle),
                        cos(m_verticalAngle) * cos(m_horizontalAngle)
                        );
    
    // Right vector
    glm::vec3 right = glm::vec3(
                                sin(m_horizontalAngle - 3.14f/2.0f),
                                0,
                                cos(m_horizontalAngle - 3.14f/2.0f)
                                );
    
    // Up vector
    m_up = glm::cross( right, direction );
    m_lookat =m_position+direction;
    
    m_viewMatrix       = glm::lookAt(
                                     m_position,           // Camera is here
                                     m_lookat, // and looks here : at the same position, plus "direction"
                                     m_up                  // Head is up (set to 0,-1,0 to look upside-down)
                                     );
    
    
}

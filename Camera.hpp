/*
 * Camera.hpp
 *
 * by Stefanie Zollmann
 *
 * Camera class.
 *
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//!  Camera.
/*!
 Contains decriptions for a setting up a render camera.
 */

class Camera{
    
public:
    //! Default constructor
    /*! Setting up default camera. */
    Camera();
    //! Constructor
    /*! Setting up camera with certain parameters. */
    Camera(glm::mat4 projectionMat, glm::mat4 viewMat);
    //! Access viewprojection matrix
    /*!  Access viewprojection matrix. */
    glm::mat4 getViewProjectionMatrix();
    //! getViewMatrix
    /*!  Access view matrix. */
    glm::mat4 getViewMatrix();
    //! getProjectionatrix
    /*!  Access projection matrix. */
    glm::mat4 getProjectionatrix();
    
    //! Access camera position
    /*!  Access camera position. Retruns a vec3 */
    glm::vec3 getPosition();
    
    //! Set camera orientation
    /*!  Set camera orientation based on vertical and horizontal angle */
    void setCameraOrientation(float vertAngle, float horzAngle);
    //! Set lookat vector
    /*!  Set lookat vector only. */
    void setLookAt(glm::vec3 lookAt);
    //! Set lookat vector
    /*!  Set lookat configuration by setting position, lookat vector and up vector. */
    void setLookAt(glm::vec3 pos,glm::vec3 lookAt, glm::vec3 up);
    //! Set position
    /*!  Set position. */
    void setPosition(glm::vec3 pos);
    
    //! Update angles.
    /*!  Set after setting the angles the camera settings neeed to be updated. */
    void updateAngles();
    
    
private:
    glm::mat4 m_projectionMatrix;   //!< Contains only projectionMatrix
    glm::mat4 m_viewMatrix;         //!< Contains only viewMatrix
    
    // camera pose parameters
    // Initial position : on +Z
    glm::vec3 m_position;           //!< Position of camera
    glm::vec3 m_lookat;             //!< Lookat vector of camera
    glm::vec3 m_up;                 //!< Up vector of camera
    
    //orienation of the camera
    float m_horizontalAngle;        //!< Initial horizontal angle : toward -Z
    float m_verticalAngle;          //!< Initial vertical angle : none
    
    // camera intrinsics
    float m_foV;                    //!< Field of View
    
    
};



#endif


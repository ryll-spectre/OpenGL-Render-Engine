/*
 * Controls.hpp
 *
 * Setting controls for interacting using mouse and keyboard with the rendering.
 * Adjusted to work with the camera class
 * by Stefanie Zollmann
 *
 *
 */


#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include "Camera.hpp"


class Controls{
	
public:
	Controls(){};
	Controls(Camera* cam);
    //! Update controls
    /*! Update controls based on mouse and keyboard input. */
	void update();
    //! Set Speed
    /*! How fast should the mouse move be. */
    void setSpeed(float sp){keyspeed = sp;}
	
private:
	
	Camera* m_camera;           //!< controls have a reference to camera to manipulate
	float keyspeed;             //!< X units / second for keyboard
	float mouseSpeed;           //!< X units / second for mouse
	
	float horizontalAngle;      //!< Stores internal horizontal angle
	float verticalAngle;        //!< Stores internal vertical angle
};
#endif

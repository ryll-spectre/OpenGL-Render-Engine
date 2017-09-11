/*
 * Quad.hpp
 *
 *  Class for a simple quad.
 *  by Stefanie Zollmann
 *
 */
#ifndef QUAD_HPP
#define QUAD_HPP

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>

#include "Object.hpp"

//!  Quad.
/*!
 Basic quad class that represents a quad and defines it rendering
 */
class Quad:  public Object{
    
    public:
        //! Default constructor
        /*! Setting up default quad. */
        Quad();
        //! Destructor
        /*! Delete quad. */
        ~Quad();
        //! init
        /*! Setting up default quad. */
        void init();
        //! render
        /*! Render default quad. */
        void render(Camera* camera);
        //! directRender
        /*! Direct rendering function that doesnt take camera into account. */
        void directRender();
    
    
    private:
        
        GLfloat g_vertex_buffer_data[18];
        GLuint vertexbuffer;
    
};





#endif

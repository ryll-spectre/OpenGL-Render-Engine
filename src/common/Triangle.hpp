#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP


#include "Object.hpp"
// Include GLEW
#include <GL/glew.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
class Triangle:  public Object{
    
    public:
    
        //! Default constructor
        /*! Setting up default triangle. */
        Triangle();
        //! Destructor
        /*! Delete triangle. */
        ~Triangle();
        //! init
        /*! Setting up default triangle. */
        void init();
        //! render
        /*! Render default quad. */
        void render(Camera* camera);

    private:
    
        GLfloat g_vertex_buffer_data[9];
        GLuint vertexbuffer;
    
};

#endif

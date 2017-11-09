/*
 * Shader.hpp
 *
 *  Class for representing shader implementation. Contains all the required function calls like create shaders, compile shaders.
 *  by Stefanie Zollmann
 *
 */

#ifndef SHADER_HPP
#define SHADER_HPP

// Include standard headers
#include <string>
// Include GLEW
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


//!  Shader.
/*!
 Shader implementation. Contains all the required function calls like create shaders, compile shaders.
 */
class Shader{
	
public:
    //! Default constructor
    /*! Does nothing at the moment */
	Shader(){
		
	}
    //! Constructor with shader source specification
    /*! Creates the shaders from source, creates vertex and fragment shader at the same time. 
        Uses different source file naming conventions*/
	Shader(std::string vertexshaderName, std::string fragmentshaderName){
		initShaders(vertexshaderName,fragmentshaderName);
		
	}
    //! Constructor with shader source specification
    /*! Creates the shaders from source, creates vertex and fragment shader at the same time. 
     Assumes that fragment and vertex shader have the same names*/
	Shader(std::string shaderName){
		initShaders(shaderName+".vert",shaderName+".frag");
		
	}
    
    //! Destructor
    /*! Virtual - write own destructor for each shader implementation*/
    
	virtual ~Shader();
	
    //! LoadShaders
    /*! Does the actual shader loading and compiling*/
	GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
    //! initShaders
    /*! init shaders*/
	void initShaders(std::string vertexshaderName, std::string fragmentshaderName);
	
    //! updateMatrices
    /*! Updates the values for the model-view projection matrix and the model and view matrix separately*/
	void updateMatrices(glm::mat4 MVP,glm::mat4 M,glm::mat4 V);
	
    //! updateMVP
    /*! Updates the values for the model-view projection matrix*/
	void updateMVP(glm::mat4 MVP);
	
    //! bind
    /*! Shader binding, virtual */
	virtual void bind();
    
protected:
	GLuint programID;
	GLuint m_MVPID;     //!<   all shader should get information about the MVP matrix
	GLuint m_VID;       //!<   all shader should get information about the view matrix
	GLuint m_MID;       //!<   all shader should get information about the model matrix
};



#endif

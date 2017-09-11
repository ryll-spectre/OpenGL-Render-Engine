/*
 *  PostProcessingShader.hpp
 *
 *  Class for creating postprocessing vertex and fragment shader. It takes a timestamp to change the effect of the post effect.
 *  by Stefanie Zollmann
 *
 */
#ifndef PASSTHROUGHSHADER_HPP
#define PASSTHROUGHSHADER_HPP

#include "Shader.hpp"
//!  PostProcessingShader.
/*!
* Class for creating postprocessing vertex and fragment shader. 
* It takes a timestamp to change the effect of the post effect.
*/
class PostProcessingShader: public Shader{
    public:
        //! Default constructor
        /*! Does nothing - don't use. */
        PostProcessingShader();
        //! PostProcessingShader constructor
        /*! Version of constructor that allows for  vertex and fragment shader with different names. */
        PostProcessingShader(std::string vertexshaderName, std::string fragmentshaderName);
        //! PostProcessingShader constructor
        /*! Version of constructor that assumes that vertex and fragment shader have same name*/
        PostProcessingShader(std::string shaderName);
        //! Destructor
        /*! Clean up ressources*/
        ~PostProcessingShader();
        //! setTime
        /*! Set time to vary effect. */
        void setTime(float t);
        //! bindShader
        /*! Bind the texture. */
        void bindTexture();
        //! bindShader
        /*! Bind the shader. */
        void bindShader();
	
	private:
        GLuint timeID;
        GLuint m_TextureID;

	
};


#endif

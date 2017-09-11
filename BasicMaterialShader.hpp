/*
 * BasicMaterialShader
 *
 * Class for a shader supporting a basic phong shading
 * by Stefanie Zollmann
 *
 *
 */
#ifndef BASICMATERIALSHADER_HPP
#define BASICMATERIALSHADER_HPP

#include "Shader.hpp"
#include "Texture.hpp"

//!  BasicMaterialShader.
/*!
 Class for a shader supporting a basic phong shading
 */
class BasicMaterialShader: public Shader{
    public:
    //! Default constructor
    /*! Does nothing - don't use. */
    BasicMaterialShader();
    //! BasicMaterialShader constructor
    /*! Version of constructor that allows for  vertex and fragment shader with different names. */
    BasicMaterialShader(std::string vertexshaderName, std::string fragmentshaderName);
    //! BasicMaterialShader constructor
    /*! Version of constructor that assumes that vertex and fragment shader have same name*/
    BasicMaterialShader(std::string shaderName);
    //! Destructor
    /*! Clean up ressources*/
    ~BasicMaterialShader();
    //! init
    /*! Init shader*/
    void init();
    //! setTexture
    /*! Set a reference to the texture. */
    void setTexture(Texture* texture);
    //! setLightPos
    /*! Set the light's position. */
    void setLightPos(glm::vec3 lightPos);
    //! bind
    /*! Bind the shader. */
    void bind();
   
    
    private:
        Texture* m_texture;
        glm::vec3 m_lightPos;
        GLuint m_TextureID;
        GLuint m_lightPosID;
    
};


#endif

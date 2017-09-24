#ifndef TEXTURESHADER_HPP
#define TEXTURESHADER_HPP

#include "Shader.hpp"
#include "Texture.hpp"
//!  TextureShader.
/*!
Shader for textures. Has a reference to a texture that will be passed to the shader
 */
class TextureShader: public Shader{
    public:
    
    //! Default constructor
    /*! Does nothing at the moment. */
    TextureShader();
    //
    //! TextureShader
    /*! Version of constructor that allows for  vertex and fragment shader with differnt names. */
    TextureShader(std::string vertexshaderName, std::string fragmentshaderName);
    //! TextureShader
    /*! Version of constructor that assumes that vertex and fragment shader have same name. */
    TextureShader(std::string shaderName);
    //! Destructor
    /*! Clean up ressources. */
    
    ~TextureShader();
    //! setTexture
    /*! Set a refernece to the texture. */
    void setTexture(Texture* texture);
    //! bind
    /*! Bind the shader. */
    void bind();
    

    private:
        glm::vec4 color;
        Texture* m_texture;
        GLuint m_TextureID;
    
    
};


#endif

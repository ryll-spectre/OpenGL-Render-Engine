
#include "TextureShader.hpp"

TextureShader::TextureShader(){
        
    }
// version of constructor that allows for  vertex and fragment shader with differnt names
TextureShader::TextureShader(std::string vertexshaderName, std::string fragmentshaderName): Shader(vertexshaderName, fragmentshaderName){
    
    m_TextureID  = glGetUniformLocation(programID, "myTextureSampler");
    
    
}

// version of constructor that assumes that vertex and fragment shader have same name
TextureShader::TextureShader(std::string shaderName): Shader(shaderName){
    
    m_TextureID  = glGetUniformLocation(programID, "myTextureSampler");
    
}

TextureShader::~TextureShader(){
    glDeleteTextures(1, &m_TextureID);

}

void TextureShader::setTexture(Texture* texture){
    m_texture = texture;
    // Get a handle for our "myTextureSampler" uniform
    m_TextureID  = glGetUniformLocation(programID, "myTextureSampler");

}

void TextureShader::bind(){
    // Use our shader
    glUseProgram(programID);
    // Bind our texture in Texture Unit 0
    m_texture->bindTexture();
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(m_TextureID, 0);
    
}


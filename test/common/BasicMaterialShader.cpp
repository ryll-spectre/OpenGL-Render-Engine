
#include "BasicMaterialShader.hpp"

BasicMaterialShader::BasicMaterialShader(){
    
}


// version of constructor that allows for  vertex and fragment shader with different names
BasicMaterialShader::BasicMaterialShader(std::string vertexshaderName, std::string fragmentshaderName): Shader(vertexshaderName, fragmentshaderName){
        init();
    }
    
// version of constructor that assumes that vertex and fragment shader have same name
BasicMaterialShader::BasicMaterialShader(std::string shaderName): Shader(shaderName){
    init();
}

void BasicMaterialShader::init(){
    glUseProgram(programID);
    m_lightPos = glm::vec3(4,4,4);
    m_lightPosID = glGetUniformLocation(programID, "lightPosWorldspace");
    glUniform3f(m_lightPosID, m_lightPos.x, m_lightPos.y, m_lightPos.z);
    m_TextureID  = glGetUniformLocation(programID, "myTextureSampler");
}

BasicMaterialShader::~BasicMaterialShader(){
    glDeleteTextures(1, &m_TextureID);

}

void BasicMaterialShader::setTexture(Texture* texture){
    m_texture = texture;
    // Get a handle for our "myTextureSampler" uniform
    m_TextureID  = glGetUniformLocation(programID, "myTextureSampler");

}

void BasicMaterialShader::setLightPos(glm::vec3 lightPos){
    m_lightPos= lightPos;
    glUniform3f(m_lightPosID, lightPos.x, lightPos.y, lightPos.z);
}


void BasicMaterialShader::bind(){
    // Use our shader
    glUseProgram(programID);
    // Bind our texture in Texture Unit 0
    m_texture->bindTexture();
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(m_TextureID, 0);
    
}



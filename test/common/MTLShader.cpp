
#include "MTLShader.hpp"
// complete the setters with the appropriate method for passing information to the shaders


MTLShader::MTLShader(){
        
}

// version of constructor that allows for  vertex and fragment shader with differnt names
    
MTLShader::MTLShader(std::string vertexshaderName, std::string fragmentshaderName): Shader(vertexshaderName, fragmentshaderName){
    
    setUpShaderParameters();
    
}

// version of constructor that assumes that vertex and fragment shader have same name
MTLShader::MTLShader(std::string shaderName): Shader(shaderName){
    
    setUpShaderParameters();
    
}

MTLShader::~MTLShader(){
    glDeleteTextures(1, &m_TextureID);

}

void MTLShader::setUpShaderParameters(){
	m_diffuseColor = glm::vec4(1.0);
    GLint diffusecolorID = glGetUniformLocation(programID, "diffColorMat");
    glProgramUniform4fv(programID,diffusecolorID,1, &m_diffuseColor[0]);
    m_texture =NULL;
}

void MTLShader::setTexture(Texture* texture){
    m_texture = texture;
    //DONE: Get a handle for our "myTextureSampler" uniform
	m_TextureID  = glGetUniformLocation(programID, "myTextureSampler");
}


void MTLShader::setLightPos(glm::vec3 lightPos){
    
    m_lightPos= lightPos;
	
}

void MTLShader::setDiffuse(glm::vec3 diffuse){
    
    m_diffuseColor= glm::vec4(diffuse[0],diffuse[1],diffuse[2], 1.0);;
    GLint diffusecolorID = glGetUniformLocation(programID, "diffColorMat");
    glProgramUniform4fv(programID,diffusecolorID,1, &m_diffuseColor[0]);
}
void MTLShader::setAmbient(glm::vec3 ambient){
    
    m_ambientColor= glm::vec4(ambient[0],ambient[1],ambient[2], 1.0);
	GLint ambientcolorID = glGetUniformLocation(programID, "ambColorMat"); // ADDED
    glProgramUniform4fv(programID,ambientcolorID,1, &m_ambientColor[0]); // ADDED
}
void MTLShader::setSpecular(glm::vec3 specular){
    
    m_specularColor= glm::vec4(specular[0],specular[1],specular[2], 1.0);
	GLint specularcolorID = glGetUniformLocation(programID, "specColorMat"); // ADDED
    glProgramUniform4fv(programID,specularcolorID,1, &m_specularColor[0]); // ADDED
}

void MTLShader::setOpacity(float opacity){
    
    m_opacity= opacity;
    GLint opacityID = glGetUniformLocation(programID, "opacity"); // ADDED
    glProgramUniform1f(programID,opacityID, m_opacity); // ADDED
}

void MTLShader::setRenderMode(float renderMode){
    m_renderMode= renderMode;
    GLint renderID = glGetUniformLocation(programID, "renderMode");
    glProgramUniform1f(programID, renderID, m_renderMode);
}


void MTLShader::bind(){
    // Use our shader
    glUseProgram(programID);
    // Bind our texture in Texture Unit 0
    if(m_texture!=NULL){
        m_texture->bindTexture();
        // DONE: Set our "myTextureSampler" sampler to user Texture Unit 0 using glUniform1i
		glUniform1i(m_TextureID, 0);
    }
    
}

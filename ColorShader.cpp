
#include "ColorShader.hpp"

ColorShader::ColorShader(){
    
}
// version of constructor that allows for  vertex and fragment shader with differnt names

ColorShader::ColorShader(std::string vertexshaderName, std::string fragmentshaderName): Shader(vertexshaderName, fragmentshaderName){
    
    // add color parameter to shader
    GLint colorID = glGetUniformLocation(programID, "colorValue");
    color = glm::vec4(1.0,1.0,1.0,1.0);
    glUniform4f(colorID, color[0],color[1],color[2],color[3]);
    
}

// version of constructor that assumes that vertex and fragment shader have same name
ColorShader::ColorShader(std::string shaderName): Shader(shaderName){
    
    // add color parameter to shader
    GLint colorID = glGetUniformLocation(programID, "colorValue");
    color = glm::vec4(1.0,1.0,1.0,1.0);
    glProgramUniform4fv(programID,colorID,1, &color[0]);
    
}


void ColorShader::setColor(glm::vec4 newcolor){
    color = newcolor;
    // Send our colour value to the currently bound shader,
    GLint colorID = glGetUniformLocation(programID, "colorValue");
    glProgramUniform4fv(programID,colorID,1, &color[0]);
}

/*
 * ColorShader.hpp
 *
 * by Stefanie Zollmann
 *
 * ColorShader class.
 *
 */

#ifndef COLORSHADER_HPP
#define COLORSHADER_HPP

#include "Shader.hpp"
class ColorShader: public Shader{
    public:
        ColorShader();
        // version of constructor that allows for  vertex and fragment shader with differnt names

        ColorShader(std::string vertexshaderName, std::string fragmentshaderName);

        // version of constructor that assumes that vertex and fragment shader have same name
        ColorShader(std::string shaderName);

        //set Colour value
        void setColor(glm::vec4 newcolor);
    
    private:
        glm::vec4 color;
    
    
};


#endif

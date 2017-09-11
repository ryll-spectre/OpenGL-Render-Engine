
#include "Material.hpp"


    Material::Material(){
		m_shader = NULL;
    }

	Material::~Material(){
		
	}

    //setter
    void Material::setTextureName(const char* name){
        m_textureName = std::string(name);
    }
    void Material::setDiffuseColour(glm::vec3 diffC){
        m_colorDiffuse = diffC;
    }
    
    void Material::setAmbientColour(glm::vec3 ambC){
        m_colorAmbient = ambC;
    }

    void Material::setSpecularColour(glm::vec3 specC){
        m_colorSpecular = specC;
    }
    
    void Material::setOpacity(float opacity){
        m_opacity = opacity;
    }
    void Material::setShininess(float shininess){
        m_shininess = shininess;
    }
    
    //getter
    glm::vec3 Material::getDiffuseColour(){
        return m_colorDiffuse;
    }
    glm::vec3 Material::getAmientColour(){
        return m_colorAmbient;
    }
    glm::vec3 Material::getSpecularColour(){
        return m_colorSpecular;
    }
    
    float Material::getOpacity(){
        return m_opacity;
    };
    
    
	void Material::setShader(Shader* shader){
		m_shader = shader;
		
	}
	Shader*  Material::getShader(){
		return m_shader;
		
	}
	
	bool Material::shaderIsInitialized(){
		return (m_shader!=NULL);
	}
	
		
    std::string Material::getTextureName(){
        return m_textureName;
    }
 

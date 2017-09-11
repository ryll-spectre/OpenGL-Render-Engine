
#include "Group.hpp"


    // default triangle
Group::Group(){
        init();
    
    };
Group::~Group(){
        
        
    };
    
void Group::addMesh(Mesh* mesh){
        meshes.push_back(mesh);
    
    }
void Group::addMaterial(Material* mat){
        materials.push_back(mat);
        
    }
    
Mesh* Group::getMesh(int index){
        return meshes[index];
    
    }
Material* Group::getMaterial(int index){
        return materials[index];
    }
    
int Group::getNumMeshes(){
    return meshes.size();

}
void Group::setRenderMode(float rendermode){
    for (int i=0;i<materials.size();i++)
        {
            MTLShader* shader = static_cast<MTLShader*>(materials[i]->getShader());
            if(shader!=NULL)
                shader->setRenderMode(rendermode); // Setting renderMode in MTLShader
        }
    
}

void Group::init(){
    setupShaders();
    
}
void Group::render(Camera* camera){
   //DONE: Make sure all meshes are rendered - at the moment only the first one is rendered
    if(meshes.size()>0){
        for(int meshInd = 0; meshInd < meshes.size(); meshInd++)
        {
            meshes[meshInd]->bindShaders();
            meshes[meshInd]->render(camera);
        }
        
    }
    
}

void Group::setupShaders(){
	//DONE: Do this for all meshes
	if(meshes.size()>0) // check to see if we have meshes
    {
        // get right material index for mesh - getMaterialIndex
        for(int i = 0; i < meshes.size(); i++) // go through all meshes
        {
            // DONE: get the correct material index from obj file
            Material* mat = getMaterial(meshes[i]->getMatIndex());
            Shader* shader = NULL;
            if(!mat->shaderIsInitialized()) // if shader is not initialized
            {
                MTLShader* mtlshader = new MTLShader( "mtlShader"); // set properties for shader
                mtlshader->setDiffuse(mat->getDiffuseColour());
                mtlshader->setAmbient(mat->getAmientColour());
                mtlshader->setSpecular(mat->getSpecularColour());
                mtlshader->setOpacity(mat->getOpacity());
                mat->setShader(mtlshader);
                if(mat->getTextureName()!="")
                {
                    Texture* texture = new Texture(mat->getTextureName());
                    mtlshader->setTexture(texture);
                }

                shader = mtlshader;
            }
            else 
            {
                shader = mat->getShader();
            }
            meshes[i]->setShader(shader); 
        }      
    }
}

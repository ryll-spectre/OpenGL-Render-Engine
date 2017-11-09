#ifndef GROUP_HPP
#define GROUP_HPP


#include "Object.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
// Include GLEW
#include <GL/glew.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
#include "MTLShader.hpp"
#include "Material.hpp"


// Object that can have multiple meshes and materials
class Group:  public Object{
    
    public:
        //!Default constructor
        /*! Setup shaders for this group. */
        Group();
        //! Destructor
        /*! Clean up ressources */
        ~Group();
        //! addGeometry
        /*! Add a new mesh. */
        void addMesh(Mesh* mesh);
        //! addMaterial
        /*! Add a new material. */
        void addMaterial(Material* mat);
        //! getMesh
        /*! Access a mesh using an index. */
        Mesh* getMesh(int index);
        //! getMaterial
        /*! Get materials using an index. */
        Material* getMaterial(int index);
        //! getNumMeshes
        /*! Get number of meshes. */
        int getNumMeshes();
        //! SetRenderMode
        /*! Set a render mode. */
        void setRenderMode(float rendermode);
        //! init
        /*! Initialise group. */
        void init();
        //! render
        /*! Render group. */
        void render(Camera* camera);
        //! SetupShaders
        /*! Setup all shaders. */
        void setupShaders();
    
    private:
    
        std::vector<Mesh*> meshes;          //!< all meshes of this group
        std::vector<Material*> materials;   //!< collection of all materials

    
};

#endif

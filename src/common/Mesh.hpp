/*
 * Mesh.hpp
 *
 * Mesh class can have vertices, texture coordinates, normals, and later on face indices
 * can be used for creating simple geometries but also more complex ones from model loader
 * by Stefanie Zollmann
 *
 */

#ifndef MESH_HPP
#define MESH_HPP

#include "Object.hpp"
// Include GLEW
#include <GL/glew.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>

//!  Mesh.
/*!
Mesh class can have vertices, texture coordinates, normals, and later on face indices.
 */
class Mesh:  public Object{
    
    public:
        //! Default constructor
        /*! Setting up mesh object. */
        Mesh(){};
        //! Destructor
        /*! Deleting ressources. */
        ~Mesh();
        //! setVertices
        /*! Set vertices using a std::vector with floats. */
        void setVertices(std::vector<float> verts);
        //! setVertices
        /*! Set vertices using a std::vector with glm::vec3. */
        void setVertices(std::vector<glm::vec3> verts);
        //! setUVs
        /*! Set texture coordinates using a std::vector with glm::vec2. */
        void setUVs(std::vector<glm::vec2> uvs);
        //! setUVs
        /*! Set texture coordinates using a std::vector with floats. */
        void setUVs(std::vector<float> uvs);
        //! setNormals
        /*! Set normals using a std::vector with glm::vec3. */
        void setNormals(std::vector<glm::vec3> normals);
        //! setIndices
        /*! Set indices to create primitives using a std::vector of unsigned short. */
        void setIndices(std::vector<unsigned short> indices);
        //! render
        /*! Do the actual rendering of the mesh. */
        void render(Camera* camera);
        //! setMatIndex
        /*! Set material index for this mesh. This is for reusing materials between multiple meshes */
        void setMatIndex(int index){matIndex = index;};
        //! getMatIndex
        /*! Get material index for this mesh. This is for reusing materials between multiple meshes */
        int  getMatIndex(){return matIndex;}
        
    private:
        std::vector<glm::vec3> m_vertices;  //!<  vertices, for more flexibility we use a std vector here
        std::vector<glm::vec2> m_uvs;       //!<  texture coordinates
        std::vector<glm::vec3> m_normals;   //!<  normals
        std::vector<unsigned short> m_indices;  //!<  face indices
        
        GLuint m_vertexBufferID;            //!<  vertex buffer id
        GLuint m_uvBufferID;                //!<  texture coordinates buffer id
        GLuint m_normalBufferID;            //!<  normal buffer id
        GLuint m_indexBufferID;             //!<  index buffer id
        int matIndex;
    
};

#endif

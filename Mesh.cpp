
#include "Mesh.hpp"


Mesh::~Mesh(){// Cleanup VBO and shader
    glDeleteBuffers(1, &m_vertexBufferID);
    glDeleteBuffers(1, &m_uvBufferID);
    glDeleteBuffers(1, &m_normalBufferID);
    glDeleteBuffers(1, &m_indexBufferID);
}
void Mesh::setVertices(std::vector<float> verts){
    m_vertices.clear();
    for(int i=0; i<verts.size()/3;i++){
        m_vertices.push_back(glm::vec3(verts[i*3+0],verts[i*3+1],verts[i*3+2]));
    }
    // Load it into a VBO
    glGenBuffers(1, &m_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(glm::vec3), &m_vertices[0], GL_STATIC_DRAW);
    
    
}
void Mesh::setVertices(std::vector<glm::vec3> verts){
    m_vertices.clear();
	m_vertices.resize(verts.size());
	std::copy(verts.begin(), verts.end(), m_vertices.begin());
	
    // Load it into a VBO
    glGenBuffers(1, &m_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(glm::vec3), &m_vertices[0], GL_STATIC_DRAW);
    
    
}
void Mesh::setUVs(std::vector<glm::vec2> uvs){
	m_uvs.clear();
	m_uvs.resize(uvs.size());
	std::copy(uvs.begin(), uvs.end(), m_uvs.begin());
	
    glGenBuffers(1, &m_uvBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, m_uvBufferID);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &m_uvs[0], GL_STATIC_DRAW);
    
    
}
void Mesh::setUVs(std::vector<float> uvs){
    m_uvs.clear();
    for(int i=0; i<uvs.size()/2;i++){
        m_uvs.push_back(glm::vec2(uvs[i*2+0],uvs[i*2+1]));
    }
    glGenBuffers(1, &m_uvBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, m_uvBufferID);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &m_uvs[0], GL_STATIC_DRAW);
    
    
}


void Mesh::setNormals(std::vector<glm::vec3> normals){
	m_normals.clear();
	m_normals.resize(normals.size());
	
	std::copy(normals.begin(), normals.end(), m_normals.begin());
    
    glGenBuffers(1, &m_normalBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, m_normalBufferID);
    glBufferData(GL_ARRAY_BUFFER, m_normals.size() * sizeof(glm::vec3), &m_normals[0], GL_STATIC_DRAW);
    
}
void Mesh::setIndices(std::vector<unsigned short> indices){
	
	m_indices.clear();
	m_indices.resize(indices.size());
	
	std::copy(indices.begin(), indices.end(), m_indices.begin());
    
    // Generate a buffer for the indices as well
    glGenBuffers(1, &m_indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0] , GL_STATIC_DRAW);
    
    
    
}
void Mesh::render(Camera* camera){
    bindShaders();
    // Build the model matrix -get from object
    glm::mat4 modelMatrix = this->getTransform();
    glm::mat4 MVP = camera->getViewProjectionMatrix() * modelMatrix;
	glm::mat4 viewMatrix = camera->getViewMatrix();
	
    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
	// we will set the model matrix and the view matrix as well
	// we could calculate this in the shader, but it is faster to compute this once in advance
    shader->updateMatrices(MVP, modelMatrix, viewMatrix);
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
    glVertexAttribPointer(
                          0,                  // attribute
                          3,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );
    
    if(m_uvs.size()!=0){
        // 2nd attribute buffer : UVs
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, m_uvBufferID);
        glVertexAttribPointer(
                              1,                                // attribute
                              2,                                // size
                              GL_FLOAT,                         // type
                              GL_FALSE,                         // normalized?
                              0,                                // stride
                              (void*)0                          // array buffer offset
                              );
    }
    if(m_normals.size()!=0){
        // 3rd attribute buffer : normals
        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, m_normalBufferID);
        glVertexAttribPointer(
                              2,                                // attribute
                              3,                                // size
                              GL_FLOAT,                         // type
                              GL_FALSE,                         // normalized?
                              0,                                // stride
                              (void*)0                          // array buffer offset
                              );
		
    }
    
    // Draw unindexed data
    if(m_indices.size()==0){
        //first parameter :mode specifies what kind of primitives to render. Symbolic constants GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, and GL_TRIANGLES are accepted.
        //second parameter :first specifies the starting index in the enabled arrays.
        //third parameter :count specifies the number of indices to be rendered.
        glDrawArrays(GL_TRIANGLES, 0, m_vertices.size()); //draw x triangles
        
    }
    else{ //draw indexed data
        // Index buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferID);
        // Draw the triangles !
        glDrawElements(
                       GL_TRIANGLES,      // mode
                       m_indices.size(),    // count
                       GL_UNSIGNED_SHORT,   // type
                       (void*)0           // element array buffer offset
                       );
        
    }
    glDisableVertexAttribArray(0);
    if(m_uvs.size()!=0)
		glDisableVertexAttribArray(1);
    
    if(m_normals.size()!=0)
		glDisableVertexAttribArray(2);
    
}

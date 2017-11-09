#include "Triangle.hpp"


// default triangle
Triangle::Triangle(){
    init();
}
Triangle::~Triangle(){// Cleanup VBO
        glDeleteBuffers(1, &vertexbuffer);
        
    }
void Triangle::init(){
    //x,y,z
    g_vertex_buffer_data[0] = -1.0f, g_vertex_buffer_data[1]=  -1.0f, g_vertex_buffer_data[2]=0.0f;
    g_vertex_buffer_data[3] = 1.0f, g_vertex_buffer_data[4]=  -1.0f, g_vertex_buffer_data[5]=0.0f;
    g_vertex_buffer_data[6] = 0.0f, g_vertex_buffer_data[7]=  1.0f, g_vertex_buffer_data[8]=0.0f;
    
    
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    
}
void Triangle::render(Camera* camera){
    bindShaders();
    // Build the model matrix -get from object
    glm::mat4 ModelMatrix = this->getTransform();
    glm::mat4 MVP = camera->getViewProjectionMatrix() * ModelMatrix;
    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    shader->updateMVP(MVP);
    
    
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
                          0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                          3,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );
    
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
    
    glDisableVertexAttribArray(0);
}

    

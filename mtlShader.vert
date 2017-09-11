#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal_modelspace;

// Output data ; will be interpolated for each fragment.
out vec2 UV;
out vec3 posWorldspace;
out vec3 normalCameraspace;
out vec3 eyeDirectionCameraspace;
out vec3 lightDirectionCameraspace;


// Values that stay constant for the whole mesh.
uniform mat4 MVP; // model view projection matrix
uniform mat4 V; // view matrix
uniform mat4 M; // Model matrix
uniform vec3 lightPosWorldspace;


void main(){
	
	// Output position of the vertex, in clip space : MVP * position
	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
    
    // Position of the vertex, in worldspace : M * position
	posWorldspace = (M * vec4(vertexPosition_modelspace,1)).xyz;
    
    // Vector that goes from the vertex to the camera, in camera space.
	vec3 vertexPosCameraspace = ( V * M * vec4(vertexPosition_modelspace,1)).xyz;
	eyeDirectionCameraspace = vec3(0,0,0) - vertexPosCameraspace;
    
    // Vector that goes from the vertex to the light, in camera space.
	vec3 lightPositionCameraspace = ( V * vec4(lightPosWorldspace,1)).xyz;
	lightDirectionCameraspace = lightPositionCameraspace + eyeDirectionCameraspace;
    
    // Normal of the the vertex, in camera space
	normalCameraspace = ( V * M * vec4(vertexNormal_modelspace,0)).xyz; 

	// UV of the vertex
	UV = vertexUV;
}


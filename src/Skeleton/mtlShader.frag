#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;
in vec3 posWorldspace;
in vec3 normalCameraspace; //normal in camera space
in vec3 eyeDirectionCameraspace; // eye direction in camera space
in vec3 lightDirectionCameraspace; // light direction in camera space


// Ouput data
out vec4 color;

// Values that stay constant for the whole mesh (light emission properties)
uniform float opacity; 
uniform float exponent; 
uniform sampler2D myTextureSampler;
uniform float renderMode; 
// material color properties from MTLShader.cpp - take rgb component
uniform vec4 diffColorMat; 
uniform vec4 ambColorMat;
uniform vec4 specColorMat;

// Hard coded diffuse, ambient, and specular color
const vec3 diffuseColor = vec3(1.0,1.0,1.0);
const vec3 ambientColor = vec3(0.4,0.4,0.4); // ADDED
const vec3 specularColor = vec3(1.0,1.0,1.0); // ADDED

void main(){

	vec3 textureVal = texture( myTextureSampler, UV ).rgb;  //texture map will be used for diffuse and ambient texture map
	
	vec3 N = normalize(normalCameraspace); // normal of the computed fragment
    vec3 L = normalize(lightDirectionCameraspace); // direction of light in cameraspace

    // We use the cosine of the angle theta between the normal and the light direction to compute the diffuse component.
	// The cosine is clamped to contrain it between 0 and 1
    float cosTheta = clamp( dot( N,L), 0,1 );

    // Eye vector (towards the camera)
	vec3 E = normalize(eyeDirectionCameraspace);
	// Direction in which the triangle reflects the light
	vec3 R = reflect(-L,N);
    
    // BLINN-PHONG Halfway Vector "H" for specular component
    vec3 H = normalize(eyeDirectionCameraspace + L);

	// Cosine of the angle between the Eye vector and the Reflect vector,
	// The cosine is clamped to contrain it between 0 and 1 to avoid negative values
	// BLINN PHONG: Alpha is now dot product of halfway vector(H) and surface normal(N)
	float cosAlpha = clamp( dot( H,N ), 0,1 );

	// compute the light components using the colors and material properties
	vec3 Ia = ambientColor * ambColorMat.rgb * textureVal; //colorAmb is the material property for ambient
	vec3 Id = diffuseColor * diffColorMat.rgb * textureVal * cosTheta; //colorDiff is the material property for diffuse
	vec3 Is = specularColor * specColorMat.rgb * textureVal * pow(cosAlpha, exponent); //colorSpec is the material property for specular

    color.rgb = Ia + Id + Is; // start with standard render

    if(renderMode == 1.0) // standard color output
    {
        color.rgb = Ia + Id + Is;
    }
    else if(renderMode == 2.0) // RGB Normalization Effect
    {
        color.rgb = Ia + Id + Is;
        float S = color.r + color.g + color.b;
        color.r = color.r/S;
        color.g = color.g/S;
        color.b = color.b/S;
    }
    else if(renderMode == 3.0) // B&W Effect
    {
        color.rgb = Ia + Id + Is;
        color.r = (color.r + color.b + color.g)/3.0;
        color.g = (color.r + color.b + color.g)/3.0;
        color.b = (color.r + color.b + color.g)/3.0;
    }
    
    color.a = opacity;
}

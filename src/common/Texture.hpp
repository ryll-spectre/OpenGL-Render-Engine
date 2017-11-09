/*
 * Texture.hpp
 *
 *  Class for representing a texture.
 *  by Stefanie Zollmann
 *
 */
#ifndef TEXTURE_HPP
#define TEXTURE_HPP
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

// Include GLEW
#include <GL/glew.h>

//!  Texture.
/*!
 Basic texture represenation. Supports dds and bmp at the moment
 */
class Texture{
    public:
        //! Default constructor
        /*! Setting up default texture. */
        Texture();
        //! Constructor
        /*! Setting up texture from filename. */
        Texture(std::string filename);
        //! Constructor
        /*! Setting up texture with widht and height. */
		Texture(int w, int h);
        //! Destructor
        /*! Clean up ressources. */
        ~Texture();
        //! bindTexture
        /*! Bind our texture in Texture Unit 0. */
        void bindTexture();
        //! bindTegetTextureIDxture
        /*! Returns the id of the texture object. */
        GLuint getTextureID();
    
    private:
        GLuint m_textureID;
		// Load a .DDS file using GLFW's own loader
		GLuint loadDDS(const char * imagepath);
		// a few functions that can be used everywhere - better to encapsulate this!!!
		// Load a .BMP file using our custom loader
		GLuint loadBMP_custom(const char * imagepath);

};




#endif

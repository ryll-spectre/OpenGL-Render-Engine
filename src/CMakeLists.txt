# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (COSC_Assignment_OpenGL)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP



include_directories(
external/glfw-3.1.2/include/GLFW/
external/glm-0.9.7.1/
external/glew-1.13.0/include/
external/assimp-3.0.1270/include/
.
)

set(ALL_LIBS
${OPENGL_LIBRARY}
glfw
GLEW_1130
)

add_definitions(
-DTW_STATIC
-DTW_NO_LIB_PRAGMA
-DTW_NO_DIRECT3D
-DGLEW_STATIC
-D_CRT_SECURE_NO_WARNINGS
)



# OpenGL Skeleton
add_executable(Skeleton
Skeleton/renderApp.cpp
common/Shader.cpp
common/Shader.hpp
common/Texture.cpp
common/Texture.hpp
common/Texture.cpp
common/Texture.hpp
common/Camera.hpp
common/Camera.cpp
common/Scene.hpp
common/Scene.cpp
common/Object.hpp
common/Object.cpp
common/MTLShader.hpp
common/MTLShader.cpp
common/Mesh.hpp
common/Mesh.cpp
common/Material.hpp
common/Material.cpp
common/Group.hpp
common/Group.cpp
common/Objloader.hpp
common/Objloader.cpp
common/Controls.hpp
common/Controls.cpp

Skeleton/mtlShader.frag
Skeleton/mtlShader.vert
)
target_link_libraries(Skeleton
${ALL_LIBS}
assimp
)
set_target_properties(Skeleton PROPERTIES COMPILE_DEFINITIONS "USE_ASSIMP")
set_target_properties(Skeleton PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Skeleton/")
create_target_launcher(Skeleton WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Skeleton/")



SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )

if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

add_custom_command(
TARGET Skeleton POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/Skeleton${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/Skeleton/"
)

elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )


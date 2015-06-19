# OpenGL_Fun
OpenGL fun with GLEW, SDL2 and GLM 

**GLEW** - load all OpenG functions for this system.

**GLM**  - OpenGL Maths library.

**SDL**  - cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.

<!------------------------------------------------------------->
## My Notes - Graphics Pipeline: 
[Wikipedia link](https://www.opengl.org/wiki/Rendering_Pipeline_Overview)

Data -> Processing(Vertex Shader) -> Rasterisation -> Processing (fragment shader) -> Output image

####Vertex Shader
Is fed the Vertex Attribute data and converts the data into points that can be connected (but does not actually connect them just yet).

####Rasterisation
Has two stages, stage one connects the points and stage two fills them in.

####Fragment Shader
Takes every single pixel and generates some colour for it

####Output image
Takes the output image and write all the pixels to it.
Note every stage of the pipeline is done in parallel
<!------------------------------------------------------------->
##Implementation
**Meshes** - defines the vertices of a object. 
The format of vertex is that it has 3 coordinates x,y,z between -1 and 1. 
OpenGL expects 3 vertecies in sequence to represent a triangle.

**mesh.cpp** implements the logic behind the list of verticies we give either manually or via importing a model.

**shader.cpp** creates shaders from given vertex/fragment source, performs error handling and binds the shaders to OpenGL program.
The basic source code for shaders is located in `./res/basicShaders[.vs/.fs]`.

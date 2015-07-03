#version 120

attribute vec3 position; //position of verticies
attribute vec2 texCoord; //position of texture coordinates to use
varying vec2 texCoord0;  //varying variable can be shared between shaders
						 //shares texCoord to .fs shader via texCoord0 varying variable
						 //value of this value is also interpolated.

void main()
{
	gl_Position =  vec4(position, 1.0);
	texCoord0 = texCoord; 

}
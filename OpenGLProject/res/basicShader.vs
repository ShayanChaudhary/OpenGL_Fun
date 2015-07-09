#version 120

attribute vec3 position; //position of verticies
attribute vec2 texCoord; //position of texture coordinates to use
varying vec2 texCoord0;  //varying variable can be shared between shaders
						 //shares texCoord to .fs shader via texCoord0 varying variable
						 //value of this value is also interpolated.

uniform mat4 transform; //uniform variable can be set by the cpu

void main()
{
	gl_Position =  transform * vec4(position, 1.0);
	texCoord0 = texCoord;
}

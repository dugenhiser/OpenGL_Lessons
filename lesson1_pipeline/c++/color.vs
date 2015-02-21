// Author: Jordan Reed

#version 330 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec4 color;

out vec4 colorVarying;

uniform mat4 mvp;

void main()
{
    gl_Position = mvp * vec4(vertex, 1.0);
    colorVarying = color;
}

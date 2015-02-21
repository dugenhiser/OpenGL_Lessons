// Author: Jordan Reed

#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <vector>

#include "Graphics.h"
#include "Matrix.h"
#include "Vector.h"

class Renderer
{
private:
    
    bool keysDown[256];
    string resourcePath;
    
    vec2 screenSize;
    float aspectRatio;
    float fieldOfView;
    mat4 perspectiveMatrix;
    
    GLuint vao, vbo, cbo;
    int numVertices;
    float objectRotation;
    
    GLuint shaderProgramID;
    GLuint mvpID;
    
public:
    
    Renderer() { }
    void init(float w, float h);
    
    void initColorShader();
    void initTriangle();
    void bindObjectToColorShader();
    
    void reshape(float width, float height);
    
    void update();
    void draw();
};

#endif

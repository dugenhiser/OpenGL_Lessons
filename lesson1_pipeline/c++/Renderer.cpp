// Author: Jordan Reed

#include "Renderer.h"
#include "Helpers.h"

void Renderer::init(float w, float h)
{
    for (int i = 0; i < 256; i++)
    keysDown[i] = false;
    
    // Change this to the path of your resource path
    resourcePath = "/path/to/resources/";
    
    fieldOfView = 70;
    reshape(w, h);
    
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    initColorShader();
    initTriangle();
    bindObjectToColorShader();
    objectRotation = 0;
}

void Renderer::initColorShader()
{
    shaderProgramID = getShaderProgram(resourcePath + "color.vs", resourcePath + "color.fs");
    glUseProgram(shaderProgramID);
    mvpID = glGetUniformLocation(shaderProgramID, "mvp");
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
}

void Renderer::initTriangle()
{
    float vertices[] = {
        -.5, -.5, 0,
        .5, -.5, 0,
        0,  .5, 0
    };

    float colors[] = {
        1,0,0,1,
        0,1,0,1,
        0,0,1,1
    };

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    int size = sizeof(vertices);
    glBufferData(GL_ARRAY_BUFFER, size, &vertices[0], GL_STATIC_DRAW);

    numVertices = size / 3;

    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    size = sizeof(colors);
    glBufferData(GL_ARRAY_BUFFER, size, &colors[0], GL_STATIC_DRAW);
}

void Renderer::bindObjectToColorShader()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void Renderer::reshape(float w, float h)
{
    screenSize.x = w;
    screenSize.y = h;
    aspectRatio = w / h;
    glViewport(0, 0, w, h);
    perspectiveMatrix = perspective(aspectRatio, fieldOfView, 0.1, 5000.0);
}

void Renderer::update()
{
    objectRotation += .25;
    if (objectRotation > 360)
    {
        objectRotation -= 360;
    }
}

void Renderer::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    mat4 viewMatrix = translate(0, 0, -100);
    mat4 mvp = (perspectiveMatrix *
                viewMatrix *
                scale(50,50,50) *
                rotateX(objectRotation) *
                rotateZ(objectRotation));
    
    mat4 mvpTranspose = mvp.transpose();
    glUniformMatrix4fv(mvpID, 1, GL_FALSE, &mvpTranspose.values[0]);
    glDrawArrays(GL_TRIANGLES, 0, numVertices);
}


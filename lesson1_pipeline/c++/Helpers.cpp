// Author: Jordan Reed

#include "Helpers.h"
#include <fstream>

string getShaderCode(string path)
{
    ifstream fin(path.c_str());
    if (fin.fail())
    {
        cout << "Couldn't open: " << path << endl;
        exit(0);
    }
    string code;
    string line = "";
    while (getline(fin, line)) code += "\n" + line;
    fin.close();
    return code;
}

void compileShader(string code, GLuint shaderID)
{
    const char* source = code.c_str();
    glShaderSource(shaderID, 1, &source, NULL);
    glCompileShader(shaderID);
    
    GLint result = GL_FALSE;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    int logLength;
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0)
    {
        cout << "Error(s) when compiling shader:\n";
        char error[logLength + 1];
        glGetShaderInfoLog(shaderID, logLength, NULL, &error[0]);
        cout << error << endl;
    }
}

GLuint getShaderProgram(string vsPath, string fsPath)
{
    GLuint vsID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fsID = glCreateShader(GL_FRAGMENT_SHADER);
    
    compileShader(getShaderCode(vsPath), vsID);
    compileShader(getShaderCode(fsPath), fsID);
    
    GLuint programID = glCreateProgram();
    glAttachShader(programID, vsID);
    glAttachShader(programID, fsID);
    glLinkProgram(programID);
    
    GLint result = GL_FALSE;
    glGetProgramiv(programID, GL_LINK_STATUS, &result);
    int logLength;
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0)
    {
        cout << "Error(s) when linking program:\n";
        char error[logLength + 1];
        glGetProgramInfoLog(programID, logLength, NULL, &error[0]);
        cout << error << endl;
    }
    
    glDeleteShader(vsID);
    glDeleteShader(fsID);
    
    return programID;
}

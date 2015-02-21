// Author: Jordan Reed

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "Vector.h"
using std::ostream;

class vec3;
class vec4;

class mat3
{
public:
    float values[9];
    
    mat3();
    mat3(float a, float b, float c,
         float d, float e, float f,
         float g, float h, float i);
    mat3 transpose();
    vec3 operator * (const vec3 &v);
};
ostream& operator << (ostream& os, const mat3& m);

class mat4
{
public:
    float values[16];
    
    mat4();
    mat4(float a, float b, float c, float d,
         float e, float f, float g, float h,
         float i, float j, float k, float l,
         float m, float n, float o, float p);
    mat4 transpose();
    mat3 toMat3();
    mat4 operator * (const mat4 &right);
    vec4 operator * (const vec4 &v);
    vec3 operator * (const vec3 &v);
};
ostream& operator << (ostream& os, const mat4& m);


/*******************************************************************************
 * Matrix Operations
 ******************************************************************************/
mat4 ortho(float l, float r, float b, float t, float n, float f);
mat4 ortho(float aspectRatio, float n, float f);
mat4 perspective(float l, float r, float b, float t, float n, float f);
mat4 perspective(float aspectRatio, float fov, float n, float f);

mat4 translate(float x, float y, float z);
mat4 translate(vec3 t);
mat4 scale(float x, float y, float z);
mat4 scale(float s);
mat4 rotateX(float degrees);
mat4 rotateY(float degrees);
mat4 rotateZ(float degrees);

/*******************************************************************************
 * Interpolation
 ******************************************************************************/
float lerp(float a, float b, float t);
vec2 lerp(vec2 a, vec2 b, float t);
vec3 lerp(vec3 a, vec3 b, float t);
vec4 lerp(vec4 a, vec4 b, float t);

/*******************************************************************************
 * Other
 ******************************************************************************/
int clamp(int num, int low, int high);
float clamp(float num, float low, float high);
vec2 clamp(vec2 v, float low, float high);
vec3 clamp(vec3 v, float low, float high);
vec4 clamp(vec4 v, float low, float high);


#endif

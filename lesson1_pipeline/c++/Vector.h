// Author: Jordan Reed

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>
#include <ostream>
using namespace std;

#define _USE_MATH_DEFINES

class vec2
{
public:
    float x, y;
    
    vec2()                     {*this = vec2(0, 0)        ;}
    vec2(float inNum)          {*this = vec2(inNum, inNum);}
    vec2(float inX, float inY) {x = inX; y = inY          ;}
    
    float dot(vec2 vec) {return ((x * vec.x) + (y * vec.y));}
    void normalize()
    {
        float mag = sqrt(dot(*this));
        if (mag != 0.0) *this /= mag;
    }
    
    void move(vec2 dir, float distance) {*this += dir * distance;}
    void rotate(vec2 por, float rotation)
    {
        float cosA = cos((M_PI/180.0) * rotation);
        float sinA = sin((M_PI/180.0) * rotation);
        
        vec2 min = (*this - por);
        x = ((min.x * cosA) - (min.y * sinA)) + por.x;
        y = ((min.x * sinA) + (min.y * cosA)) + por.y;
    }
    float distance(const vec2 &rhs)
    {
        vec2 a = *this - rhs;
        return sqrt((a.x * a.x) + (a.y * a.y));
    }
    float length() {return sqrt(dot(*this));}
    
    vec2 operator * (const vec2  &rhs) {return vec2(x * rhs.x, y * rhs.y);}
    vec2 operator * (const float &rhs) {return vec2(x * rhs  , y * rhs  );}
    vec2 operator + (const vec2  &rhs) {return vec2(x + rhs.x, y + rhs.y);}
    vec2 operator + (const float &rhs) {return vec2(x + rhs  , y + rhs  );}
    vec2 operator - (const vec2  &rhs) {return vec2(x - rhs.x, y - rhs.y);}
    vec2 operator - (const float &rhs) {return vec2(x - rhs  , y - rhs  );}
    vec2 operator / (const vec2  &rhs) {return vec2(x / rhs.x, y / rhs.y);}
    vec2 operator / (const float &rhs) {return vec2(x / rhs  , y / rhs  );}
    
    void operator *= (const vec2  &rhs) {x *= rhs.x; y *= rhs.y;}
    void operator *= (const float &rhs) {x *= rhs  ; y *= rhs  ;}
    void operator += (const vec2  &rhs) {x += rhs.x; y += rhs.y;}
    void operator += (const float &rhs) {x += rhs  ; y += rhs  ;}
    void operator -= (const vec2  &rhs) {x -= rhs.x; y -= rhs.y;}
    void operator -= (const float &rhs) {x -= rhs  ; y -= rhs  ;}
    void operator /= (const vec2  &rhs) {x /= rhs.x; y /= rhs.y;}
    void operator /= (const float &rhs) {x /= rhs  ; y /= rhs  ;}
};
ostream& operator << (ostream& os, const vec2& v);




class vec3
{
public:
    float x, y, z;
    
    vec3()                                {*this = vec3(0, 0, 0);}
    vec3(float inNum)                     {*this = vec3(inNum, inNum, inNum);}
    vec3(vec2 inXY, float inZ)            {*this = vec3(inXY.x, inXY.y, inZ);}
    vec3(float inX, float inY, float inZ) {x = inX; y = inY; z = inZ;}
    
    float dot(vec3 vec) {return ((x * vec.x) + (y * vec.y) + (z * vec.z));}
    void normalize()
    {
        float mag = sqrt(dot(*this));
        if (mag != 0.0) *this /= mag;
    }
    float distance(const vec3 &rhs)
    {
        vec3 a = *this - rhs;
        return sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
    }
    vec3 cross(vec3 b)
    {
        return vec3((y * b.z) - (z * b.y),
                    (z * b.x) - (x * b.z),
                    (x * b.y) - (y * b.x));
    }
    float length() {return sqrt(dot(*this));}
    
    vec3 operator * (const vec3  &rhs) {return vec3(x * rhs.x, y * rhs.y, z * rhs.z);}
    vec3 operator * (const float &rhs) {return vec3(x * rhs  , y * rhs  , z * rhs  );}
    vec3 operator + (const vec3  &rhs) {return vec3(x + rhs.x, y + rhs.y, z + rhs.z);}
    vec3 operator + (const float &rhs) {return vec3(x + rhs  , y + rhs  , z + rhs  );}
    vec3 operator - (const vec3  &rhs) {return vec3(x - rhs.x, y - rhs.y, z - rhs.z);}
    vec3 operator - (const float &rhs) {return vec3(x - rhs  , y - rhs  , z - rhs  );}
    vec3 operator / (const vec3  &rhs) {return vec3(x / rhs.x, y / rhs.y, z / rhs.z);}
    vec3 operator / (const float &rhs) {return vec3(x / rhs  , y / rhs  , z / rhs  );}
    
    void operator *= (const vec3  &rhs) {x *= rhs.x; y *= rhs.y; z *= rhs.z;}
    void operator *= (const float &rhs) {x *= rhs  ; y *= rhs  ; z *= rhs  ;}
    void operator += (const vec3  &rhs) {x += rhs.x; y += rhs.y; z += rhs.z;}
    void operator += (const float &rhs) {x += rhs  ; y += rhs  ; z += rhs  ;}
    void operator -= (const vec3  &rhs) {x -= rhs.x; y -= rhs.y; z -= rhs.z;}
    void operator -= (const float &rhs) {x -= rhs  ; y -= rhs  ; z -= rhs  ;}
    void operator /= (const vec3  &rhs) {x /= rhs.x; y /= rhs.y; z /= rhs.z;}
    void operator /= (const float &rhs) {x /= rhs  ; y /= rhs  ; z /= rhs  ;}
};
ostream& operator << (ostream& os, const vec3& v);



class vec4
{
public:
    float x, y, z, w;
    
    vec4()                                           {*this = vec4(0, 0, 0, 0);}
    vec4(float inNum)                                {*this = vec4(inNum, inNum, inNum, inNum);}
    vec4(vec3 inXYZ, float inW)                      {*this = vec4(inXYZ.x, inXYZ.y, inXYZ.z, inW);}
    vec4(vec2 inXY, float inZ, float inW)            {*this = vec4(inXY.x, inXY.y, inZ, inW);}
    vec4(float inX, float inY, float inZ, float inW) {x = inX; y = inY; z = inZ; w = inW;}
    
    float dot(vec4 vec) {return ((x * vec.x) + (y * vec.y) + (z * vec.z) + (w * vec.w));}
    void normalize()
    {
        float mag = sqrt(dot(*this));
        if (mag != 0.0) *this /= mag;
    }
    
    vec4 operator * (const vec4  &rhs) {return vec4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);}
    vec4 operator * (const float &rhs) {return vec4(x * rhs  , y * rhs  , z * rhs  , w * rhs  );}
    vec4 operator + (const vec4  &rhs) {return vec4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);}
    vec4 operator + (const float &rhs) {return vec4(x + rhs  , y + rhs  , z + rhs  , w + rhs  );}
    vec4 operator - (const vec4  &rhs) {return vec4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);}
    vec4 operator - (const float &rhs) {return vec4(x - rhs  , y - rhs  , z - rhs  , w - rhs  );}
    vec4 operator / (const vec4  &rhs) {return vec4(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);}
    vec4 operator / (const float &rhs) {return vec4(x / rhs  , y / rhs  , z / rhs  , w / rhs  );}
    
    void operator *= (const vec4  &rhs) {x *= rhs.x; y *= rhs.y; z *= rhs.z; w *= rhs.w;}
    void operator *= (const float &rhs) {x *= rhs  ; y *= rhs  ; z *= rhs  ; w *= rhs  ;}
    void operator += (const vec4  &rhs) {x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w;}
    void operator += (const float &rhs) {x += rhs  ; y += rhs  ; z += rhs  ; w += rhs  ;}
    void operator -= (const vec4  &rhs) {x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w;}
    void operator -= (const float &rhs) {x -= rhs  ; y -= rhs  ; z -= rhs  ; w -= rhs  ;}
    void operator /= (const vec4  &rhs) {x /= rhs.x; y /= rhs.y; z /= rhs.z; w /= rhs.w;}
    void operator /= (const float &rhs) {x /= rhs  ; y /= rhs  ; z /= rhs  ; w /= rhs  ;}
};
ostream& operator << (ostream& os, const vec4& v);


class projection
{
public:
    float min, max;
    
    projection() {*this = projection(0, 0);}
    projection(float inMin, float inMax) {min = inMin; max = inMax;}
    
    bool overlap(projection p2)	{return (getOverlap(p2) > 0);}
    float getOverlap(projection p2)
    {
        if (min <= p2.min) return max - p2.min;
        else return p2.max - min;
    }
};



class vec2i
{
public:
    int x, y;
    
    vec2i() {*this = vec2i(0,0);}
    vec2i(int inX, int inY) {x = inX; y = inY;}
};
ostream& operator << (ostream& os, const vec2i& v);

class vec3i
{
public:
    int x, y, z;
    
    vec3i() {*this = vec3i(0,0,0);}
    vec3i(int inX, int inY, int inZ) {x = inX; y = inY; z = inZ;}
    
    vec3i operator * (const vec3i &rhs) {return vec3i(x * rhs.x, y * rhs.y, z * rhs.z);}
    vec3i operator * (const float &rhs) {return vec3i(x * rhs  , y * rhs  , z * rhs  );}
    vec3i operator + (const vec3i &rhs) {return vec3i(x + rhs.x, y + rhs.y, z + rhs.z);}
    vec3i operator + (const float &rhs) {return vec3i(x + rhs  , y + rhs  , z + rhs  );}
    vec3i operator - (const vec3i &rhs) {return vec3i(x - rhs.x, y - rhs.y, z - rhs.z);}
    vec3i operator - (const float &rhs) {return vec3i(x - rhs  , y - rhs  , z - rhs  );}
    vec3i operator / (const vec3i &rhs) {return vec3i(x / rhs.x, y / rhs.y, z / rhs.z);}
    vec3i operator / (const float &rhs) {return vec3i(x / rhs  , y / rhs  , z / rhs  );}
    
    void operator *= (const vec3i &rhs) {x *= rhs.x; y *= rhs.y; z *= rhs.z;}
    void operator *= (const float &rhs) {x *= rhs  ; y *= rhs  ; z *= rhs  ;}
    void operator += (const vec3i &rhs) {x += rhs.x; y += rhs.y; z += rhs.z;}
    void operator += (const float &rhs) {x += rhs  ; y += rhs  ; z += rhs  ;}
    void operator -= (const vec3i &rhs) {x -= rhs.x; y -= rhs.y; z -= rhs.z;}
    void operator -= (const float &rhs) {x -= rhs  ; y -= rhs  ; z -= rhs  ;}
    void operator /= (const vec3i &rhs) {x /= rhs.x; y /= rhs.y; z /= rhs.z;}
    void operator /= (const float &rhs) {x /= rhs  ; y /= rhs  ; z /= rhs  ;}
    
    bool operator == (const vec3i &rhs) {return x == rhs.x && y == rhs.y && z == rhs.z;}
};
ostream& operator << (ostream& os, const vec3i& v);


#endif

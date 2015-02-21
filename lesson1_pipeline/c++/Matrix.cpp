// Author: Jordan Reed

#include "Matrix.h"

#include <iostream>
#include "Vector.h"
using std::cout;

mat3::mat3()
{
    *this = mat3(1.0, 0.0, 0.0,
                 0.0, 1.0, 0.0,
                 0.0, 0.0, 1.0);
}

mat3::mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
    values[0] = a; values[1] = b; values[2] = c;
    values[3] = d; values[4] = e; values[5] = f;
    values[6] = g; values[7] = h; values[8] = i;
}

mat3 mat3::transpose()
{
    return mat3(values[0], values[3], values[6],
                values[1], values[4], values[7],
                values[2], values[5], values[8]);
}

vec3 mat3::operator * (const vec3 &v)
{
    // 0 1 2     0
    // 3 4 5  X  1
    // 6 7 8     2
    return vec3(values[0] * v.x + values[1] * v.y + values[2] * v.y,
                values[3] * v.x + values[4] * v.y + values[5] * v.y,
                values[6] * v.x + values[7] * v.y + values[8] * v.y);
}

ostream& operator << (ostream& os, const mat3& m)
{
    cout << "|" << m.values[0] << ", " << m.values[1] << ", " << m.values[2] << "|\n";
    cout << "|" << m.values[3] << ", " << m.values[4] << ", " << m.values[5] << "|\n";
    cout << "|" << m.values[6] << ", " << m.values[7] << ", " << m.values[8] << "|\n";
    return os;
}






mat4::mat4()
{
    *this = mat4(1.0, 0.0, 0.0, 0.0,
                 0.0, 1.0, 0.0, 0.0,
                 0.0, 0.0, 1.0, 0.0,
                 0.0, 0.0, 0.0, 1.0);
}

mat4::mat4(float a, float b, float c, float d, float e, float f, float g, float h,
           float i, float j, float k, float l, float m, float n, float o, float p)
{
    values[ 0] = a; values[ 1] = b; values[ 2] = c; values[ 3] = d;
    values[ 4] = e; values[ 5] = f; values[ 6] = g; values[ 7] = h;
    values[ 8] = i; values[ 9] = j; values[10] = k; values[11] = l;
    values[12] = m; values[13] = n; values[14] = o; values[15] = p;
}

mat4 mat4::transpose()
{
    return mat4(values[0], values[4], values[ 8], values[12],
                values[1], values[5], values[ 9], values[13],
                values[2], values[6], values[10], values[14],
                values[3], values[7], values[11], values[15]);
}

mat3 mat4::toMat3()
{
    // 0 1 2
    // 4 5 6
    // 8 9 10
    return mat3(values[0], values[1], values[ 2],
                values[4], values[5], values[ 6],
                values[8], values[9], values[10]);
}

mat4 mat4::operator * (const mat4 &right)
{
    // 0  1  2  3      0  1  2  3
    // 4  5  6  7   X  4  5  6  7
    // 8  9  10 11     8  9  10 11
    // 12 13 14 15     12 13 14 15
    return mat4((values[ 0] * right.values[ 0]) + (values[ 1] * right.values[ 4]) + // Row 1
                (values[ 2] * right.values[ 8]) + (values[ 3] * right.values[12]),
                (values[ 0] * right.values[ 1]) + (values[ 1] * right.values[ 5]) +
                (values[ 2] * right.values[ 9]) + (values[ 3] * right.values[13]),
                (values[ 0] * right.values[ 2]) + (values[ 1] * right.values[ 6]) +
                (values[ 2] * right.values[10]) + (values[ 3] * right.values[14]),
                (values[ 0] * right.values[ 3]) + (values[ 1] * right.values[ 7]) +
                (values[ 2] * right.values[11]) + (values[ 3] * right.values[15]),
                
                (values[ 4] * right.values[ 0]) + (values[ 5] * right.values[4 ]) + // Row 2
                (values[ 6] * right.values[ 8]) + (values[ 7] * right.values[12]),
                (values[ 4] * right.values[ 1]) + (values[ 5] * right.values[5 ]) +
                (values[ 6] * right.values[ 9]) + (values[ 7] * right.values[13]),
                (values[ 4] * right.values[ 2]) + (values[ 5] * right.values[6 ]) +
                (values[ 6] * right.values[10]) + (values[ 7] * right.values[14]),
                (values[ 4] * right.values[ 3]) + (values[ 5] * right.values[7 ]) +
                (values[ 6] * right.values[11]) + (values[ 7] * right.values[15]),
                
                (values[ 8] * right.values[ 0]) + (values[ 9] * right.values[ 4]) + // Row 3
                (values[10] * right.values[ 8]) + (values[11] * right.values[12]),
                (values[ 8] * right.values[ 1]) + (values[ 9] * right.values[ 5]) +
                (values[10] * right.values[ 9]) + (values[11] * right.values[13]),
                (values[ 8] * right.values[ 2]) + (values[ 9] * right.values[ 6]) +
                (values[10] * right.values[10]) + (values[11] * right.values[14]),
                (values[ 8] * right.values[ 3]) + (values[ 9] * right.values[ 7]) +
                (values[10] * right.values[11]) + (values[11] * right.values[15]),
                
                (values[12] * right.values[ 0]) + (values[13] * right.values[ 4]) + // Row 4
                (values[14] * right.values[ 8]) + (values[15] * right.values[12]),
                (values[12] * right.values[ 1]) + (values[13] * right.values[ 5]) +
                (values[14] * right.values[ 9]) + (values[15] * right.values[13]),
                (values[12] * right.values[ 2]) + (values[13] * right.values[ 6]) +
                (values[14] * right.values[10]) + (values[15] * right.values[14]),
                (values[12] * right.values[ 3]) + (values[13] * right.values[ 7]) +
                (values[14] * right.values[11]) + (values[15] * right.values[15]));
}

vec4 mat4::operator * (const vec4 &v)
{
    // 0  1  2  3        0
    // 4  5  6  7    X   1
    // 8  9  10 11       2
    // 12 13 14 15       3
    return vec4(values[ 0] * v.x + values[ 1] * v.y + values[ 2] * v.z + values[ 3] * v.w,
                values[ 4] * v.x + values[ 5] * v.y + values[ 6] * v.z + values[ 7] * v.w,
                values[ 8] * v.x + values[ 9] * v.y + values[10] * v.z + values[11] * v.w,
                values[12] * v.x + values[13] * v.y + values[14] * v.z + values[15] * v.w);
}

vec3 mat4::operator * (const vec3 &v)
{
    // 0  1  2  3        0
    // 4  5  6  7    X   1
    // 8  9  10 11       2
    // 12 13 14 15       3
    return vec3(values[ 0] * v.x + values[ 1] * v.y + values[ 2] * v.z + values[ 3],
                values[ 4] * v.x + values[ 5] * v.y + values[ 6] * v.z + values[ 7],
                values[ 8] * v.x + values[ 9] * v.y + values[10] * v.z + values[11]);
}

ostream& operator << (ostream& os, const mat4& m)
{
    cout << "|" << m.values[ 0] << ", " << m.values[ 1] << ", " << m.values[ 2] << ", " << m.values[ 3] << "|\n";
    cout << "|" << m.values[ 4] << ", " << m.values[ 5] << ", " << m.values[ 6] << ", " << m.values[ 7] << "|\n";
    cout << "|" << m.values[ 8] << ", " << m.values[ 9] << ", " << m.values[10] << ", " << m.values[11] << "|\n";
    cout << "|" << m.values[12] << ", " << m.values[13] << ", " << m.values[14] << ", " << m.values[15] << "|\n";
    return os;
}







mat4 perspective(float l, float r, float b, float t, float n, float f)
{
    return mat4(((2.0*n)/(r-l)), 0.0            , ((r+l)/(r-l)) , 0.0,
                0.0            , ((2.0*n)/(t-b)), ((t+b)/(t-b)) , 0.0,
                0.0            , 0.0            , (-(f+n)/(f-n)), ((-2.0*f*n)/(f-n)),
                0.0            , 0.0            , -1.0          , 0.0);
}
mat4 perspective(float aspect, float fov, float zNear, float zFar)
{
    float fH = float(tan(fov / 360.0 * M_PI) * zNear);
    float fW = float(fH * aspect);
    return perspective(-fW, fW, -fH, fH, zNear, zFar);
}

mat4 ortho(float l, float r, float b, float t, float n, float f)
{
    return mat4((2.0/(r-l)), 0.0        , 0.0         , -((r+l)/(r-l)),
                0.0        , (2.0/(t-b)), 0.0         , -((t+b)/(t-b)),
                0.0        , 0.0        , (-2.0/(f-n)), -((f+n)/(f-n)),
                0.0        , 0.0        , 0.0         , 1.0);
}

mat4 ortho(float aspectRatio, float n, float f)
{
    float l, r, b, t;
    if (aspectRatio <= 1)
    {
        l = -1; r = 1;
        t = 1/aspectRatio;
        b = -t;
    }
    else
    {
        r = aspectRatio;
        l = -r;
        b = -1; t = 1;
    }
    return ortho(l, r, t, b, n, f);
}

mat4 translate(float x, float y, float z)
{
    return mat4(1.0, 0.0, 0.0, x,
                0.0, 1.0, 0.0, y,
                0.0, 0.0, 1.0, z,
                0.0, 0.0, 0.0, 1.0);
}
mat4 translate(vec3 t) {return translate(t.x, t.y, t.z);}

mat4 scale(float x, float y, float z)
{
    return mat4(x  , 0.0, 0.0, 0.0,
                0.0, y  , 0.0, 0.0,
                0.0, 0.0, z  , 0.0,
                0.0, 0.0, 0.0, 1.0);
}
mat4 scale(float s) {return scale(s, s, s);}

// t+center  *  rotate  *  scale  *  t-center
// parentMatrix * childMatrix
// roll -> pitch -> yaw (z -> x -> y)
// mat multiply ->  yaw * pitch * roll (y * x * z)
mat4 rotateX(float degrees) // pitch
{
    float cosA = cos((M_PI / 180.0) * degrees);
    float sinA = sin((M_PI / 180.0) * degrees);
    return mat4(1.0, 0.0 ,  0.0 , 0.0,
                0.0, cosA, -sinA, 0.0,
                0.0, sinA,  cosA, 0.0,
                0.0, 0.0 ,  0.0 , 1.0);
}

mat4 rotateY(float degrees) // yaw
{
    float cosA = cos((M_PI / 180.0) * degrees);
    float sinA = sin((M_PI / 180.0) * degrees);
    return mat4(cosA , 0.0, sinA, 0.0,
                0.0  , 1.0, 0.0 , 0.0,
                -sinA, 0.0, cosA, 0.0,
                0.0  , 0.0, 0.0 , 1.0);
}

mat4 rotateZ(float degrees) // roll
{
    float cosA = cos((M_PI / 180.0) * degrees);
    float sinA = sin((M_PI / 180.0) * degrees);
    return mat4(cosA,-sinA, 0.0, 0.0,
                sinA, cosA, 0.0, 0.0,
                0.0 , 0.0 , 1.0, 0.0,
                0.0 , 0.0 , 0.0, 1.0);
}

float lerp(float a, float b, float t) {return (a + ((b - a) * t));}
vec2 lerp(vec2 a, vec2 b, float t) {return a + ((b - a) * t);}
vec3 lerp(vec3 a, vec3 b, float t) {return a + ((b - a) * t);}
vec4 lerp(vec4 a, vec4 b, float t) {return a + ((b - a) * t);}

//I' = I - 2 * dot(N, I) * N;
vec2 reflect(vec2 dir, vec2 normal) {return dir - (normal * 2 * normal.dot(dir));}
vec3 reflect(vec3 dir, vec3 normal) {return dir - (normal * 2 * normal.dot(dir));}
vec4 reflect(vec4 dir, vec4 normal) {return dir - (normal * 2 * normal.dot(dir));}

//template <class T>
//T clamp(T num, T low, T high)
//{
//    if      (num < low)  return low;
//    else if (num > high) return high;
//    else                 return num;
//}
int clamp(int num, int low, int high)
{
    if      (num < low)  return low;
    else if (num > high) return high;
    else                 return num;
}

float clamp(float num, float low, float high)
{
    if      (num < low)  return low;
    else if (num > high) return high;
    else                 return num;
}
vec2 clamp(vec2 v, float low, float high)
{
    return vec2(clamp(v.x, low, high),
                clamp(v.y, low, high));
}
vec3 clamp(vec3 v, float low, float high)
{
    return vec3(clamp(v.x, low, high),
                clamp(v.y, low, high),
                clamp(v.z, low, high));
}
vec4 clamp(vec4 v, float low, float high)
{
    return vec4(clamp(v.x, low, high),
                clamp(v.y, low, high),
                clamp(v.z, low, high),
                clamp(v.w, low, high));
}


// Author: Jordan Reed

#include "Vector.h"

ostream& operator << (ostream& os, const vec2& v)
{
    os << v.x << ", " << v.y;
    return os;
}

ostream& operator << (ostream& os, const vec3& v)
{
    os << v.x << ", " << v.y << ", " << v.z;
    return os;
}

ostream& operator << (ostream& os, const vec4& v)
{
    os << v.x << ", " << v.y << ", " << v.z << ", " << v.w;
    return os;
}




ostream& operator << (ostream& os, const vec2i& v)
{
    os << v.x << ", " << v.y;
    return os;
}

ostream& operator << (ostream& os, const vec3i& v)
{
    os << v.x << ", " << v.y << ", " << v.z;
    return os;
}

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

// vector 3 class
class vec3
{
public:
    double e[3];

    vec3() : e{0, 0, 0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // vector of opposite director or uniary minus
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    // allows reading a component by index - but read only (const)
    double operator[](int i) const { return e[i]; }

    // modify a component by index
    double &operator[](int i) { return e[i]; }

    // add assign, adds another vec3 to this vec3
    vec3 &operator+=(const vec3 &v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    // multiply assign, multiplies another vec3 to this vec3
    vec3 &operator*=(double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    // divide assign, divides another vec3 to this vec3

    vec3 &operator/=(double t)
    {
        return *this *= 1 / t;
    }

    // length of vector
    double length() const
    {
        return std::sqrt(length_squared());
    }

    double length_squared() const
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
};

// points alias
using point3 = vec3;

// unitlity funtions

// defines how vec3 is sent to output stream
inline std::ostream &operator<<(std::ostream &out, const vec3 &v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// addition operator -- overloads the default operator for this obj
inline vec3 operator+(const vec3 &u, const vec3 &v)
{
    // u + v => (x1 + x2, y1 + y2, z1 + z2)
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// minus operator -- overloads the default operator for this obj
inline vec3 operator-(const vec3 &u, const vec3 &v)
{
    // u - v => (x1 - x2, y1 - y2, z1 - z2)
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3 &v)
{
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t)
{
    return t * v;
}

inline vec3 operator/(const vec3 &v, double t)
{
    return (1 / t) * v;
}

inline double dot(const vec3 &u, const vec3 &v)
{
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3 &v)
{
    return v / v.length();
}

#endif
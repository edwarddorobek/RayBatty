#pragma once

#include "Common.h"
#include "Util.h"
#include <iosfwd>
#include <string>


class VEC3;
inline VEC3 operator+(const VEC3 &a, const VEC3 &b);
inline VEC3 operator-(const VEC3 &a, const VEC3 &b);
inline VEC3 operator*(const VEC3 &a, const VEC3 &b);
inline VEC3 operator*(const double s, const VEC3 &v);
inline VEC3 operator*(const VEC3 &v, const double s);
inline VEC3 operator/(const VEC3 &v, const double s);


class VEC3 {
public:
    // Data
    double _x = 0;
    double _y = 0;
    double _z = 0;

    enum class Axis {
        X = 0,
        Y,
        Z
    };

public:
    explicit VEC3() = default;

    // Create a vector w/ the same value for each component
    explicit VEC3(const double value)  :
        VEC3(value, value, value)
    { }

    explicit VEC3(const double x_, const double y_, const double z_) :
        _x(x_),
        _y(y_),
        _z(z_)
    { }

    // Negation
    inline VEC3 operator-() const  {
        return VEC3(-_x, -_y, -_z);
    }

    inline VEC3 &operator+=(const VEC3 &rhs)  {
        _x += rhs.x;
        _y += rhs.y;
        _z += rhs.z;

        return *this;
    }

    inline VEC3 &operator-=(const VEC3 &rhs)  {
        _x -= rhs.x;
        _y -= rhs.y;
        _z -= rhs.z;

        return *this;
    }

    inline VEC3 &operator*=(const double t)  {
        _x *= t;
        _y *= t;
        _z *= t;

        return *this;
    }

    inline VEC3 &operator/=(const double t)  {
        return (*this *= (1 / t));
    }

    inline double length() const  {
        return util::sqrt(length_squared());
    }

    // Is the dot product with itself
    inline double length_squared() const  {
        return (_x * _x) + (_y * _y) + (_z * _z);
    }

    inline VEC3 unit_vector() const  {
        return *this / length();
    }

    inline double dot(const VEC3 &other) const  {
        return (_x * other.x) + (_y * other.y) + (_z * other.z);
    }

    inline VEC3 cross(const VEC3 &other) const  {
        return VEC3(
            (_y * other.z) - (_z * other.y),
            (_z * other.x) - (_x * other.z),
            (_x * other.y) - (_y * other.x)
        );
    }

    inline VEC3 reflect(const VEC3 &n) const  {
        const VEC3 v = *this;
        return v - (2 * v.dot(n) * n);
    }

    VEC3 refract(const VEC3 &n, const double etai_over_etat) const  {
        const VEC3 uv = *this;
        const double cos_theta = (-uv).dot(n);
        const VEC3 r_out_perp = etai_over_etat * (uv + (cos_theta * n));
        const VEC3 r_out_parallel = -sqrt(fabs(1 - r_out_perp.length_squared())) * n;

        return r_out_perp + r_out_parallel;
    }

    // Produces the vector but with each component their inverse
    inline VEC3 recip() const  {
        return VEC3(
            1 / _x,
            1 / _y,
            1 / _z
        );
    }

    std::string str() const {
        return "VEC3<" + std::to_string(_x) +
                  ", " + std::to_string(_y) +
                  ", " + std::to_string(_z) + ">";
    }
};

// arithmetic
inline VEC3 operator+(const VEC3 &a, const VEC3 &b)  {
    return VEC3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline VEC3 operator-(const VEC3 &a, const VEC3 &b)  {
    return VEC3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline VEC3 operator*(const VEC3 &a, const VEC3 &b)  {
    return VEC3(a.x * b.x, a.y * b.y, a.z * b.z);
}

inline VEC3 operator*(const double s, const VEC3 &v)  {
    return VEC3(s * v.x, s * v.y, s * v.z);
}

inline VEC3 operator*(const VEC3 &v, const double s)  {
    return s * v;
}

inline VEC3 operator/(const VEC3 &v, const double s)  {
    return (static_cast<double>(1) / s) * v;
}

// Other
std::ostream &operator<<(std::ostream &out, const VEC3 &v);
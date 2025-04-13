#pragma once

#include <cmath>
#include <iostream>
#include <cassert>

class Vec3 {
public:
    float data_[3];

    constexpr Vec3() : data_{0.0f, 0.0f, 0.0f} {}
    constexpr Vec3(float x, float y, float z) : data_{x, y, z} {}
    
    constexpr float x() const { return data_[0]; }
    constexpr float y() const { return data_[1]; }
    constexpr float z() const { return data_[2]; }

    constexpr Vec3 operator-() const {
        return Vec3(-data_[0], -data_[1], -data_[2]);
    }

    constexpr float operator[](size_t index) const {
        assert(index < 3 && "Index out of bounds");
        return data_[index];
    }
    constexpr float& operator[](size_t index) {
        assert(index < 3 && "Index out of bounds");
        return data_[index];
    }

    constexpr Vec3& operator+=(const Vec3& other) {
        data_[0] += other.data_[0];
        data_[1] += other.data_[1];
        data_[2] += other.data_[2];
        return *this;
    }

    constexpr Vec3& operator*=(float scalar) {
        data_[0] *= scalar;
        data_[1] *= scalar;
        data_[2] *= scalar;
        return *this;
    }

    constexpr Vec3& operator/=(float scalar) {
        assert(scalar != 0.0f && "Division by zero");
        return *this *= (1.0f / scalar);
    }

    constexpr float length() const {
        return std::sqrt(lengthSquared());
    }

    constexpr float lengthSquared() const {
        return (data_[0] * data_[0]) + (data_[1] * data_[1]) + (data_[2] * data_[2]);
    }
};

using Point3 = Vec3;
using Color = Vec3;

inline std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
    os << "Vec3(" << vec.x() << ", " << vec.y() << ", " << vec.z() << ")";
    return os;
}

constexpr Vec3 operator+(const Vec3& a, const Vec3& b) {
    return Vec3(a.data_[0] + b.data_[0],
                a.data_[1] + b.data_[1],
                a.data_[2] + b.data_[2]);
}

constexpr Vec3 operator-(const Vec3& a, const Vec3& b) {
    return Vec3(a.data_[0] - b.data_[0],
                a.data_[1] - b.data_[1],
                a.data_[2] - b.data_[2]);
}

constexpr Vec3 operator*(const Vec3& a, const Vec3& b) {
    return Vec3(a.data_[0] * b.data_[0],
                a.data_[1] * b.data_[1],
                a.data_[2] * b.data_[2]);
}

constexpr Vec3 operator*(const Vec3& vec, float scalar) {
    return Vec3(vec.data_[0] * scalar,
                vec.data_[1] * scalar,
                vec.data_[2] * scalar);
}

constexpr Vec3 operator*(float scalar, const Vec3& vec) {
    return vec * scalar;
}

constexpr Vec3 operator/(const Vec3& vec, float scalar) {
    return Vec3(vec.data_[0] / scalar,
                vec.data_[1] / scalar,
                vec.data_[2] / scalar);
}

constexpr float dot(const Vec3& u, const Vec3& v) {
    return u.data_[0] * v.data_[0] +
           u.data_[1] * v.data_[1] +
           u.data_[2] * v.data_[2];
}

constexpr Vec3 cross(const Vec3& u, const Vec3& v) {
    return Vec3(u.data_[1] * v.data_[2] - u.data_[2] * v.data_[1],
                u.data_[2] * v.data_[0] - u.data_[0] * v.data_[2],
                u.data_[0] * v.data_[1] - u.data_[1] * v.data_[0]);
}

constexpr Vec3 unitVector(const Vec3& vec) {
    float len = vec.length();
    if (len == 0.0f) {
        return Vec3(0.0f, 0.0f, 0.0f); // Return a zero vector if length is zero
    }
    return vec / len;
}

inline void writeColorToBuffer(uint8_t* buffer, const Color& color) {
    auto clamp = [](float x) { return x < 0.0f ? 0.0f : (x > 1.0f ? 1.0f : x); };
    buffer[0] = static_cast<uint8_t>(clamp(color.x()) * 255.999f);
    buffer[1] = static_cast<uint8_t>(clamp(color.y()) * 255.999f);
    buffer[2] = static_cast<uint8_t>(clamp(color.z()) * 255.999f);
}
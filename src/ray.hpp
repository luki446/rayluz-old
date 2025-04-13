#pragma once

#include "vec3.hpp"

class Ray {
public:
    constexpr Ray() {}
    constexpr Ray(const Point3& origin, const Vec3& direction): origin_(origin), direction_(direction) {}
    
    constexpr Point3 const& origin() const { return origin_; }
    constexpr Vec3 const& direction() const { return direction_; }

    constexpr Point3 at(float t) const {
        return origin_ + (t * direction_);
    }
private:
    Point3 origin_;
    Vec3 direction_;
};
#include "image_save.hpp"
#include "vec3.hpp"
#include "ray.hpp"
#include <cstdint>
#include <memory>
#include "camera_constants.hpp"

bool hitSphere(const Point3& center, float radius, const Ray& ray) {
    Vec3 oc = center - ray.origin();
    float a = dot(ray.direction(), ray.direction());
    float b = -2.0f * dot(ray.direction(), oc);
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4.0f * a * c;
    return discriminant >= 0.0f;
}

Color rayColor(const Ray& ray) {
    if(hitSphere(Point3(0.0f, 0.0f, -1.0f), 0.5f, ray)) {
        return Color(1.0f, 0.0f, 0.0f);
    }

    Vec3 unit_direction = unitVector(ray.direction());
    
    float alpha = 0.5f * (unit_direction.y() + 1.0f); // Assuming y is up
    return (1.0f - alpha) * Color(1.0f, 1.0f, 1.0f) + alpha * Color(0.25f, 0.35f, 1.0f);
}

int main(int argc, char** argv) {
    auto image_data = std::make_unique<uint8_t[]>(kImageWidth * kImageHeight * kBytesPerPixel);

    for(int32_t row_index{0}; row_index < kImageHeight; ++row_index) {
        for(int32_t column_index{0}; column_index < kImageWidth; ++column_index) {
            auto pixel_center = kPixel00Location + (kPixelDeltaU * float(column_index)) + (kPixelDeltaV * float(row_index));
            auto ray_direction = pixel_center - kCameraCenter;

            Ray ray{kCameraCenter, ray_direction};
            Color pixel_color = rayColor(ray);
            writeColorToBuffer(&image_data[(row_index * kImageWidth + column_index) * kBytesPerPixel], pixel_color);
        }
    }

    savePixelsToImage("output.png", image_data.get(), kImageWidth, kImageHeight);

    return 0;
}
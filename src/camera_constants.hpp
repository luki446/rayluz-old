#pragma once
#include <cstdint>
#include "vec3.hpp"

constexpr static float kAspectRatio{16.0f / 9.0f};
constexpr static int32_t kImageWidth{200};

constexpr static int32_t kImageHeight{int32_t(kImageWidth / kAspectRatio)};

constexpr static float kFocalLength{1.0f};
constexpr static float kViewportHeight{2.0f};
constexpr static float kViewportWidth{kViewportHeight * (float(kImageWidth) / kImageHeight)};
constexpr static Point3 kCameraCenter{0.0f, 0.0f, 0.0f};

constexpr static Vec3 kViewportU{kViewportWidth, 0.0f, 0.0f};
constexpr static Vec3 kViewportV{0.0f, -kViewportHeight, 0.0f};

constexpr static Vec3 kPixelDeltaU{kViewportU / float(kImageWidth)};
constexpr static Vec3 kPixelDeltaV{kViewportV / float(kImageHeight)};

constexpr static Vec3 kViewportUpperLeft{kCameraCenter - Vec3(0.0f, 0.0f, kFocalLength) - (kViewportU / 2.0f) - (kViewportV / 2.0f)};
constexpr static Vec3 kPixel00Location{kViewportUpperLeft + 0.5f * (kPixelDeltaU + kPixelDeltaV)};

constexpr static int32_t kBytesPerPixel{3};
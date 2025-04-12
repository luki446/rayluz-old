#include "image_save.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

void savePixelsToImage(const std::string_view image_path, const uint8_t* image_data, int width, int height) {
    stbi_write_png(image_path.data(), width, height, 3, image_data, width * 3);
}
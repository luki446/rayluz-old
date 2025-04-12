#pragma once
#include <string_view>


void savePixelsToImage(const std::string_view image_path, const uint8_t* image_data, int const width, int const height);
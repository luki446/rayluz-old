#include "image_save.hpp"

int main(int argc, char** argv) {
    constexpr static size_t image_width{256};
    constexpr static size_t image_height{256};
    uint8_t image_data[image_width * image_height * 3]{0};

    for(int32_t i{0}; i < image_width; ++i) {
        for(int32_t j{0}; j < image_height; ++j) {
            auto red = double(i) / (image_width - 1);
            auto green = double(j) / (image_height - 1);
            auto blue = 0.0;

            auto int_red = static_cast<uint8_t>(red * 255.999);
            auto int_green = static_cast<uint8_t>(green * 255.999);
            auto int_blue = static_cast<uint8_t>(blue * 255.999);

            image_data[(i + j * image_width) * 3 + 0] = int_red;
            image_data[(i + j * image_width) * 3 + 1] = int_green;
            image_data[(i + j * image_width) * 3 + 2] = int_blue;
        }
    }

    savePixelsToImage("output.png", image_data, image_width, image_height);

    return 0;
}
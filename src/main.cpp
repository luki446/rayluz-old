#include "image_save.hpp"
#include "vec3.hpp"

int main(int argc, char** argv) {
    constexpr static size_t image_width{256};
    constexpr static size_t image_height{256};
    uint8_t image_data[image_width * image_height * 3]{0};

    for(int32_t row_index{0}; row_index < image_height; ++row_index) {
        for(int32_t column_index{0}; column_index < image_width; ++column_index) {
            auto pixel_color = Color{static_cast<float>(column_index) / image_width, static_cast<float>(row_index) / image_height, 0.0f};

            writeColorToBuffer(&image_data[(row_index * image_width + column_index) * 3], pixel_color);
        }
    }

    savePixelsToImage("output.png", image_data, image_width, image_height);

    return 0;
}
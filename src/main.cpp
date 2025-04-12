#include "image_save.hpp"

int main(int argc, char** argv) {
    constexpr static size_t image_width{256};
    constexpr static size_t image_height{256};
    uint8_t image_data[image_width * image_height * 3]{0};

    for(int32_t row_index{0}; row_index < image_height; ++row_index) {
        for(int32_t column_index{0}; column_index < image_width; ++column_index) {
            auto const red = static_cast<float>(column_index) / (image_width - 1);
            auto const green = static_cast<float>(row_index) / (image_height - 1);
            auto const blue = 0.0f;

            auto const int_red = static_cast<uint8_t>(red * 255.999);
            auto const int_green = static_cast<uint8_t>(green * 255.999);
            auto const int_blue = static_cast<uint8_t>(blue * 255.999);

            image_data[(column_index + row_index * image_width) * 3 + 0] = int_red;
            image_data[(column_index + row_index * image_width) * 3 + 1] = int_green;
            image_data[(column_index + row_index * image_width) * 3 + 2] = int_blue;
        }
    }

    savePixelsToImage("output.png", image_data, image_width, image_height);

    return 0;
}
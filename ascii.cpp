#include "headers/image_to_ascii.hpp"

#include <iostream>

//! Ubuntu: use Ctrl + '-' : zoom out , Ctrl + "+" : zoom in

/**
*     @author DidoHZ
*     @desc image to ascii
*
*     stb:
*       + sudo apt install libstb-dev
*
*     Usage: ./ascii <(required) image path> Options[<(optional) width> <(optional) height>]
*       ps: if you set only width, the height will be set automatically
*/

int main(int argc, char * argv[])
{
    if( argc < 2 ) exit(1);

    if(std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
        std::cout << "Usage: ./ascii <image path> <width> <height>" << std::endl;
        return 0;
    }

    std::string filename = argv[1];

    Image image = Image(filename.c_str());

    int width = argc > 2 ? atoi(argv[2]) : 80;
    int height = argc > 3 ? atoi(argv[3]) : (image.height / (float) image.width / 3.5) * width;

    // new image resolution
    image.resize(width, height);

    std::cout << "Image Properties : " << image.to_string() << std::endl;

    auto tooks = timing(&image, &image_to_ascii);

    std::cout << "\nProcess tooks: " << tooks << "ms" << std::endl;
    
    return 0;
}
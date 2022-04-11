#include "headers/image_to_ascii.hpp"

#include <iostream>
#include <stdexcept>

//! Ubuntu: use Ctrl + '-' : zoom out , Ctrl + "+" : zoom in

/**
*     @author DidoHZ
*     @desc image to ascii
*
*     stb:
*       + sudo apt install libstb-dev
*
*     Usage: ./ascii -f <(required) image path> Options[-width <(optional) width> -height <(optional) height>]
*       ps: if you set only width, the height will be set automatically
*/

int main(int argc, char * argv[])
{
    if(std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
        std::cout << "Usage: ./ascii -f <image path> -width <width> -height <height>" << std::endl;
        return 0;
    }

    char* filepath = getCmdOption(argv, argv + argc, "-f");

    if(!filepath)
        throw std::runtime_error("No path found.");

    std::cout << "next" << std::endl;
    
    Image image = Image(std::string(filepath).c_str());

    int width = 80, height = prefer_height(image.width, image.height, width);

    if(cmdOptionExists(argv, argv+argc, "-width")){
            char* _width = getCmdOption(argv, argv + argc, "-width");

            if(!_width)
                  throw std::runtime_error("No width value found.");

            width = atoi(_width);

            if(cmdOptionExists(argv, argv+argc, "-height")){
                  char* _height = getCmdOption(argv, argv + argc, "-height");

                  if(!_height)
                        throw std::runtime_error("No height value found.");
                  
                  height = atoi(_height);
            } else 
                  height = prefer_height(image.width, image.height, width);
      }

    // new image resolution
    image.resize(width, height);

    std::cout << "Image Properties : " << image.to_string() << std::endl;

    auto tooks = timing(&image, &image_to_ascii);

    std::cout << "\nProcess tooks: " << tooks << "ms" << std::endl;
    
    return 0;
}
#include "helpers.hpp"
#include "image.hpp"

#include <iostream>

#define DENSITY "N@#W$9876543210?!abc;:+=-,._                     "
#define DENSITY_SIZE 29

// RBG to ascii
char toAscii (float r, float g, float b){
    float _min = std::min(std::min(r, g), b);
	float _max = std::max(std::max(r, g), b);

    // RGB to HSL (Getting only Litness)
	float litness = (_max + _min) / 2;

    int index = mapper(litness, 0, 1, DENSITY_SIZE, 0);

    return DENSITY[index];
}

void image_to_ascii(Image* image){
    float r, g, b;
    
    std::string output ;

    for(int i = 0; i < image->width*image->height; ++i)
    {
        b = image->data[image->channels*i + 0] / 255.f;
        g = image->data[image->channels*i + 1] / 255.f;
        r = image->data[image->channels*i + 2] / 255.f;

        if(i % image->width == 0)
            output+='\n';

        output+=toAscii(r, g, b);        
    }
    
    std::cout << output ;
}

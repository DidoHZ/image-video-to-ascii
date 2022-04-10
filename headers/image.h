#if !defined(IMAGE)
#define IMAGE

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"

class Image {

    public:

    int width, height, channels;
    unsigned char* data;

    Image(){
        data = nullptr;
        width = 0;
        height = 0;
        channels = 0;
    }

    Image(std::string file_path){
        data = stbi_load(file_path.c_str(), &width, &height, &channels, 0);

        if(data == nullptr){
            std::cout << "error while loading image.	" << std::endl;
            exit(1);
        }
    }

    Image(unsigned char* data, int width, int height, int channels){
        this->data = data;
        this->width = width;
        this->height = height;
        this->channels = channels;
    }

    // Resizing Image with new Resolution (width * heigth)
    Image& resize(int width, int height){
        // allocating new image in memory
        unsigned char* tmp = (unsigned char *) malloc(this->width * this->height * this->channels);

        // resizing image with new data
        stbir_resize_uint8(data, this->width, this->height, 0, tmp, width, height, 0, this->channels);

        // clear old image data
        stbi_image_free(data);

        data = tmp;
        this->width = width;
        this->height = height;
        
        return *this;
    }

    std::string to_string(){
        return std::to_string(this->width) + "x" + std::to_string(this->height) + (this->channels == 3 ? " RGB" : " RGBA");
    }

    void destroy(){
        stbi_image_free(data);
        delete data;
    }

};

#endif // IMAGE
#include "headers/image_to_ascii.hpp"

#include <iostream>

using namespace std;

// Ubuntu: use Ctrl + '-' to zoom out , Ctrl

int main(int argc, char * argv[])
{
    if( argc < 2 ) exit(1);

    if(string(argv[1]) == "-h" || string(argv[1]) == "--help") {
        cout << "usage: ./ascii <image path>" << endl;
        return 0;
    }

    std::string filename = argv[1];

    Image image = Image(filename.c_str());

    // new image resolution
    int w = 250, h = 50;
    
    image.resize(w,h);

    cout << "Image Properties : " << image.to_string() << endl;

    auto tooks = timing(&image, &image_to_ascii);

    cout << "\nProcess tooks: " << tooks << "ms" << endl;
	
    image.destroy();
    
    return 0;
}
# image-video-to-ascii

C++ project for converting images, videos and camera stream to ascii code using third party libreries as [stblib](https://github.com/nothings/stb) and [opencv](https://github.com/opencv/opencv).

# Image to Ascii
Converting image to ascii using [stblib](https://github.com/nothings/stb) to process images.

<img src="resources/test.png" height="500" width="500"> <img src="resources/result.png" height="500" width="500">

### Required library [stb](https://github.com/nothings/stb) :
    sudo apt install libstb-dev


### Example :

    ./ascii -f ./resources/test.png

# Video/Camera to Ascii
Coverting videos and camera stream to ascii using [opencv](https://github.com/opencv/opencv) library.

### Libraries required:
* ### [stb](https://github.com/nothings/stb) (above):
 ### [opencv](https://github.com/opencv/opencv) :
    sudo apt install libopencv-dev

### Example :
* Normal usage open camera:

   > **./video_to_ascii**

* using arguments:

    * **video path:**
        > **./video_to_ascii -f ./resources/video.mp4**
    * **set width (height set automatically):**
        > **./video_to_ascii -f ./resources/video.mp4 -width 150**
    * **set width and height:**
        > **./video_to_ascii -f ./resources/video.mp4 -width 500 -height 150**

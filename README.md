# image-video-to-ascii

### library requirments:
* ### [stb](https://github.com/nothings/stb) :
  > sudo apt install libstb-dev
* ### [opencv](https://github.com/opencv/opencv) :
  > sudo apt install libopencv-dev

# Image to Ascii
Converting image to ascii using [stblib](https://github.com/nothings/stb) to process images.

![Figure 1-1](resources/test.png)

![Figure 1-2](https://cdn-149.anonfiles.com/R2G32cVbx6/a86367dd-1649612919/Screenshot%20from%202022-04-10%2018-28-39.png)

### Example :

    > ./ascii ./resources/test.png

# Video/Camera to Ascii
Coverting videos and camera stream to ascii using [opencv](https://github.com/opencv/opencv) library.

### Example :
* Normal usage open camera:

    > ./video_to_ascii

* using arguments:

    * video path:
        > ./video_to_ascii ./resources/video.mp4
    * set width <b>(height set automatically)</b>:
        > ./video_to_ascii ./resources/video.mp4 150
    * set width & height:
        > ./video_to_ascii ./resources/video.mp4 500 150
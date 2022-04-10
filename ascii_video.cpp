#include <opencv2/opencv.hpp>
#include <iostream>

#include "headers/video_to_ascii.h"

using namespace cv; 

/*
*     sudo apt-get install libopencv-dev
*
*     @Auth DidoHZ
*     @Desc Video/Camera to ascii
*
*     Usage: ./ascii_video <video path (Optional)>  <Default: Open Camera>
*/

int main(int argc, char* argv[])
{
      // Creating VideoCapture object and opening webcam
      VideoCapture cap = argc >= 2 ? VideoCapture(argv[1]) : VideoCapture(0);


       //Checking if opened 
      if(!cap.isOpened()) 
      {
            cout << (argc >= 2 ? "Cannot open the video file" : "Error opening Web cam") << endl;
            return -1;
      }

      // Converting video to ascii
      video_to_ascii(&cap);

      // When everything done, release the video capture object
      cap.release();
      // Closes all the frames
      destroyAllWindows();
      return 0;
}

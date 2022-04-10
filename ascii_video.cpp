#include "headers/video_to_ascii.hpp"

//! Ubuntu: use Ctrl + '-' : zoom out , Ctrl + "+" : zoom in

/**  
*     @author DidoHZ
*     @desc Video/Camera to ascii
*
*     stb:
*        + sudo apt install libstb-dev
*     opencv: 
*        + sudo apt-get install libopencv-dev
*
*     Usage: ./ascii_video <video path (Optional)> [Default: Open Camera] Options[<(optional) width> <(optional) height>]
*       ps: if you set only width, the height will be set automatically
*/

int main(int argc, char* argv[])
{
      // Creating VideoCapture object and opening webcam
      cv::VideoCapture cap = argc >= 2 ? cv::VideoCapture(argv[1]) : cv::VideoCapture(0);

       //Checking if opened 
      if(!cap.isOpened()) 
      {
            std::cout << (argc >= 2 ? "Cannot open the video file" : "Error opening Web cam") << std::endl;
            return -1;
      }


      int width = argc > 2 ? atoi(argv[2]) : 80;
      int height = argc > 3 ? atoi(argv[3]) : (cap.get(4) / (float) cap.get(3) / 3.5) * width;

      // Converting video to ascii
      video_to_ascii(&cap, cv::Size(width, height));

      // When everything done, release the video capture object
      cap.release();
      // Closes all the frames
      cv::destroyAllWindows();
      return 0;
}

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
*     Usage: ./ascii_video -f <video path (Optional)> [Default: Open Camera] Options[-width <(optional) width> -height <(optional) height>]
*       ps: if you set only width, the height will be set automatically
*/

int main(int argc, char* argv[])
{
      // Creating VideoCapture object and opening webcam
      cv::VideoCapture cap;

      if(cmdOptionExists(argv, argv+argc, "-f")){
                  char* filepath = getCmdOption(argv, argv + argc, "-f");

                  if(!filepath)
                        throw std::runtime_error("No path found.");
                  
                  cap = cv::VideoCapture(filepath);
      }else
            cap = cv::VideoCapture(0);

       //Checking if opened 
      if(!cap.isOpened()) 
            throw std::runtime_error(argc >= 2 ? "Cannot open the video file" : "Error opening Web cam");


      int width = 80, height = (cap.get(4) / (float) cap.get(3) / 3.5) * width;

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
                  height = (cap.get(4) / (float) cap.get(3) / 3.5) * width;
      }

      // Converting video to ascii
      video_to_ascii(&cap, cv::Size(width, height));

      // When everything done, release the video capture object
      cap.release();
      // Closes all the frames
      cv::destroyAllWindows();
      return 0;
}

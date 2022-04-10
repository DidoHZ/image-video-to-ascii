#if !defined(VIDEO_TO_ASCII)
#define VIDEO_TO_ASCII

#include <opencv2/opencv.hpp>

#include "image_to_ascii.hpp"


void video_to_ascii(cv::VideoCapture* cap, cv::Size size){
    Image image = Image();

      while(1)
      {     
            // Creating Mat object
            cv::Mat frame; 
            // Capture frame-by-frame
            *cap >> frame;  
            
            // If the frame is empty, break immediately
            if (frame.empty())
                  break;

            cv::Mat resized;

            // resize frame
            resize(frame, resized, size);

            image = Image((unsigned char*) resized.data , resized.cols, resized.rows, resized.channels());

            image_to_ascii(&image);

            // Display the frame 
            imshow( "Video Frames", frame );

            //Press ESC on keyboard to exit/
            char a=(char)cv::waitKey(25);

            if(a==27)
                  break;
      } 
}

#endif // VIDEO_TO_ASCII
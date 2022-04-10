#include <opencv2/opencv.hpp>

#include "image_to_ascii.h"


void video_to_ascii(cv::VideoCapture* cap){
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

            // resize frame to w:250 x h:50
            resize(frame, resized, cv::Size(250*2, 50*2));

            image = Image((unsigned char*) resized.data , resized.cols, resized.rows, resized.channels());

            image_to_ascii(&image);

            // Display the frame 
            imshow( "VdoFrame", frame );

            //Press ESC on keyboard to exit/
            char a=(char)cv::waitKey(25);

            if(a==27)
                  break;
      } 
}
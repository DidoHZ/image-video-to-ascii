cmake_minimum_required(VERSION 3.0)
set( CMAKE_TOOLCHAIN_FILE cmake(1) )
project(test)

add_executable(ascii_video ascii_video.cpp ./headers/video_to_ascii.hpp)

find_package(OpenCV CONFIG REQUIRED)

if(OpenCV_FOUND)

    # Additional Include Directories
    include_directories( ${OpenCV_INCLUDE_DIRS} )

    # Additional Library Directories
    link_directories( ${OpenCV_LIB_DIR} )

    # Additional output Directory
    set(EXECUTABLE_OUTPUT_PATH ./build)

    # Additional Dependencies
    target_link_libraries( ascii_video ${OpenCV_LIBS} )

endif()
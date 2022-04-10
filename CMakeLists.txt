cmake_minimum_required(VERSION 3.0)
set( CMAKE_TOOLCHAIN_FILE "/home/dido/Desktop/c++/vcpkg/scripts/buildsystems/vcpkg.cmake" )
project(test)

add_executable(main ascii_video.cpp)

set( OpenCV "/home/dido/Desktop/c++/vcpkg/installed/x64-linux/share/opencv" )

find_package(OpenCV CONFIG REQUIRED)

if(OpenCV_FOUND)

    # Additional Include Directories
    include_directories( ${OpenCV_INCLUDE_DIRS} )

    # Additional Library Directories
    link_directories( ${OpenCV_LIB_DIR} )

    # Additional Dependencies
    target_link_libraries( main ${OpenCV_LIBS} )

endif()
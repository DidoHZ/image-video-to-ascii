#include <chrono>
#include "image.hpp"

/* 
* Mapping a number from range to a new_range value

* x = 50
* in_min = 0 , in_max = 100
* out_min = 0 , out_max = 1
*
* 50 [0,100] => 0.5 [0,1]
*/
float mapper(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// calculate a process timing in (ms)
int timing(Image* image,void (*func)(Image*)){
    auto start = std::chrono::system_clock::now();

    func(image);

    auto end = std::chrono::system_clock::now();
    	
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);

    return elapsed.count();
}
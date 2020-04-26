#include "HelloWorld.h"

void HelloWorld::say() {
 std::cout << "Hello, World"; 
}
/*cmake_minimum_required(VERSION 3.0.0)
project(cab301)

set(CMAKE_CXX_STANDARD 14) # enable c++14 CMAKE_CXX_STANDARD

include_directories(
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS

        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

add_executable(cab301 ${all_SRCS})
*/
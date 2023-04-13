cmake_minimum_required(VERSION 3.0.0)
project(particle_filter_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui opencv_imgcodecs)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})

# add_subdirectory(app)

add_executable(particle_filter_cpp include/bee-map.h app/bee-map.cpp app/main.cpp)

target_link_libraries(particle_filter_cpp ${OpenCV_LIBS})

project(GPSPathList CXX)

add_executable(GPSPathList GPSPathList.cc gps_trail_list.cc)

add_executable(GPSPath GPSPath.cc GPSCoord.cc gps_trail_vector.cc)

set(CMAKE_BUILD_TYPE Debug)

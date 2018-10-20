cmake_minimum_required(VERSION 2.8.4)
project(ObservableCache)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -pedantic -I/home/anand/git/ObservableCache")
# Generate shared library libArrayBlockingQueue.so file.
ADD_LIBRARY(ObservableCache SHARED ObservableCache.cpp ThreadSafeCache.cpp)

add_executable(examples/Example1.out examples/Example1.cpp)
add_executable(examples/Example2.out examples/Example2.cpp)
add_executable(examples/Example3.out examples/Example3.cpp)
add_executable(examples/Example4.out examples/Example4.cpp)
add_executable(examples/Example5.out examples/Example5.cpp)
add_executable(examples/Example6.out examples/Example6.cpp)

target_link_libraries(examples/Example1.out ObservableCache pthread)
target_link_libraries(examples/Example2.out ObservableCache pthread)
target_link_libraries(examples/Example3.out ObservableCache pthread)
target_link_libraries(examples/Example4.out ObservableCache pthread)
target_link_libraries(examples/Example5.out ObservableCache pthread)
target_link_libraries(examples/Example6.out ObservableCache pthread)

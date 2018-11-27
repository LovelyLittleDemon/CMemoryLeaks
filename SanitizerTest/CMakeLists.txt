CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(SanitizerTest)
#this is for memory leaks flags, if -O1, memory check is no effective
set(CMAKE_CXX_FLAGS "-g -fsanitize=address -fno-omit-frame-pointer") 
#set(CMAKE_CXX_FLAGS "-O1 -g -fsanitize=address -fno-omit-frame-pointer")
ADD_EXECUTABLE(main src/sanitize_test.cpp src/main.cpp)

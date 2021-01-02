cmake_minimum_required(VERSION 3.1)
project(Data_Structures_Cpp VERSION 0.1.0 LANGUAGES CXX)

include_directories(include)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_executable(chapter05 src/chapter05.cpp )
target_compile_features(chapter05 PUBLIC cxx_std_17)
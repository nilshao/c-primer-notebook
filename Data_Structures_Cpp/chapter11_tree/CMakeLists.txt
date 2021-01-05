cmake_minimum_required(VERSION 3.1)
project(chapter11_tree VERSION 0.1.0 LANGUAGES CXX)

include_directories(include)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_executable(binaryTree src/binaryTree.cpp )
target_compile_features(binaryTree PUBLIC cxx_std_17)
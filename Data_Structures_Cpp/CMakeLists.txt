cmake_minimum_required(VERSION 3.1)
project(Data_Structures_Cpp VERSION 0.1.0 LANGUAGES CXX)

include_directories(include)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_executable(arrayList src/chapter05/arrayList.cpp )
target_compile_features(arrayList PUBLIC cxx_std_17)

add_executable(chain src/chapter06/chain.cpp )
target_compile_features(chain PUBLIC cxx_std_17)
cmake_minimum_required(VERSION 3.0.0)
project(template_tut VERSION 0.1.0)


add_executable(template_tut1 main1.cpp)
target_compile_features(template_tut1 PRIVATE cxx_std_20)

add_executable(template_tut2 main2.cpp)
target_compile_features(template_tut2 PRIVATE cxx_std_20)
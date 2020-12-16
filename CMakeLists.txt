cmake_minimum_required(VERSION 3.17)
project(cpp_templates_the_complete_guide)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(src)

add_executable(test_stack test_stack.cc)
target_link_libraries(test_stack stack)
target_include_directories(test_stack PUBLIC src)

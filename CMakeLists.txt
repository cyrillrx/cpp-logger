project(CppLogger)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include(conanbuildinfo.cmake)
conan_basic_setup()

option(BUILD_TEST "Build the tests" FALSE)

add_library(logger
        src/logger.cpp
        src/logger.h
        src/console_logger.cpp
        src/console_logger.h
        src/logger_manager.cpp
        src/logger_manager.h)
target_link_libraries(logger ${CONAN_LIBS})

IF(BUILD_TEST)
    add_executable(test_logger test/test_logger.cpp)
    target_link_libraries(test_logger logger ${CONAN_LIBS})
ENDIF()
project(CppLogger)
cmake_minimum_required(VERSION 3.0)

include(conanbuildinfo.cmake)
conan_basic_setup()

option(BUILD_TEST "Build the tests" FALSE)

add_library(logger
        src/main/logger.cpp
        src/main/logger.h
        src/main/console_logger.cpp
        src/main/console_logger.h
        src/main/logger_manager.cpp
        src/main/logger_manager.h)
target_link_libraries(logger ${CONAN_LIBS})

IF(BUILD_TEST)
    add_executable(test_logger src/test/test_logger.cpp)
    target_link_libraries(test_logger logger ${CONAN_LIBS})
ENDIF()
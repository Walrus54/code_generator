cmake_minimum_required( VERSION 3.12 )

project( code_generator LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

# Библиотека генератора: все .cpp из src/.
file( GLOB_RECURSE CODEGEN_SOURCES CONFIGURE_DEPENDS src/*.cpp )
add_library( codegen STATIC ${CODEGEN_SOURCES} )
target_include_directories( codegen PUBLIC src )

# Демонстрационная программа.
add_executable( code_generator main.cpp examples.cpp )
target_link_libraries( code_generator PRIVATE codegen )
target_include_directories( code_generator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )

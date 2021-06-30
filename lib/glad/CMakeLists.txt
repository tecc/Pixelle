cmake_minimum_required(VERSION 3.16)
project(glad C)

add_library(glad src/gl.c)
target_include_directories(glad PUBLIC include)

set(GLAD_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)
# add -fPIC compile flag
get_target_property(GLAD_COMPILE_FLAGS glad COMPILE_FLAGS)
if (GLAD_COMPILE_FLAGS STREQUAL "GLAD_COMPILE_FLAGS-NOTFOUND")
    set(GLAD_COMPILE_FLAGS "")
endif()
set(GLAD_COMPILE_FLAGS ${GLAD_COMPILE_FLAGS} "-fPIC")
set_target_properties(glad PROPERTIES COMPILE_FLAGS "${GLAD_COMPILE_FLAGS}")
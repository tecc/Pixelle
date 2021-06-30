cmake_minimum_required(VERSION 3.19)
project(Pixelle)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

option(PIXELLE_BUILD_SHARED_LIBRARY "Whether or not to build a shared or static library" OFF)
if (PIXELLE_BUILD_SHARED_LIBRARY)
    set(PIXELLE_LIBRARY_TYPE "SHARED")
else()
    set(PIXELLE_LIBRARY_TYPE "STATIC")
endif()
message(STATUS "Pixelle library type: ${PIXELLE_LIBRARY_TYPE}")

include(Util)
set(PIXELLE_GRAPHICS_API gl)

prefix_list(PIXELLE_GRAPHICS_SOURCES src/graphics/${PIXELLE_GRAPHICS_API}/
    GraphicsAPI.cpp
    Texture.cpp
    )

prefix_list(PIXELLE_UTIL_SOURCES src/util/
    Util.cpp
    Colour.cpp
    Math.cpp
    Exception.cpp
    )

prefix_list(PIXELLE_SOURCES src/
    Engine.cpp
    )

add_library(Pixelle ${PIXELLE_LIBRARY_TYPE}
    ${PIXELLE_GRAPHICS_SOURCES}
    ${PIXELLE_UTIL_SOURCES}
    ${PIXELLE_SOURCES}
    )
list(APPEND PIXELLE_INCLUDE_DIRS_PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include-tcc)
list(APPEND PIXELLE_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/include)

if (${PIXELLE_GRAPHICS_API} MATCHES "gl")
    # GLFW
    message(STATUS "Including GLFW")
    set(GLFW_BUILD_EXAMPLES OFF)
    set(GLFW_BUILD_TESTS OFF)
    set(GLFW_BUILD_DOCS ON)
    set(GLFW_VULKAN_STATIC OFF)
    add_subdirectory(lib/glfw)
    list(APPEND PIXELLE_LIBRARIES glfw)
    list(APPEND PIXELLE_INCLUDE_DIRS_PRIVATE ${GLFW_INCLUDE_DIRS})

    # GLAD
    message(STATUS "Including GLAD2")
    add_subdirectory(lib/glad)
    list(APPEND PIXELLE_LIBRARIES glad)
    list(APPEND PIXELLE_INCLUDE_DIRS_PRIVATE ${GLAD_INCLUDE_DIRS})
endif()

target_link_libraries(Pixelle ${PIXELLE_LIBRARIES})
target_include_directories(Pixelle PRIVATE ${PIXELLE_INCLUDE_DIRS_PRIVATE})
target_include_directories(Pixelle PUBLIC ${PIXELLE_INCLUDE_DIRS})

# tests
add_subdirectory(test)
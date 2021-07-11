cmake_minimum_required(VERSION 3.19)
project(Pixelle)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

option(PIXELLE_BUILD_SHARED_LIBRARY "Whether or not to build a shared or static library" OFF)
option(PIXELLE_BUILD_TOOLS "Whether or not to build Pixelle tools" ON)
if (PIXELLE_BUILD_SHARED_LIBRARY)
    set(PIXELLE_LIBRARY_TYPE "SHARED")
else()
    set(PIXELLE_LIBRARY_TYPE "STATIC")
endif()
set(PIXELLE_PLATFORM_NAME linux) # TODO: make compatible with Windows & MacOS
message(STATUS "Pixelle library type: ${PIXELLE_LIBRARY_TYPE}")

include(Util)
set(PIXELLE_GRAPHICS_API gl)

# Graphics API sources
prefix_list(PIXELLE_GRAPHICS_SOURCES src/graphics/${PIXELLE_GRAPHICS_API}/
    GraphicsAPI.cpp
    Texture.cpp
    RenderObject.cpp
    )

# Utility sources
prefix_list(PIXELLE_UTIL_SOURCES src/util/
    Util.cpp Util_${PIXELLE_PLATFORM_NAME}.cpp
    Colour.cpp
    Math.cpp
    Exception.cpp
    )

# Resources sources
prefix_list(PIXELLE_RESOURCES_SOURCES src/resources/
    Resource.cpp
    )

# Base sources
prefix_list(PIXELLE_SOURCES src/
    Engine.cpp
    )

# Add library
add_library(Pixelle ${PIXELLE_LIBRARY_TYPE}
    ${PIXELLE_GRAPHICS_SOURCES}
    ${PIXELLE_UTIL_SOURCES}
    ${PIXELLE_RESOURCES_SOURCES}
    ${PIXELLE_SOURCES}
    )
# Set private and public include directories
list(APPEND PIXELLE_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/include-tcc)
find_package(PkgConfig REQUIRED)

# nlohmann-json / JSON for Modern C++
message(STATUS "Including nlohmann-json")
add_subdirectory(lib/json)
list(APPEND PIXELLE_LIBRARIES nlohmann_json)

# zlib: compression
message(STATUS "Using zlib for compression")
pkg_check_modules(ZLIB REQUIRED zlib)
list(APPEND PIXELLE_LIBRARIES ${ZLIB_LIBRARIES})
list(APPEND PIXELLE_INCLUDE_DIRS_PRIVATE ${ZLIB_INCLUDE_DIRS})

# LibBSD: utilities
message(STATUS "Using LibBSD")
pkg_check_modules(LIBBSD REQUIRED libbsd)
list(APPEND PIXELLE_LIBRARIES ${LIBBSD_LIBRARIES})
list(APPEND PIXELLE_LIBRARIES ${LIBBSD_INCLUDE_DIRS})

if (${PIXELLE_GRAPHICS_API} MATCHES "gl")
    # GLFW
    message(STATUS "Including GLFW")
    set(GLFW_BUILD_EXAMPLES OFF)
    set(GLFW_BUILD_TESTS OFF)
    set(GLFW_BUILD_DOCS ON)
    set(GLFW_VULKAN_STATIC OFF)
    add_subdirectory(lib/glfw)
    list(APPEND PIXELLE_LIBRARIES glfw)
    list(APPEND PIXELLE_INCLUDE_DIRS ${GLFW_INCLUDE_DIRS})

    # GLAD
    message(STATUS "Including GLAD2")
    add_subdirectory(lib/glad)
    list(APPEND PIXELLE_LIBRARIES glad)
    list(APPEND PIXELLE_INCLUDE_DIRS ${GLAD_INCLUDE_DIRS})
endif()

# Link libraries and directories
target_link_libraries(Pixelle ${PIXELLE_LIBRARIES})
target_include_directories(Pixelle PUBLIC ${PIXELLE_INCLUDE_DIRS})

set(PIXELLE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# Tools
if (PIXELLE_BUILD_TOOLS)
    message(STATUS "Including Argh! library")
    add_subdirectory(lib/argh)

    message(WARNING "Pixelle has no tools for now!")
endif()

# Test game
add_subdirectory(test)
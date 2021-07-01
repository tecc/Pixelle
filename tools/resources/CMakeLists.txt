cmake_minimum_required(VERSION 3.17)
project(PixelleResources)

add_executable(pixelle-resources 
    src/main.cpp src/Manifest.cpp
    # Actions
    src/actions/help.cpp src/actions/init.cpp
    )

find_package(PkgConfig REQUIRED)
pkg_check_modules(ZLIB REQUIRED zlib)
target_include_directories(pixelle-resources PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include ${PIXELLE_INCLUDE_DIRS} ${PIXELLE_INCLUDE_DIRS_PRIVATE} ${ZLIB_INCLUDE_DIRS}
    )
target_link_libraries(pixelle-resources Pixelle nlohmann_json argh ${ZLIB_LIBRARIES})
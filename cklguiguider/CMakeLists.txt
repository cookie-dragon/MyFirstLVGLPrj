cmake_minimum_required(VERSION 3.12.4)
project(cklguiguider VERSION 0.1.0 LANGUAGES C CXX)

# Set C and C++ standards
set(CMAKE_C_STANDARD 99) # C99 # lvgl officially support C99 and above
set(CMAKE_CXX_STANDARD 17) # C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output path for the library
if(UNIX)
    # Set the output path for the library
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../output/lib)
elseif(WIN32)
    # Set the output path for the library
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../output)
endif()

if(WIN32)
    # Find and include SDL2 library
    find_package(SDL2 REQUIRED)
    add_definitions(-DLIBSDL=1)
endif()

if(UNIX)
    target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR})
elseif(WIN32)
    target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})
endif()

FILE(GLOB_RECURSE PRJ_SRC CONFIGURE_DEPENDS "./custom/*.c" "./generated/*.c")
FILE(GLOB_RECURSE PRJ_INC CONFIGURE_DEPENDS "./custom/*.h" "./generated/*.h")

# 由于包含全局变量，故只能使用静态链接库的方式
add_library(${PROJECT_NAME} STATIC ${PRJ_SRC} ${PRJ_INC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/custom)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/generated)

if(UNIX)
    find_package(SDL2)

    if(SDL2_FOUND)
        add_definitions(-DLIBSDL=1)
    else()
        add_definitions(-DLIBSDL=0)
    endif()

    find_package(SDL2_image)
    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
endif()

if(UNIX)
    target_link_libraries(${PROJECT_NAME} lvgl lvgl::examples lvgl::demos lvgl::thorvg ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${Libdrm_LIBRARIES} m pthread)
elseif(WIN32)
    # Define LVGL configuration as a simple include
    target_compile_definitions(${PROJECT_NAME} PRIVATE LV_CONF_INCLUDE_SIMPLE)
    target_link_libraries(${PROJECT_NAME} lvgl lvgl::examples lvgl::demos lvgl::thorvg ${SDL2_LIBRARIES} m pthread)
endif()

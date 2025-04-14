cmake_minimum_required(VERSION 3.10)
project(myfirstlvglprj C CXX)

if(UNIX)
    add_definitions(-DSYSUNIX=1)
    add_definitions(-DSYSWIN32=0)
elseif(WIN32)
    add_definitions(-DSYSUNIX=0)
    add_definitions(-DSYSWIN32=1)
endif()

# Main include files of the project
FILE(GLOB_RECURSE PRJ_INC CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/main/include
)
include_directories(${PRJ_INC})

if(WIN32)
    # Define options for LVGL with default values (OFF)
    option(LV_USE_DRAW_SDL "Use SDL draw unit" OFF)
    option(LV_USE_LIBPNG "Use libpng to decode PNG" OFF)
    option(LV_USE_LIBJPEG_TURBO "Use libjpeg turbo to decode JPEG" OFF)
    option(LV_USE_FFMPEG "Use libffmpeg to display video using lv_ffmpeg" OFF)
    option(LV_USE_FREETYPE "Use freetype library" OFF)
endif()

# Set C and C++ standards
set(CMAKE_C_STANDARD 99) # C99 # lvgl officially support C99 and above
set(CMAKE_CXX_STANDARD 17) # C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(WIN32)
cmake_policy(SET CMP0167 NEW)
endif()

if(UNIX)
    # Set the output path for the executable
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output/bin)

    # Set the output path for the library
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output/lib)
elseif(WIN32)
    # Set the output path for the executable
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)

    # Set the output path for the library
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)
endif()

if(WIN32)
    # Find and include SDL2 library
    find_package(SDL2 REQUIRED)
    add_definitions(-DLIBSDL=1)
endif()

# 查找 Boost 库，添加组件
find_package(Boost REQUIRED COMPONENTS filesystem system thread)
include_directories(${Boost_INCLUDE_DIRS})

if(WIN32)
    # Remove ARM-specific compile and linker options
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

if(WIN32)
    # Add compile definitions based on the selected options
    add_compile_definitions($<$<BOOL:${LV_USE_DRAW_SDL}>:LV_USE_DRAW_SDL=1>)
    add_compile_definitions($<$<BOOL:${LV_USE_LIBPNG}>:LV_USE_LIBPNG=1>)
    add_compile_definitions($<$<BOOL:${LV_USE_LIBJPEG_TURBO}>:LV_USE_LIBJPEG_TURBO=1>)
    add_compile_definitions($<$<BOOL:${LV_USE_FFMPEG}>:LV_USE_FFMPEG=1>)
endif()

# Add LVGL subdirectory
add_subdirectory(lvgl)

if(UNIX)
    target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR})
elseif(WIN32)
    target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})
endif()

# Add BSP subdirectory
add_subdirectory(cklhmibsp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cklhmibsp/include)

# Add View subdirectory
add_subdirectory(ckldemos)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ckldemos/include)

# Add Gui Guider subdirectory
add_subdirectory(cklguiguider)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cklguiguider/custom)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cklguiguider/generated)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cklguiguider/generated/guider_customer_fonts)

# Add SquareLine Stuido subdirectory
add_subdirectory(cklsquarelinestudio)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cklsquarelinestudio)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/cklsquarelinestudio/components)

# 100ask不完全适配linux环境
if(WIN32)
    # Add 100ask_lesson_demos subdirectory
    add_subdirectory(lv_100ask_lesson_demos)
endif()

FILE(GLOB_RECURSE PRJ_SRC CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/main/src/mouse_cursor_icon.c
    ${PROJECT_SOURCE_DIR}/main/src/main.c
)
add_executable(${PROJECT_NAME} ${PRJ_SRC})

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

# Custom target to run the executable
add_custom_target(run COMMAND ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME} DEPENDS ${PROJECT_NAME})

# 链接 Boost 库
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

target_link_libraries(${PROJECT_NAME} cklhmibsp)
target_link_libraries(${PROJECT_NAME} ckldemos)
target_link_libraries(${PROJECT_NAME} cklguiguider)
target_link_libraries(${PROJECT_NAME} cklsquarelinestudio)

# 100ask不完全适配linux环境
if(WIN32)
    target_link_libraries(${PROJECT_NAME} lv_100ask_lesson_demos)
endif()

if(WIN32)
    # Conditionally include and link SDL2_image if LV_USE_DRAW_SDL is enabled
    if(LV_USE_DRAW_SDL)
        set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
        find_package(SDL2_image REQUIRED)
        target_include_directories(lvgl PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
        target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})
    endif()

    # Conditionally include and link libpng if LV_USE_LIBPNG is enabled
    if(LV_USE_LIBPNG)
        find_package(PNG REQUIRED)
        target_include_directories(lvgl PUBLIC ${PNG_INCLUDE_DIRS})
        target_link_libraries(${PROJECT_NAME} ${PNG_LIBRARIES})
    endif()

    # Conditionally include and link libjpeg-turbo if LV_USE_LIBJPEG_TURBO is enabled
    if(LV_USE_LIBJPEG_TURBO)
        find_package(JPEG REQUIRED)
        target_include_directories(lvgl PUBLIC ${JPEG_INCLUDE_DIRS})
        target_link_libraries(${PROJECT_NAME} ${JPEG_LIBRARIES})
    endif()

    # Conditionally include and link FFmpeg libraries if LV_USE_FFMPEG is enabled
    if(LV_USE_FFMPEG)
        target_link_libraries(${PROJECT_NAME} avformat avcodec avutil swscale z)
    endif()

    # Conditionally include and link FreeType if LV_USE_FREETYPE is enabled
    if(LV_USE_FREETYPE)
        find_package(Freetype REQUIRED)
        target_include_directories(lvgl PUBLIC ${FREETYPE_INCLUDE_DIRS})
        target_link_libraries(${PROJECT_NAME} ${FREETYPE_LIBRARIES})
    endif()
endif()

if(WIN32)
    # Apply additional compile options if the build type is Debug
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Debug mode enabled")

        target_compile_options(lvgl PRIVATE
            -pedantic-errors
            -Wall
            -Wclobbered
            -Wdeprecated
            -Wdouble-promotion
            -Wempty-body
            -Wextra
            -Wformat-security
            -Wmaybe-uninitialized

            # -Wmissing-prototypes
            -Wpointer-arith
            -Wmultichar
            -Wno-pedantic # ignored for now, we convert functions to pointers for properties table.
            -Wreturn-type
            -Wshadow
            -Wshift-negative-value
            -Wsizeof-pointer-memaccess
            -Wtype-limits
            -Wundef
            -Wuninitialized
            -Wunreachable-code
            -Wfloat-conversion
            -Wstrict-aliasing
        )

        if(ASAN)
            message(STATUS "AddressSanitizer enabled")

            # Add AddressSanitizer flags
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
            set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
            set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fsanitize=address")
        else()
            message(STATUS "AddressSanitizer disabled")
        endif()
    endif()
endif()
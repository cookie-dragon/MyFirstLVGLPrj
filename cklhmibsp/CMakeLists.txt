cmake_minimum_required(VERSION 3.12.4)
project(cklhmibsp VERSION 0.1.0 LANGUAGES C CXX)

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

# find_package(Boost COMPONENTS system REQUIRED)
# include_directories(${Boost_INCLUDE_DIRS})
FILE(GLOB_RECURSE PRJ_SRC CONFIGURE_DEPENDS "./src/*.cpp")
FILE(GLOB_RECURSE PRJ_INC CONFIGURE_DEPENDS "./include/*.h")

add_library(${PROJECT_NAME} SHARED ${PRJ_SRC} ${PRJ_INC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})

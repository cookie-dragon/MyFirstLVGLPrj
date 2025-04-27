cmake_minimum_required(VERSION 3.12.4)
project(cklhmiutils VERSION 0.1.0 LANGUAGES C CXX)

# Set C and C++ standards
set(CMAKE_C_STANDARD 99) # C99 # lvgl officially support C99 and above
set(CMAKE_CXX_STANDARD 17) # C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    cmake_policy(SET CMP0167 NEW)
endif()

# Set the output path for the library
if(UNIX)
    # Set the output path for the library
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../output/lib)
elseif(WIN32)
    # Set the output path for the library
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../output)
endif()

# 查找 Boost 库，添加组件
find_package(Boost REQUIRED COMPONENTS filesystem system thread)
include_directories(${Boost_INCLUDE_DIRS})

# 查找 openssl 库
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

# 查找 Google Test 包
if(WIN32)
    find_package(GTest REQUIRED)
    include_directories(${GTest_INCLUDE_DIRS})
endif()

FILE(GLOB_RECURSE PRJ_SRC CONFIGURE_DEPENDS "./src/*.cpp" "./src/*.c")
FILE(GLOB_RECURSE PRJ_INC CONFIGURE_DEPENDS "./include/*.h")

add_library(${PROJECT_NAME} SHARED ${PRJ_SRC} ${PRJ_INC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 链接 Boost 库
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

# 链接 openssl 库
target_link_libraries(${PROJECT_NAME} ${OPENSSL_LIBRARIES})

# 添加测试可执行文件、链接 Google Test 库
if(WIN32)
    add_executable(${PROJECT_NAME}Tests test/libcklhmiutilstest.cpp ${PRJ_SRC} ${PRJ_INC})
    target_include_directories(${PROJECT_NAME}Tests PUBLIC ${PROJECT_SOURCE_DIR}/include)

    target_link_libraries(${PROJECT_NAME}Tests ${Boost_LIBRARIES})
    target_link_libraries(${PROJECT_NAME}Tests ${OPENSSL_LIBRARIES})
    target_link_libraries(${PROJECT_NAME}Tests ${PROJECT_NAME} )
    target_link_libraries(${PROJECT_NAME}Tests GTest::gtest_main pthread)
endif()

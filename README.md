# MyFirstLVGLPrj
My first LVGL project

## 一、	在Windows上搭建LVGL开发环境

### 1   安装/配置类Linux环境

#### 1.1	安装msys2

- msys2-x86_64-20230718.exe

#### 1.2	在MSYS2中安装必备库

- 更新软件列表和已安装软件

执行两遍
```bash
pacman -Syu
```

- 安装必备软件包

```bash
# 基础
pacman -S mingw64/mingw-w64-x86_64-cmake
pacman -S mingw64/mingw-w64-x86_64-gcc
pacman -S mingw64/mingw-w64-x86_64-gdb
pacman -S mingw64/mingw-w64-x86_64-make

# C++和LVGL依赖
pacman -S mingw64/mingw-w64-x86_64-boost
pacman -S mingw64/mingw-w64-x86_64-SDL2

# 其它库
pacman -S mingw64/mingw-w64-x86_64-poppler
pacman -S mingw64/mingw-w64-x86_64-qrencode
pacman -S mingw64/mingw-w64-x86_64-openssl
pacman -S mingw64/mingw-w64-x86_64-libjpeg-turbo
pacman -S mingw64/mingw-w64-x86_64-libpng
pacman -S mingw64/mingw-w64-x86_64-freetype
```

### 2	安装IDE

#### 2.1	安装Visual Studio Code

- VisualStudioSetup.exe

##### 2.1.1	安装扩展

```
Chinese (Simplified) (简体中文) Language Pack for Visual Studio Code
Doxygen Documentation Generator
C/C++ Extension Pack
CMake Language Support
```

#### 2.2	配置Visual Studio Code

##### 2.2.1	配置注释生成器

```json
{
    // The prefix that is used for each comment line except for first and last.
    "doxdocgen.c.commentPrefix": " * ",
    // Smart text snippet for factory methods/functions.
    "doxdocgen.c.factoryMethodText": "Create a {name} object",
    // The first line of the comment that gets generated. If empty it won't get generated at all.
    "doxdocgen.c.firstLine": "/**",
    // Smart text snippet for getters.
    "doxdocgen.c.getterText": "Get the {name} object",
    // The last line of the comment that gets generated. If empty it won't get generated at all.
    "doxdocgen.c.lastLine": " */",
    // Smart text snippet for setters.
    "doxdocgen.c.setterText": "Set the {name} object",
    // Doxygen comment trigger. This character sequence triggers generation of Doxygen comments.
    "doxdocgen.c.triggerSequence": "/**",
    // Smart text snippet for constructors.
    "doxdocgen.cpp.ctorText": "Construct a new {name} object",
    // Smart text snippet for destructors.
    "doxdocgen.cpp.dtorText": "Destroy the {name} object",
    // The template of the template parameter Doxygen line(s) that are generated. If empty it won't get generated at all.
    "doxdocgen.cpp.tparamTemplate": "@tparam {param} ",
    // File copyright documentation tag.  Array of strings will be converted to one line per element.  Can template {year}.
    "doxdocgen.file.copyrightTag": [
        "@copyright Copyright (c) My Company {year}"
    ],
    // Additional file documentation. One tag per line will be added. Can template `{year}`, `{date}`, `{author}`, `{email}` and `{file}`. You have to specify the prefix.
    "doxdocgen.file.customTag": [],
    // The order to use for the file comment. Values can be used multiple times. Valid values are shown in default setting.
    "doxdocgen.file.fileOrder": [
        "file",
        "author",
        "brief",
        "date",
        "empty",
        "copyright",
        "empty",
        "custom"
    ],
    // The template for the file parameter in Doxygen.
    "doxdocgen.file.fileTemplate": "@file {name}",
    // Version number for the file.
    "doxdocgen.file.versionTag": "@version 0.1",
    // Set the e-mail address of the author.  Replaces {email}.
    "doxdocgen.generic.authorEmail": "me@domain.com",
    // Set the name of the author.  Replaces {author}.
    "doxdocgen.generic.authorName": "My Name",
    // Set the style of the author tag and your name.  Can template {author} and {email}.
    "doxdocgen.generic.authorTag": "@author {author} ({email})",
    // If this is enabled a bool return value will be split into true and false return param.
    "doxdocgen.generic.boolReturnsTrueFalse": true,
    // The template of the brief Doxygen line that is generated. If empty it won't get generated at all.
    "doxdocgen.generic.briefTemplate": "@brief {text}",
    // The format to use for the date.
    "doxdocgen.generic.dateFormat": "YYYY-MM-DD",
    // The template for the date parameter in Doxygen.
    "doxdocgen.generic.dateTemplate": "@date {date}",
    // Decide if you want to get smart text for certain commands.
    "doxdocgen.generic.generateSmartText": true,
    // Whether include type information at return.
    "doxdocgen.generic.includeTypeAtReturn": true,
    // How many lines the plugin should look for to find the end of the declaration. Please be aware that setting this value too low could improve the speed of comment generation by a very slim margin but the plugin also may not correctly detect all declarations or definitions anymore.
    "doxdocgen.generic.linesToGet": 20,
    // The order to use for the comment generation. Values can be used multiple times. Valid values are shown in default setting.
    "doxdocgen.generic.order": [
        "brief",
        "empty",
        "tparam",
        "param",
        "return",
        "custom",
        "author",
        "date",
    ],
    // Custom tags to be added to the generic order. One tag per line will be added. Can template `{year}`, `{date}`, `{author}`, `{email}` and `{file}`. You have to specify the prefix.
    "doxdocgen.generic.customTags": [],
    // The template of the param Doxygen line(s) that are generated. If empty it won't get generated at all.
    "doxdocgen.generic.paramTemplate": "@param {param} ",
    // The template of the return Doxygen line that is generated. If empty it won't get generated at all.
    "doxdocgen.generic.returnTemplate": "@return {type} ",
    // Decide if the values put into {name} should be split according to their casing.
    "doxdocgen.generic.splitCasingSmartText": true,
    // Array of keywords that should be removed from the input prior to parsing.
    "doxdocgen.generic.filteredKeywords": [],
    // Substitute {author} with git config --get user.name.
    "doxdocgen.generic.useGitUserName": false,
    // Substitute {email} with git config --get user.email.
    "doxdocgen.generic.useGitUserEmail": false,
    // Provide intellisense and snippet for doxygen commands
    "doxdocgen.generic.commandSuggestion": true,
    // Add `\\` in doxygen command suggestion for better readbility (need to enable commandSuggestion)
    "doxdocgen.generic.commandSuggestionAddPrefix": false
}
```

##### 2.2.2	配置默认C++编译器

```json
{
    "C_Cpp.default.compilerPath": "C:\\msys64\\mingw64\\bin\\g++.exe"
}
```

##### 2.2.3	配置CMake路径

```json
{
    "cmake.cmakePath": "C:\\msys64\\mingw64\\bin\\cmake.exe"
}
```

### 3	编译/运行Demo程序

#### 3.1	获取官方代码

```bash
git clone https://github.com/lvgl/lv_port_pc_vscode.git
cd lv_port_pc_vscode
git submodule update --init --recursive
git checkout -b release/v9.2
```

#### 3.2	VSCode配置并编译

- 打开目标文件夹。
- Ctrl + Shift + P：CMake: Select a kit，搜索/选择指定的编译包；或者， Ctrl + Shift + P：CMake: Edit User-Local Cmake Kits，手动增加编译包。选择MSYS2中gcc包的编译器。
- 执行：CMake – 生成。
- 执行：Cmake – 调试/启动

报错1：
```
[build] E:\TempPrj\LVGLDemo\lv_port_pc_vscode\main\src\main.c:18:10: fatal error: glob.h: No such file or directory
[build]    18 | #include "glob.h"
[build]       |          ^~~~~~~~
[build] compilation terminated.
[build] mingw32-make[2]: *** [CMakeFiles\main.dir\build.make:79: CMakeFiles/main.dir/main/src/main.c.obj] Error 1
[build] mingw32-make[2]: *** Waiting for unfinished jobs....
[build] mingw32-make[1]: *** [CMakeFiles\Makefile2:121: CMakeFiles/main.dir/all] Error 2
[build] mingw32-make: *** [Makefile:135: all] Error 2
```

解决方法：删除`src\main.c`中`#include "glob.h"`的引用
```patch
-- #include "glob.h"
++ //#include "glob.h"
```

报错2：
```
[build] C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/14.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:/SDL2-2.30.9/x86_64-w64-mingw32/lib/libSDL2main.a(SDL_windows_main.c.obj):SDL_windows_ma:(.text+0x152): undefined reference to `SDL_main'
[build] collect2.exe: error: ld returned 1 exit status
[build] mingw32-make[2]: *** [CMakeFiles\main.dir\build.make:126: E:/TempPrj/LVGLDemo/lv_port_pc_vscode/bin/main.exe] Error 1
[build] mingw32-make[1]: *** [CMakeFiles\Makefile2:121: CMakeFiles/main.dir/all] Error 2
[build] mingw32-make: *** [Makefile:135: all] Error 2
```

解决方法：在`src\main.c`中加入SDL2的头文件
```patch
++ #include <SDL.h>
```

## 二、	制作可运行LVGL应用程序的树莓派固件

### 1	制作固件

#### 1.1	Buildroot运行环境搭建

##### 1.1.1	创建虚拟环境

###### 1.1.1.1	Docker环境

docker-compose.yml
```yaml
version: "3"

services:
  rasp:
    image: ubuntu:22.04
    container_name: rasp
    volumes:
      - /docker-data/docker-volume/buildroot_dl_data:/buildroot_dl
```

###### 1.1.1.2	虚拟机环境

使用Ubuntu 22.04版本，并创建/buildroot_dl文件夹

##### 1.1.2	安装开发环境依赖包

```bash
sed -i 's@//.*archive.ubuntu.com@//mirrors.ustc.edu.cn@g' /etc/apt/sources.list
apt update
apt install -y build-essential nano vim-gtk wget xz-utils
apt install -y ncurses-dev file cpio unzip rsync bc git cmake

apt install -y python2
cd /usr/bin
ln -s python2 python
```

#### 1.2	基于Buildroot制作固件

##### 1.2.1	下载/解压buildroot压缩包

```bash
cd ~
wget https://buildroot.org/downloads/buildroot-2025.02.tar.gz
tar zxvf buildroot-2025.02.tar.gz
```

##### 1.2.2	使用树莓派默认配置

```bash
cd ~/buildroot-2025.02
make raspberrypi5_defconfig
```

##### 1.2.3	修改menuconfig配置

```bash
make ARCH=arm menuconfig
```

```
    Toolchain  --->
    	    C library (glibc)  --->
    Build options  --->
    	(/buildroot_dl) Download dir
    Target packages  --->
    	[*]   Show packages that are also provided by busybox
    	    Compressors and decompressors  --->
    	    	-*- bzip2
    	    	[*] gzip
    	    	[*] unzip
    	    	[*] xz-utils
    	    	[*] zip
    	    Development tools  --->
    	    	[*] jq
    	    Graphic libraries and applications (graphic/text)  --->
    	    	[*] Qt5  --->
    	    		 SQLite 3 support (System SQLite)  --->
    	    		[*] GIF support
    	    		[*] JPEG support
    	    		[*] PNG support
    	    		[*]     DBus module
    	    		[*]     Enable Tslib support
    	    	[*] mupdf
    	    Hardware handling  --->
    	    	[*] i2c-tools
    	    Interpreter languages and scripting  --->
    	    	[*] tcl
    	    	      Tcl libraries/modules  --->
    	    	      	[*] expect
    	    Libraries  --->
    	    	    Crypto  --->
    	    	    	-*- openssl support
    	    	    	      ssl library (openssl)  --->
    	    	    	 openssl
    	    	    	[*] openssl binary
    	    	    	[*] openssl additional engines
    	    	    Graphics  --->
    	    	    	-*- freetype
    	    	    	[*] libqrencode
    	    	    	[*]   libqrencode tools
    	    	    	[*] poppler
    	    	    	[*]   Qt5 support
    	    	    	[*]   command line utils
    	    	    Hardware handling  --->
    	    	    	-*- tslib
    	    	    Networking  --->
    	    	    	[*] libcurl
    	    	    	[*]   curl binary
    	    	    	[*] libmodbus
    	    	    	[*] libsocketcan
    	    	    	[*] libvncserver
    	    	    	[*]   TightPNG encoding support
    	    	    	[*] paho-mqtt-c
    	    	    Other  --->
    	    	    	[*] boost
    	    	    	-*-   boost-atomic
    	    	    	-*-   boost-chrono
    	    	    	-*-   boost-container
    	    	    	-*-   boost-context
    	    	    	[*]   boost-contract
    	    	    	[*]   boost-coroutine
    	    	    	-*-   boost-date_time
    	    	    	[*]   boost-exception
    	    	    	[*]   boost-fiber
    	    	    	-*-   boost-filesystem
    	    	    	[*]   boost-graph
    	    	    	[*]   boost-graph_parallel
    	    	    	[*]   boost-iostreams
    	    	    	[*]   boost-json
    	    	    	[*]   boost-locale
    	    	    	[*]   boost-log
    	    	    	[*]   boost-math
    	    	    	[*]   boost-mpi
    	    	    	[*]   boost-nowide
    	    	    	[*]   boost-program_options
    	    	    	[*]   boost-random
    	    	    	-*-   boost-regex
    	    	    	[*]   boost-serialization
    	    	    	[*]   boost-stacktrace
    	    	    	-*-   boost-system
    	    	    	[*]   boost-test
    	    	    	-*-   boost-thread
    	    	    	-*-   boost-timer
    	    	    	[*]   boost-type_erasure
    	    	    	[*]   boost-url
    	    	    	[*]   boost-wave
    	    Networking applications  --->
    	    	[*] openssh
    	    	[*] wget
    Filesystem images  --->
    	(160M) exact size
```

##### 1.2.4	编译

如果使用root用户，则增加以下环境变量
```bash
export FORCE_UNSAFE_CONFIGURE=1
```

如网络不好，则增加以下环境变量
```bash
export all_proxy=http://10.10.10.23:8888
export https_proxy=http://10.10.10.23:8888
export http_proxy=http://10.10.10.23:8888

# unset all_proxy
# unset http_proxy
# unset https_proxy
```

编译
```bash
make -j$(nproc)
```

编译成功，输出目录：`~/buildroot-2025.02/output/images/sdcard.img`

### 2	配置树莓派板上环境

#### 2.1	打开特定功能

##### 2.1.1	打开板载调试串口

修改tf卡上的`config.txt`文件，增加一行设置
```patch
++ enable_uart=1
```

#### 2.2	加载特定驱动

##### 2.2.1	手动加载触摸驱动

```bash
insmod /lib/modules/5.10.92-v7l/kernel/drivers/input/touchscreen/raspberrypi-ts.ko
```

此时在`/dev/input/`下出现`event0`设备，即触摸屏设备，`cat /dev/input/event0`后点击触摸屏有响应，即驱动成功。

#### 2.3	配置环境变量

##### 2.3.1	配置tslib环境变量

```bash
export TSLIB_ROOT=/usr
export TSLIB_TSDEVICE=/dev/input/event0
export TSLIB_CALIBFILE=/etc/pointercal
export TSLIB_CONFFILE=/etc/ts.conf
export TSLIB_PLUGINDIR=/usr/lib/ts
export TSLIB_FBDEVICE=/dev/fb0
export TSLIB_CONSOLEDEVICE=none
```

## 三、	交叉编译LVGL应用程序

### 1	编译Demo程序

#### 1.1	获取官方代码

```bash
mkdir -p /home/runner/work
cd /home/runner/work
git clone --branch release/v9.2 --depth 1 --recurse-submodules https://github.com/lvgl/lv_port_linux.git
```

#### 1.2	针对嵌入式设备修改

##### 1.2.1	选择图形后端

修改`lv_conf.h`以支持`legacy framebuffer (fbdev)`
```patch
-- #define LV_USE_LINUX_FBDEV	0
++ #define LV_USE_LINUX_FBDEV	1
```

##### 1.2.2	启用输入

修改`lv_conf.h`以支持`EVDEV`
```patch
-- #define LV_USE_EVDEV	0
++ #define LV_USE_EVDEV	1
```

##### 1.2.3	修改电阻触摸屏驱动

*[TODO]*

#### 1.3	编译

- 注意CMake最低版本要求。

```bash
export PROJECTDIR=/home/runner/work/lv_port_linux
cd $PROJECTDIR
mkdir -p build
rm -rf build/*
cd build

cmake -DCMAKE_C_COMPILER=/home/runner/work/buildroot-2025.02/output/host/bin/aarch64-linux-gcc \
      -DCMAKE_CXX_COMPILER=/home/runner/work/buildroot-2025.02/output/host/bin/aarch64-linux-g++ \
      -DCMAKE_SYSTEM_NAME=Linux \
      -DCMAKE_SYSTEM_PROCESSOR=arm \
      ..
make -j
```

报错：
```
CMake Error in CMakeLists.txt:
  Found relative path while evaluating include directories of "main":

    "Libdrm_INCLUDE_DIR-NOTFOUND"
```

解决方法：注释`CMakeLists.txt`中的`FindLibDRM.cmake`相关代码
```patch
-- include(${CMAKE_CURRENT_LIST_DIR}/lvgl/tests/FindLibDRM.cmake)
-- include_directories(${Libdrm_INCLUDE_DIRS})
```

生成成功，输出在`$PROJECTDIR/bin/main`

## 四、	在树莓派上运行LVGL应用程序

### 1	配置运行环境变量

#### 1.1	设置图形后端环境变量

```bash
export LV_LINUX_FBDEV_DEVICE=/dev/fb0
```

#### 1.2	设置指针设备环境变量

```bash
export LV_LINUX_EVDEV_POINTER_DEVICE=/dev/input/event1
```

### 2	运行

*[TODO]*

## 五、	设计/编译/运行第一个程序

### 1	安装UI设计辅助软件

- 官方设计工具：SquareLine Studio
- NXP设计工具：GUI Guider

### 2	创建工程并在Windows上编译运行

#### 2.1	程序实现目标

- 引入boost库，利用boost库实现功能。
- 界面上居中放置一个按钮，初始显示“Please Click!”，点击后显示文字变成“Hello, world!”。

#### 2.2	程序实现过程

创建工程文件夹
```bash
mkdir -p MyFirstLVGLPrj
cd MyFirstLVGLPrj
```

获取lvgl仓库代码
```bash
git clone --branch v9.2.1 --depth 1 https://github.com/littlevgl/lvgl.git
```

创建工程（后续代码见本仓库）
- 使用VSCode打开MyFirstLVGLPrj文件夹。
- 创建工程根CMakeLists.txt。
- 移植lv_conf.h
- 创建main/src/main.c和main/src/mouse_cursor_icon.c

### 3	交叉编译后再树莓派上运行

```bash
export PROJECTDIR=/root/MyFirstLVGLPrj
cd $PROJECTDIR
mkdir -p build
rm -rf build/*
cd build

cmake -DCMAKE_C_COMPILER=/root/buildroot-2025.02/output/host/bin/aarch64-linux-gcc \
      -DCMAKE_CXX_COMPILER=/root/buildroot-2025.02/output/host/bin/aarch64-linux-g++ \
      -DCMAKE_SYSTEM_NAME=Linux \
      -DCMAKE_SYSTEM_PROCESSOR=arm \
      ..
make -j
```

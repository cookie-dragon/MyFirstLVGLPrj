#include "lvgl/lvgl.h"

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#if SYSWIN32
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <SDL.h>
#endif

#define USE_DEMO 0
#if USE_DEMO
#include "lvgl/demos/lv_demos.h"
#else
#include "cklhmibsp/include/cklhmibsp.h"
#include "ckldemos/include/activity/mainwindow/mainwindow.h"
#include "cklguiguider/generated/gui_guider.h"
#include "cklguiguider/generated/events_init.h"
#include "cklguiguider/custom/custom.h"
lv_ui guider_ui;
#include "cklsquarelinestudio/ui.h"

#if SYSWIN32
// 100ask不完全适配linux环境
#include "lv_100ask_lesson_demos/lv_100ask_lesson_demos.h"
#endif

#endif

#if SYSUNIX
// 定义一个静态的常量字符指针函数 getenv_default
// 该函数用于获取环境变量的值，如果环境变量不存在，则返回默认值
static const char *getenv_default(const char *name, const char *dflt)
{
    // 调用标准库函数 getenv 获取名为 name 的环境变量的值
    // 如果环境变量存在，则返回其值；如果不存在，则返回 NULL
    // 使用三元运算符 ?:，如果 getenv(name) 返回 NULL，则返回默认值 dflt
    return getenv(name) ?: dflt;
}
#endif

/**
 * @brief Initialize the display
 *
 * @author My Name (me@domain.com)
 * @date 2025-04-10
 */
#if SYSUNIX
#if LV_USE_LINUX_FBDEV
static void lv_linux_disp_init(void)
{
    const char *device = getenv_default("LV_LINUX_FBDEV_DEVICE", "/dev/fb0");
    lv_display_t *disp = lv_linux_fbdev_create();

    lv_linux_fbdev_set_file(disp, device);
}
#elif LV_USE_LINUX_DRM
static void lv_linux_disp_init(void)
{
    const char *device = getenv_default("LV_LINUX_DRM_CARD", "/dev/dri/card0");
    lv_display_t *disp = lv_linux_drm_create();

    lv_linux_drm_set_file(disp, device, -1);
}
#elif LV_USE_SDL
static void lv_linux_disp_init(void)
{
    const int width = atoi(getenv("LV_SDL_VIDEO_WIDTH") ?: "800");
    const int height = atoi(getenv("LV_SDL_VIDEO_HEIGHT") ?: "480");

    lv_sdl_window_create(width, height);
}
#endif
#elif SYSWIN32
static lv_display_t *hal_init(int32_t w, int32_t h)
{

    lv_group_set_default(lv_group_create());

    lv_display_t *disp = lv_sdl_window_create(w, h);

    lv_indev_t *mouse = lv_sdl_mouse_create();
    lv_indev_set_group(mouse, lv_group_get_default());
    lv_indev_set_display(mouse, disp);
    lv_display_set_default(disp);

#if 0
    LV_IMAGE_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
    lv_obj_t *cursor_obj;
    cursor_obj = lv_image_create(lv_screen_active()); /*Create an image object for the cursor */
    lv_image_set_src(cursor_obj, &mouse_cursor_icon); /*Set the image source*/
    lv_indev_set_cursor(mouse, cursor_obj);           /*Connect the image  object to the driver*/

    lv_indev_t *mousewheel = lv_sdl_mousewheel_create();
    lv_indev_set_display(mousewheel, disp);
    lv_indev_set_group(mousewheel, lv_group_get_default());

    lv_indev_t *kb = lv_sdl_keyboard_create();
    lv_indev_set_display(kb, disp);
    lv_indev_set_group(kb, lv_group_get_default());
#endif

    return disp;
}
#endif

int main(int argc, char **argv)
{
    (void)argc; /*Unused*/
    (void)argv; /*Unused*/

    /*Initialize LVGL*/
    lv_init();
#if SYSUNIX
    /*Linux display device init*/
    lv_linux_disp_init();
#elif SYSWIN32
    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init(800, 480);
#endif

#if USE_DEMO
#if SYSUNIX
    lv_demo_widgets();
    lv_demo_widgets_start_slideshow();
#elif SYSWIN32
    lv_demo_widgets();
#endif
#else

    /*Your code here*/

    /**
     * @brief cklhmibsp
     *
     * @author My Name (me@domain.com)
     * @date 2025-04-11
     */
#if 0
    // 创建 CklHmiBsp 对象
    void *obj = createCklHmiBsp();

    // 调用 CklHmiBsp 对象的 echo 方法
    callCklHmiBspEcho(obj);

    // 销毁 CklHmiBsp 对象
    destroyCklHmiBsp(obj);
#endif

    /**
     * @brief ckldemos
     *
     * @author My Name (me@domain.com)
     * @date 2025-04-11
     */
#if 1
    createMainWindow();
#endif

    /**
     * @brief cklguiguider
     *
     * @author My Name (me@domain.com)
     * @date 2025-04-11
     */
#if 0
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);
#endif

    /**
     * @brief cklsquarelinestudio
     *
     * @author My Name (me@domain.com)
     * @date 2025-04-11
     */
#if 0
    ui_init();
#endif

#if SYSWIN32
    /**
     * @brief lv_100ask_lesson_demos
     *
     * 100ask不完全适配linux环境
     *
     * @author My Name (me@domain.com)
     * @date 2025-04-11
     */
#if 0
    // lesson_2_3_1(); // 基础对象(lv_obj)，"Hello, LVGL
    // lesson_2_4_1(); // 基础对象的大小(size)
    // lesson_2_5_1(); // 基础对象的位置(position)
    // lesson_2_6_1(); // 基础对象的盒子模型(border-box)
    // lesson_2_7_1(); // 基础对象的样式(styles)
    // lesson_2_8_1(); // 基础对象的事件(events)、事件冒泡
    // lesson_2_9_1(); // LVGL的定时器(lv_timer)-入门

    // lesson_3_1_1();  // 标签控件(lv_label)的用法
    // lesson_3_2_1();  // 按钮控件(lv_button)的用法
    // lesson_3_3_1();  // 进度条控件(lv_bar)的用法
    // lesson_3_4_1();  // 滑动条控件(lv_slider)的用法
    // lesson_3_5_1();  // 圆弧控件(lv_arc)的用法
    // lesson_3_6_1();  // 环形加载器控件(lv_spinner)的用法
    // lesson_3_7_1();  // 矩阵按钮控件(lv_btnmatrix)的用法
    // lesson_3_8_1();  // 列表控件(lv_list)的用法
    // lesson_3_9_1();  // 开关控件(lv_switch)的用法
    // lesson_3_10_1(); // 复选框控件(lv_checkbox)的用法
    // lesson_3_11_1(); // 线条控件(lv_line)的用法
    // lesson_3_12_1(); // LED控件(lv_led)的用法
    // lesson_3_13_1(); // 下拉列表控件(lv_dropdown)的用法
    // lesson_3_14_1(); // 滚轮控件(lv_roller)的用法
    // lesson_3_15_1(); // 消息框控件lv_msgbox的用法
    // lesson_3_16_1(); // 富文本控件(lv_span)的用法
    // lesson_3_17_1(); // 文本框控件(lv_textarea)的用法
    // lesson_3_18_1(); // 键盘控件(lv_keyboard)的用法
    // lesson_3_19_1(); // 微调框控件(lv_spinbox)的用法
    // lesson_3_20_1(); // 表格控件(lv_table)的用法
    // lesson_3_21_1(); // 标尺控件lv_scale的用法
    // lesson_3_22_1(); // 图表控件(lv_chart)的用法
    // lesson_3_23_1(); // 日历控件(lv_calendar)的用法
    // lesson_3_24_1(); // 图像控件(lv_image)的用法
    // lesson_3_25_1(); // 图像按钮控件(lv_imagebutton)的用法
    // lesson_3_26_1(); // 动画图像控件(lv_animimg)用法
    // lesson_3_27_1(); // 画布控件(lv_canvas)的用法
    // lesson_3_28_1(); // 选项卡控件(lv_tabview)的用法
    // lesson_3_29_1(); // 平铺视图控件(lv_tileview)的用法
    // lesson_3_30_1(); // 菜单控件(lv_menu)的用法
    // lesson_3_31_1(); // 窗口控件(lv_win)的用法
    // lesson_3_32_1(); // Lottie控件(lv_lottie)的用法

    // lesson_4_1(); // Flex（弹性）布局的用法
    // lesson_4_2(); // Grid（弹性）布局的用法
    // lesson_4_3(); // Flex（弹性）和Grid（网格）布局的区别

    // lesson_5_1(); // LVGL文件系统模块的用法
    // lesson_5_2(); // 通过LVGL文件系统模块的显示图片文件
    // lesson_5_3(); // FreeType控件（lv_freetype）的用法
    // lesson_5_4(); // 二维码控件(lv_qrcode)的用法
    // lesson_5_5(); // 条形码控件(lv_barcode)的用法

    // lesson_6_1(); // 文件资源管理器控件（lv_file_explorer）的用法
    // lesson_6_2(); // 拼音输入法控件（lv_ime_pinyin）的用法
    // lesson_6_3(); // 快照控件（lv_snapshot）的用法
    // lesson_6_4(); // Monkey测试（压力测试）的用法

    // lesson_7_1(); // 更进一步理解LVGL的定时器
    // lesson_7_2(); // 动画的用法
    // lesson_7_3(); // 动画时间线的用法
    // lesson_7_4(); // 动画的本质是定时器处理
    // lesson_7_5(); // 为什么创建出来的不同控件会不一样？
    // lesson_7_6(); // 物理按键代替触摸（鼠标模仿编码器）
    // lesson_7_7(); // Windows HOOK拦截键盘输入模拟按键输入

    // lesson_8_1(); // 基于FontAwesome 添加新SYMBOLS
    // lesson_8_2(); // 调试方法之LV_LOG
    // lesson_8_3(); // 调试方法之LV_SYSMON(system monitor)

    // lesson_9_1(); // 移植适配 lv_lib_100ask
    // lesson_9_2(); // 移植适配 lv_100ask_ui

    // lesson_10_1(); // LVGL的编码风格
    // lesson_10_2(); // 如何阅读Changelog
    // lesson_10_3(); // 如何阅读Roadmap
    // lesson_10_4(); // 如何参与LVGL开发-为LVGL库做贡献
#endif
#endif

#endif

    /*Handle LVGL tasks*/
    while (1)
    {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_timer_handler();
        usleep(5 * 1000);
    }

    return 0;
}

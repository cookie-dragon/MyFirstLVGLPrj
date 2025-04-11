#include "lvgl/lvgl.h"

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#if SYSWIN32
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <SDL.h>
#endif

#define USE_DEMO 1
#if USE_DEMO
#include "lvgl/demos/lv_demos.h"
#else
#include "cklhmibsp/include/cklhmibsp.h"
#include "ckldemos/include/ckl_mainwindow.h"
#include "cklguiguider/generated/gui_guider.h"
#include "cklguiguider/generated/events_init.h"
#include "cklguiguider/custom/custom.h"
lv_ui guider_ui;
#include "cklsquarelinestudio/ui.h"
#include "lv_100ask_lesson_demos/lv_100ask_lesson_demos.h"
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
#if 0
    ckl_mainwindow();
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

    /**
     * @brief lv_100ask_lesson_demos
     *
     * @author My Name (me@domain.com)
     * @date 2025-04-11
     */
#if 0
    lesson_2_3_1(); // 基础对象(lv_obj)，"Hello, LVGL
    // lesson_2_4_1(); // 基础对象的大小(size)
    // lesson_2_5_1(); // 基础对象的位置(position)
    // lesson_2_6_1(); // 基础对象的盒子模型(border-box)
    // lesson_2_7_1(); // 基础对象的样式(styles)
    // lesson_2_8_1(); // 基础对象的事件(events)、事件冒泡
    // lesson_2_9_1(); // LVGL的定时器(lv_timer)-入门
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

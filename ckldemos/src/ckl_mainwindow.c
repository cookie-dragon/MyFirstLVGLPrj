#include "ckl_mainwindow.h"

// 按钮点击的回调函数
static void btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        // 创建 CklHmiBsp 对象
        void *obj = createCklHmiBsp();
        // 调用 CklHmiBsp 对象的 echo 方法
        callCklHmiBspEcho(obj);
        // 销毁 CklHmiBsp 对象
        destroyCklHmiBsp(obj);

        static uint8_t cnt = 0;
        cnt++;
        /* 获取按钮上的标签 */
        lv_obj_t *label = lv_obj_get_child(btn, 0);
        /* 更新标签文本 */
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}

void ckl_mainwindow(void)
{
    /* 创建一个按钮 */
    lv_obj_t *btn = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_center(btn);

    /* 在按钮上创建一个标签 */
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);
}

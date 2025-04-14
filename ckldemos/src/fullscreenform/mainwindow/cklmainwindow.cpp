#include "fullscreenform/mainwindow/cklmainwindow.h"
#include "fullscreenform/mainwindow/ui_cklmainwindow.h"

CklMainWindow::CklMainWindow(lv_obj_t *parent) : ui(new Ui::CklMainWindow)
{
    ui->setupUi(this);
    // btn的回调函数
    lv_obj_add_event_cb(ui->btn, on_btn_clicked, LV_EVENT_ALL, NULL);
}

CklMainWindow::~CklMainWindow()
{
    delete ui;
}

void CklMainWindow::on_btn_clicked(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = (lv_obj_t *)lv_event_get_target(e);
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

void *createMainWindow()
{
    return new CklMainWindow();
}

void destroyMainWindow(void *obj)
{
    delete static_cast<CklMainWindow *>(obj);
}

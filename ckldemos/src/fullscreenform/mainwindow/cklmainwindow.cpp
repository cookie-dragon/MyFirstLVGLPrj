#include "fullscreenform/mainwindow/cklmainwindow.h"
#include "fullscreenform/mainwindow/ui_cklmainwindow.h"

CklMainWindow::CklMainWindow(lv_obj_t *parent) : ui(new Ui::CklMainWindow)
{
    ui->setupUi(this);
    // btn的回调函数
    lv_obj_add_event_cb(ui->btn, cb_btn_clicked, LV_EVENT_ALL, NULL);
    // 连接信号和槽
    lv_obj_t *label = ui->label;
    sig_btn_click.connect([this, label]()
                                  { on_btn_clicked(label); });
}

CklMainWindow::~CklMainWindow()
{
    delete ui;
}

void CklMainWindow::cb_btn_clicked(lv_event_t *e)
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

        sig_btn_click();
    }
}

void CklMainWindow::on_btn_clicked(lv_obj_t *label)
{
    static uint8_t cnt = 0;
    cnt++;
    lv_label_set_text_fmt(ui->label, "Button: %d", cnt);
}
void *createMainWindow()
{
    return new CklMainWindow();
}

void destroyMainWindow(void *obj)
{
    delete static_cast<CklMainWindow *>(obj);
}

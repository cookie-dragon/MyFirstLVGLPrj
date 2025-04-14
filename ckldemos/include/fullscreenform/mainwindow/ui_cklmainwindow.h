#ifndef UI_CKLMAINWINDOW_H
#define UI_CKLMAINWINDOW_H

#include "fullscreenform/mainwindow/cklmainwindow.h"

class Ui_CklMainWindow
{
public:
    lv_obj_t *btn;
    lv_obj_t *label;
    void setupUi(CklMainWindow *mw)
    {
        /* 创建一个按钮 */
        btn = lv_btn_create(lv_scr_act());
        lv_obj_center(btn);

        /* 在按钮上创建一个标签 */
        label = lv_label_create(btn);
        lv_label_set_text(label, "Button");
        lv_obj_center(label);
    }

    void retranslateUi(CklMainWindow *mw)
    {
        lv_label_set_text(label, "Button"); // TODO: 翻译
    }
};

namespace Ui
{
    class CklMainWindow : public Ui_CklMainWindow
    {
    };
}

#endif // UI_CKLMAINWINDOW_H
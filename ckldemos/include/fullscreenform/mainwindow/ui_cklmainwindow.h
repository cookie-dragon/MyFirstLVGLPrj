#ifndef UI_CKLMAINWINDOW_H
#define UI_CKLMAINWINDOW_H

#include "cklgui/cklview.h"

class Ui_CklMainWindow : public CklView
{
public:
    Ui_CklMainWindow(ViewModel_Ckl *p_vm = nullptr, lv_obj_t *p_lv_parent = nullptr) : CklView(p_vm, p_lv_parent) {};

public:
    lv_obj_t *btn;
    lv_obj_t *label;
    void setupUi()
    {
        /* 创建根容器 */
        if (!m_lv_parent)
        {
            m_lv_parent = lv_scr_act();
        }
        m_container = lv_obj_create(m_lv_parent);
        lv_obj_set_size(m_container, lv_obj_get_width(m_lv_parent), lv_obj_get_height(m_lv_parent));
        lv_obj_center(m_container);

        /* 创建一个按钮 */
        btn = lv_btn_create(m_container);
        lv_obj_center(btn);

        /* 在按钮上创建一个标签 */
        label = lv_label_create(btn);
        lv_label_set_text(label, "Button");
        lv_obj_center(label);
    }

    void retranslateUi()
    {
        lv_label_set_text(label, "Button"); // TODO: 翻译
    }
};

namespace Ui
{
    class CklMainWindow : public Ui_CklMainWindow
    {
    public:
        CklMainWindow(ViewModel_Ckl *p_vm = nullptr, lv_obj_t *p_lv_parent = nullptr) : Ui_CklMainWindow(p_vm, p_lv_parent) {};
    };
}

#endif // UI_CKLMAINWINDOW_H
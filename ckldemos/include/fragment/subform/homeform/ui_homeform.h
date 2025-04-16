#ifndef UI_HOMEFORM_H
#define UI_HOMEFORM_H

#include "cklgui/cklview.h"

class Ui_HomeForm : public CklView
{
public:
    Ui_HomeForm(ViewModel_Ckl *p_vm = nullptr, lv_obj_t *p_lv_parent = nullptr) : CklView(p_vm, p_lv_parent) {};

public:
    lv_obj_t *label_mcont;
    void setupUi()
    {
        // 创建标签
        label_mcont = lv_label_create(m_container);
        lv_label_set_text(label_mcont, "HomeForm");
        lv_obj_center(label_mcont);
    }

    void retranslateUi()
    {
    }
};

namespace Ui
{
    class HomeForm : public Ui_HomeForm
    {
    public:
        HomeForm(ViewModel_Ckl *p_vm = nullptr, lv_obj_t *p_lv_parent = nullptr) : Ui_HomeForm(p_vm, p_lv_parent) {};
    };
}

#endif // UI_HOMEFORM_H
#ifndef HOMEFORM_H
#define HOMEFORM_H

#include "lvgl/lvgl.h"

#include "cklgui/cklfragment.h"

namespace Ui
{
    class HomeForm;
}

namespace Model
{
    class HomeForm;
}

class HomeForm : public CklFragment
{
public:
    HomeForm(ViewModel_Ckl *parent = nullptr, lv_obj_t *p_lv_parent = nullptr);
    ~HomeForm();

private:
    Model::HomeForm *model;
    Ui::HomeForm *ui;
};
#endif // HOMEFORM_H
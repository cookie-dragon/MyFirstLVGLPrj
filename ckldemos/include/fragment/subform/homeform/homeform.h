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
    static HomeForm *getInstance(ViewModel_Ckl *parent = nullptr, lv_obj_t *p_lv_parent = nullptr);

private:
    HomeForm(ViewModel_Ckl *parent = nullptr, lv_obj_t *p_lv_parent = nullptr);
    ~HomeForm();
    static HomeForm *p;

private:
    Model::HomeForm *model;
    Ui::HomeForm *ui;

 public:
    void initView();
    void show();
    void hide();
};
#endif // HOMEFORM_H
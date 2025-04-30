#include "fragment/subform/homeform/homeform.h"
#include "fragment/subform/homeform/ui_homeform.h"
#include "fragment/subform/homeform/model_homeform.h"

HomeForm *HomeForm::getInstance(ViewModel_Ckl *parent, lv_obj_t *p_lv_parent)
{
    if (!HomeForm::p)
    {
        p = new HomeForm(parent, p_lv_parent);
    }
    return p;
}
HomeForm *HomeForm::p = 0;

HomeForm::HomeForm(ViewModel_Ckl *parent, lv_obj_t *p_lv_parent) : CklFragment(parent), model(new Model::HomeForm(this)), ui(new Ui::HomeForm(this, p_lv_parent))
{
    model->setupModel();
    ui->setupUi();
}

HomeForm::~HomeForm()
{
    delete model;
    delete ui;
}

void HomeForm::initView()
{
    
}

void HomeForm::show()
{
    
}

void HomeForm::hide()
{

}
#ifndef UI_CKL_H
#define UI_CKL_H

#include "lvgl/lvgl.h"

#include "cklgui/vm_ckl.h"

class View_Ckl
{
protected:
    ViewModel_Ckl *m_vm;

public:
    View_Ckl(ViewModel_Ckl *p_vm = nullptr);
    ~View_Ckl();

public:
    virtual void setupUi() = 0;
    virtual void retranslateUi() = 0;
};

#endif // UI_CKL_H
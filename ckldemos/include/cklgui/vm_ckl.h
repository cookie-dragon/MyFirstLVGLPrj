/**
 * @file vm_ckl.h
 * @author My Name (me@domain.com)
 * @brief ViewModel base class in MVVM pattern for LVGL GUI
 * @date 2025-04-16
 *
 * @copyright Copyright (c) My Company 2025
 *
 */
#ifndef VM_CKL_H
#define VM_CKL_H

#include "lvgl.h"

class ViewModel_Ckl
{
protected:
    ViewModel_Ckl *m_parent;

public:
    ViewModel_Ckl(ViewModel_Ckl *parent = nullptr);
    ~ViewModel_Ckl();

public:
    virtual void initView() = 0;
    virtual void show() = 0;
    virtual void hide() = 0;
};

#ifdef __cplusplus
extern "C"
{
#endif

    void childWin_show(lv_obj_t *child, int32_t id);
    void childWin_hide(lv_obj_t *child, int32_t id);

#ifdef __cplusplus
}
#endif

#endif // VM_CKL_H
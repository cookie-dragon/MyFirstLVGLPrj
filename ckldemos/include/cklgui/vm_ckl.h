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

class ViewModel_Ckl
{
protected:
    ViewModel_Ckl *m_parent;

public:
    ViewModel_Ckl(ViewModel_Ckl *parent = nullptr);
    ~ViewModel_Ckl();
};

#endif // VM_CKL_H
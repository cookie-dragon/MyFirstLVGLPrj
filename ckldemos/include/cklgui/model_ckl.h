/**
 * @file model_ckl.h
 * @author My Name (me@domain.com)
 * @brief Model base class in MVVM pattern for LVGL GUI
 * @date 2025-04-16
 *
 * @copyright Copyright (c) My Company 2025
 *
 */
#ifndef MODEL_CKL_H
#define MODEL_CKL_H

#include "cklgui/vm_ckl.h"

class Model_Ckl
{
protected:
    ViewModel_Ckl *m_vm;

public:
    Model_Ckl(ViewModel_Ckl *p_vm = nullptr);
    ~Model_Ckl();

public:
    virtual void setupModel() = 0;
};

#endif // MODEL_CKL_H
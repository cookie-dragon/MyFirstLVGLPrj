/**
 * @file cklfragment.h
 * @author My Name (me@domain.com)
 * @brief ViewModel base class in MVVM pattern for LVGL GUI， just like android fragment
 * @date 2025-04-16
 * 
 * @copyright Copyright (c) My Company 2025
 * 
 */
#ifndef CKLFAGMENT_H
#define CKLFAGMENT_H

#include "cklgui/vm_ckl.h"

class CklFragment : public ViewModel_Ckl
{
private:
    /* data */
public:
    CklFragment(ViewModel_Ckl *parent = nullptr);
    ~CklFragment();
};

#endif // CKLFAGMENT_H
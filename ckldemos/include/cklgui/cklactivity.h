/**
 * @file cklactivity.h
 * @author My Name (me@domain.com)
 * @brief ViewModel base class in MVVM pattern for LVGL GUI， just like android activity
 * @date 2025-04-16
 * 
 * @copyright Copyright (c) My Company 2025
 * 
 */
#ifndef CKLACTIVITY_H
#define CKLACTIVITY_H

#include "cklgui/vm_ckl.h"

class CklActivity : public ViewModel_Ckl
{
private:
    /* data */
public:
    CklActivity(ViewModel_Ckl *parent = nullptr);
    ~CklActivity();
};

#endif // CKLACTIVITY_H
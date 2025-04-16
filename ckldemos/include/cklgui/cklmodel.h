/**
 * @file cklmodel.h
 * @author My Name (me@domain.com)
 * @brief Model base class in MVVM pattern for LVGL GUI
 * @date 2025-04-16
 * 
 * @copyright Copyright (c) My Company 2025
 * 
 */
#ifndef CKLMODEL_H
#define CKLMODEL_H

#include "cklgui/model_ckl.h"

class CklModel : public Model_Ckl
{
private:
    /* data */
public:
    CklModel(ViewModel_Ckl *p_vm = nullptr);
    ~CklModel();
};

#endif // CKLMODEL_H
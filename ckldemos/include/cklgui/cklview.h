/**
 * @file cklview.h
 * @author My Name (me@domain.com)
 * @brief View base class in MVVM pattern for LVGL GUI
 * @date 2025-04-16
 *
 * @copyright Copyright (c) My Company 2025
 *
 */
#ifndef CKLVIEW_H
#define CKLVIEW_H

#include "cklgui/ui_ckl.h"

class CklView : public View_Ckl
{
protected:
    lv_obj_t *m_lv_parent;
    lv_obj_t *m_container;

public:
    CklView(ViewModel_Ckl *p_vm = nullptr, lv_obj_t *p_lv_parent = nullptr);
    ~CklView();
};

#endif // CKLVIEW_H
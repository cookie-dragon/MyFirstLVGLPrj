/**
 * @file ckl_mainwindow.h
 * @author My Name (me@domain.com)
 * @brief
 * @date 2025-04-10
 *
 * @copyright Copyright (c) My Company 2025
 *
 */

#ifndef CKL_MAINWINDOW_H
#define CKL_MAINWINDOW_H

#ifdef __cplusplus

#include "lvgl/lvgl.h"
#include <boost/signals2.hpp>

#include "cklgui/cklactivity.h"
#include "cklgui/cklmodel.h"

#include "cklhmibsp/include/cklhmibsp.h"

// 定义信号类型
typedef boost::signals2::signal<void()> BtnClickSignal;

// 全局信号对象
BtnClickSignal sig_btn_click;

namespace Ui
{
    class CklMainWindow;
}

namespace Model
{
    class CklMainWindow;
}

class CklMainWindow : public CklActivity
{
public:
    CklMainWindow(ViewModel_Ckl *parent = nullptr, lv_obj_t *p_lv_parent = nullptr);
    ~CklMainWindow();

private:
    Model::CklMainWindow *model;
    Ui::CklMainWindow *ui;

private:
    static void cb_btn_clicked(lv_event_t *e);

private:
    void on_btn_clicked(lv_obj_t *label);
};

#endif

// 封装 C++ 类的功能为 C 语言可调用的函数
#ifdef __cplusplus
extern "C"
{
#endif

    void *createMainWindow();
    void destroyMainWindow(void *obj);

#ifdef __cplusplus
}
#endif

#endif /* CKL_MAINWINDOW_H */
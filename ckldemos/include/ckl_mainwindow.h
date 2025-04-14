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

#include "lvgl.h"
#include "cklhmibsp/include/cklhmibsp.h"

class CklMainWindow
{
public:
    CklMainWindow();
    ~CklMainWindow();
};

#endif

// 封装 C++ 类的功能为 C 语言可调用的函数
#ifdef __cplusplus
extern "C"
{
#endif

    static void btn_event_cb(lv_event_t *e);
    void ckl_mainwindow(void);

#ifdef __cplusplus
}
#endif

#endif /* CKL_MAINWINDOW_H */
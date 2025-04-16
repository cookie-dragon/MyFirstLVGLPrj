#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef __cplusplus

#include "lvgl/lvgl.h"

#include "cklgui/cklactivity.h"

#include "fragment/subform/homeform/homeform.h"

namespace Ui
{
    class MainWindow;
}

namespace Model
{
    class MainWindow;
}

class MainWindow : public CklActivity
{
public:
    MainWindow(ViewModel_Ckl *parent = nullptr, lv_obj_t *p_lv_parent = nullptr);
    ~MainWindow();

private:
    Model::MainWindow *model;
    Ui::MainWindow *ui;

public:
    HomeForm *homeFrag;
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

#endif /* MAINWINDOW_H */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef __cplusplus

#include "lvgl/lvgl.h"

#include "cklgui/cklactivity.h"

#include "fragment/subform/homeform/homeform.h"
#include <boost/signals2.hpp>

#define NAV_BTN_COUNT 5

typedef boost::signals2::signal<void()> BtnClickSig;
BtnClickSig sigBtnClick;

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
    static MainWindow *getInstance(ViewModel_Ckl *parent = nullptr, lv_obj_t *p_lv_parent = nullptr);

private:
    MainWindow(ViewModel_Ckl *parent = nullptr, lv_obj_t *p_lv_parent = nullptr);
    ~MainWindow();
    static MainWindow *p;

private:
    Model::MainWindow *model;
    Ui::MainWindow *ui;

private:
    int btn_index[NAV_BTN_COUNT];
    int m_lastIndex;

public:
    void initView();
    void show();
    void hide();
    static void btn_event_cb(lv_event_t * e);

private:
    void on_btnClick();
};

#endif

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
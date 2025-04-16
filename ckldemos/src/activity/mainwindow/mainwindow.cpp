#include "activity/mainwindow/mainwindow.h"
#include "activity/mainwindow/ui_mainwindow.h"
#include "activity/mainwindow/model_mainwindow.h"

MainWindow::MainWindow(ViewModel_Ckl *parent, lv_obj_t *p_lv_parent) : CklActivity(parent), model(new Model::MainWindow(this)), ui(new Ui::MainWindow(this, p_lv_parent))
{
    model->setupModel();
    ui->setupUi();

    homeFrag = new HomeForm(this, ui->cont_subchild);
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void *createMainWindow()
{
    return new MainWindow();
}

void destroyMainWindow(void *obj)
{
    delete static_cast<MainWindow *>(obj);
}

#include "activity/mainwindow/mainwindow.h"
#include "activity/mainwindow/ui_mainwindow.h"
#include "activity/mainwindow/model_mainwindow.h"

MainWindow *MainWindow::getInstance(ViewModel_Ckl *parent, lv_obj_t *p_lv_parent)
{
    if (!MainWindow::p)
    {
        p = new MainWindow(parent, p_lv_parent);
    }
    return p;
}
MainWindow *MainWindow::p = 0;

MainWindow::MainWindow(ViewModel_Ckl *parent, lv_obj_t *p_lv_parent) : CklActivity(parent), model(new Model::MainWindow(this)), ui(new Ui::MainWindow(this, p_lv_parent))
{
    model->setupModel();
    ui->setupUi();

    initView();
    show();

}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void *createMainWindow()
{
    return MainWindow::getInstance();
}

void destroyMainWindow(void *obj)
{
//    delete static_cast<MainWindow *>(obj);
}
void MainWindow::initView()
{
#if 1
    for(int i=0; i<NAV_BTN_COUNT; i++)
    {
        btn_index[i] = i;
        //lv_obj_set_user_data(ui->btn_nav_array[i], ui->cont_subchild);
        lv_obj_add_event_cb(ui->btn_nav_array[i], btn_event_cb, LV_EVENT_ALL, &btn_index[i]);
    }
    //lv_obj_t *btn = ui->btn_nav_array[i];
    sigBtnClick.connect([this]() { on_btnClick(); });
#endif 
}

void MainWindow::show()
{ 
    m_lastIndex = 0;
    childWin_show(ui->cont_subchild, 0);
    childWin_hide(ui->cont_subchild, 1);
}

void MainWindow::hide()
{

}

void MainWindow::btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = (lv_obj_t *)lv_event_get_target(e);

    if(code == LV_EVENT_CLICKED) {
        // 获取按钮的用户数据
        int * formId = (int * )lv_event_get_user_data(e);
        //lv_obj_t *parent_Win = (lv_obj_t *)lv_obj_get_user_data(btn);
        if(MainWindow::getInstance()->m_lastIndex == *formId)
        {
            return;
        }
        if(formId) {
            // 打印用户数据
            printf("Button clicked! User data: %d", *formId);
            int32_t childcount = lv_obj_get_child_count(MainWindow::getInstance()->ui->cont_subchild);
            if(*formId >= NAV_BTN_COUNT)
            {
                return;
            }
            switch (*formId)
            {
            case 0:
                childWin_show(MainWindow::getInstance()->ui->cont_subchild, *formId);
                childWin_hide(MainWindow::getInstance()->ui->cont_subchild, MainWindow::getInstance()->m_lastIndex);
                break;
            case 1:
                HomeForm::getInstance(MainWindow::getInstance(), MainWindow::getInstance()->ui->cont_subchild);
                childWin_show(MainWindow::getInstance()->ui->cont_subchild, *formId);
                childWin_hide(MainWindow::getInstance()->ui->cont_subchild, MainWindow::getInstance()->m_lastIndex);
            default:
                break;
            }
            
            MainWindow::getInstance()->m_lastIndex = *formId;
        }
        
        sigBtnClick();
    }
}

void MainWindow::on_btnClick()
{
    static int32_t cnt = 0;
    cnt++;
    printf("========%d", cnt);
}

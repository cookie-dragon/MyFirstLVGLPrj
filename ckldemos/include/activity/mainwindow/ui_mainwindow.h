#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <string>
#include "cklgui/cklview.h"
#include "activity/global.h"

class Ui_MainWindow : public CklView
{
public:
    Ui_MainWindow(ViewModel_Ckl *p_vm = nullptr, lv_obj_t *p_lv_parent = nullptr) : CklView(p_vm, p_lv_parent)
    {
        GlobalManager::getInstance()->setScreenSize(lv_obj_get_width(m_lv_parent), lv_obj_get_height(m_lv_parent));
    };

public:
    lv_obj_t *cont_topbar;
    lv_obj_t *label_topbar;
    lv_obj_t *cont_nav;
    lv_obj_t *btn_nav_array[5];
    lv_obj_t *label_btn_nav_array[5];
    lv_obj_t *cont_subchild;
    lv_obj_t *label_subchild;
    void setupUi()
    {
        // 创建topbar容器
        cont_topbar = lv_obj_create(m_container);
        int32_t topbar_x = 0;
        int32_t topbar_y = 0;
        int32_t topbar_width = DESIGN_WIDTH * 1 * GlobalManager::getInstance()->getScaleX();
        int32_t topbar_height = DESIGN_HEIGHT * 0.1 * GlobalManager::getInstance()->getScaleY();
        lv_obj_set_pos(cont_topbar, topbar_x, topbar_y);
        lv_obj_set_size(cont_topbar, topbar_width, topbar_height);

        // topbar容器样式
        lv_obj_set_scrollbar_mode(cont_topbar, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_border_width(cont_topbar, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(cont_topbar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(cont_topbar, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(cont_topbar, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(cont_topbar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(cont_topbar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(cont_topbar, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_grad_dir(cont_topbar, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_top(cont_topbar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_bottom(cont_topbar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_left(cont_topbar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_right(cont_topbar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(cont_topbar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        // 创建topbar标签
        label_topbar = lv_label_create(cont_topbar);
        lv_label_set_text(label_topbar, "topbar");
        lv_obj_center(label_topbar);

        // 创建nav容器
        cont_nav = lv_obj_create(m_container);

        // 根据屏幕长宽比设定剩余的界面布局
        bool isWidescreen = lv_obj_get_width(m_lv_parent) * 1.0 / lv_obj_get_height(m_lv_parent) > 1.34;

        int32_t nav_x, nav_y, nav_width, nav_height;
        if (isWidescreen)
        {
            // 宽屏，不包括4:3，导航栏放左边
            nav_x = 0;
            nav_y = topbar_height;
            nav_width = DESIGN_WIDTH * 0.15 * GlobalManager::getInstance()->getScaleX();
            nav_height = DESIGN_HEIGHT * 1 * GlobalManager::getInstance()->getScaleY() - topbar_height;
        }
        else
        {
            // 方屏或长屏，包括4:3，导航栏放下面
            nav_x = 0;
            nav_width = DESIGN_WIDTH * 1 * GlobalManager::getInstance()->getScaleX();
            nav_height = DESIGN_HEIGHT * 0.15 * GlobalManager::getInstance()->getScaleY();
            nav_y = DESIGN_HEIGHT * 1 * GlobalManager::getInstance()->getScaleY() - nav_height;
        }

        lv_obj_set_pos(cont_nav, nav_x, nav_y);
        lv_obj_set_size(cont_nav, nav_width, nav_height);

        // nav容器样式
        lv_obj_set_scrollbar_mode(cont_nav, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_border_width(cont_nav, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(cont_nav, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(cont_nav, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(cont_nav, LV_BORDER_SIDE_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(cont_nav, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(cont_nav, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(cont_nav, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_grad_dir(cont_nav, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_top(cont_nav, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_bottom(cont_nav, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_left(cont_nav, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_right(cont_nav, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(cont_nav, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        // 创建nav按钮
        int btn_cnt = 5;
        int btnSpacing = 8; // 按钮间距

        if (isWidescreen)
        {
            // 纵向排列
            int32_t btn_width = nav_width - 2 * btnSpacing;
            int32_t btn_height = (nav_height - (btn_cnt + 1) * btnSpacing) / btn_cnt;
            int32_t btn_x, btn_y;
            for (int i = 0; i < btn_cnt; i++)
            {
                lv_obj_t *btn_nav = lv_btn_create(cont_nav);
                btn_nav_array[i] = btn_nav;

                btn_x = btnSpacing;
                btn_y = btnSpacing + i * (btn_height + btnSpacing);

                lv_obj_set_size(btn_nav, btn_width, btn_height);
                lv_obj_set_pos(btn_nav, btn_x, btn_y);

                lv_obj_t *label_btn_nav = lv_label_create(btn_nav);
                lv_label_set_text(label_btn_nav, (std::string("NAV") + std::to_string(i + 1)).c_str());
                lv_obj_center(label_btn_nav);
            }
        }
        else
        {
            // 横向排列
            int32_t btn_width = (nav_width - (btn_cnt + 1) * btnSpacing) / btn_cnt;
            int32_t btn_height = nav_height - 2 * btnSpacing;
            int32_t btn_x, btn_y;
            for (int i = 0; i < btn_cnt; i++)
            {
                lv_obj_t *btn_nav = lv_btn_create(cont_nav);
                btn_nav_array[i] = btn_nav;

                btn_x = btnSpacing + i * (btn_width + btnSpacing);
                btn_y = btnSpacing;

                lv_obj_set_size(btn_nav, btn_width, btn_height);
                lv_obj_set_pos(btn_nav, btn_x, btn_y);

                lv_obj_t *label_btn_nav = lv_label_create(btn_nav);
                lv_label_set_text(label_btn_nav, (std::string("NAV") + std::to_string(i + 1)).c_str());
                lv_obj_center(label_btn_nav);
            }
        }

        // 创建子界面容器
        cont_subchild = lv_obj_create(m_container);

        int32_t subchild_x, subchild_y, subchild_width, subchild_height;
        if (isWidescreen)
        {
            subchild_x = nav_width;
            subchild_y = topbar_height;
            subchild_width = DESIGN_WIDTH * 1 * GlobalManager::getInstance()->getScaleX() - nav_width;
            subchild_height = DESIGN_HEIGHT * 1 * GlobalManager::getInstance()->getScaleY() - topbar_height;
        }
        else
        {
            subchild_x = 0;
            subchild_y = topbar_height;
            subchild_width = DESIGN_WIDTH * 1 * GlobalManager::getInstance()->getScaleX();
            subchild_height = DESIGN_HEIGHT * 1 * GlobalManager::getInstance()->getScaleY() - topbar_height - nav_height;
        }
        lv_obj_set_size(cont_subchild, subchild_width, subchild_height);
        lv_obj_set_pos(cont_subchild, subchild_x, subchild_y);

        // 子界面容器样式
        lv_obj_set_scrollbar_mode(cont_subchild, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_border_width(cont_subchild, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(cont_subchild, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(cont_subchild, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(cont_subchild, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(cont_subchild, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(cont_subchild, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(cont_subchild, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_grad_dir(cont_subchild, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_top(cont_subchild, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_bottom(cont_subchild, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_left(cont_subchild, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_right(cont_subchild, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(cont_subchild, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        // 创建subchild标签
        label_subchild = lv_label_create(cont_subchild);
        lv_label_set_text(label_subchild, "subchild");
        lv_obj_center(label_subchild);
    }

    void retranslateUi()
    {
    }
};

namespace Ui
{
    class MainWindow : public Ui_MainWindow
    {
    public:
        MainWindow(ViewModel_Ckl *p_vm = nullptr, lv_obj_t *p_lv_parent = nullptr) : Ui_MainWindow(p_vm, p_lv_parent) {};
    };
}

#endif // UI_MAINWINDOW_H
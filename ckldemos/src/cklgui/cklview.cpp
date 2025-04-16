#include "cklgui/cklview.h"
CklView::CklView(ViewModel_Ckl *p_vm, lv_obj_t *p_lv_parent) : View_Ckl(p_vm)
{
    m_lv_parent = p_lv_parent;

    /* 创建根容器 */
    if (!m_lv_parent)
    {
        m_lv_parent = lv_scr_act();
    }
    m_container = lv_obj_create(m_lv_parent);
    
    lv_obj_set_pos(m_container, 0, 0);
    lv_obj_set_size(m_container, lv_obj_get_width(m_lv_parent), lv_obj_get_height(m_lv_parent));
    lv_obj_set_scrollbar_mode(m_container, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_border_width(m_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(m_container, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(m_container, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(m_container, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(m_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(m_container, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(m_container, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(m_container, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(m_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(m_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(m_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(m_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(m_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_center(m_container);
}
CklView::~CklView()
{
}
#include "cklgui/vm_ckl.h"
#include <cstdio>

ViewModel_Ckl::ViewModel_Ckl(ViewModel_Ckl *parent)
{
    m_parent = parent;
}
ViewModel_Ckl::~ViewModel_Ckl()
{
}

void childWin_show(lv_obj_t *parent_Win, int32_t id)
{
    int32_t childcount = lv_obj_get_child_count(parent_Win);
    printf("childcount: %d, id=%d", childcount,id);
    lv_obj_t *child;
    if (childcount > id)
    {
        child = (lv_obj_t *)lv_obj_get_child(parent_Win, id);
        if (child)
        {
            lv_obj_clear_flag(child, LV_OBJ_FLAG_HIDDEN);
 //           lv_obj_move_foreground(child); // 确保显示在最前
        }
    }
}

void childWin_hide(lv_obj_t *parent_Win, int32_t id)
{
    int32_t childcount = lv_obj_get_child_count(parent_Win);
    lv_obj_t *child;
    if (childcount > id)
    {
        child = (lv_obj_t *)lv_obj_get_child(parent_Win, id);
        if (child)
        {
            lv_obj_add_flag(child, LV_OBJ_FLAG_HIDDEN);
        }
    }
}
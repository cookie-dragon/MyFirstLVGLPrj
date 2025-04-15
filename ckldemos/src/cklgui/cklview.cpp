#include "cklgui/cklview.h"
CklView::CklView(ViewModel_Ckl *p_vm, lv_obj_t *p_lv_parent) : View_Ckl(p_vm)
{
    m_lv_parent = p_lv_parent;
}
CklView::~CklView()
{
}
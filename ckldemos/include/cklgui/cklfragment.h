#ifndef CKLFAGMENT_H
#define CKLFAGMENT_H

#include "cklgui/vm_ckl.h"

class CklFragment : public ViewModel_Ckl
{
private:
    /* data */
public:
    CklFragment(ViewModel_Ckl *parent = nullptr);
    ~CklFragment();
};

#endif // CKLFAGMENT_H
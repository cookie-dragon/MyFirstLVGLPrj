#ifndef CKLACTIVITY_H
#define CKLACTIVITY_H

#include "cklgui/vm_ckl.h"

class CklActivity : public ViewModel_Ckl
{
private:
    /* data */
public:
    CklActivity(ViewModel_Ckl *parent = nullptr);
    ~CklActivity();
};

#endif // CKLACTIVITY_H
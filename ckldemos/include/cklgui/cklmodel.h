#ifndef CKLMODEL_H
#define CKLMODEL_H

#include "cklgui/model_ckl.h"

class CklModel : public Model_Ckl
{
private:
    /* data */
public:
    CklModel(ViewModel_Ckl *p_vm = nullptr);
    ~CklModel();
};

#endif // CKLMODEL_H
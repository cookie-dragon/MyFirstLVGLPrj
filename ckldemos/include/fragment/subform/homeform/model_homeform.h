#ifndef MODEL_HOMEFORM_H
#define MODEL_HOMEFORM_H

#include "cklgui/cklmodel.h"

class Model_HomeForm : public CklModel
{
public:
    Model_HomeForm(ViewModel_Ckl *p_vm = nullptr) : CklModel(p_vm) {};

public:
    void setupModel()
    {
    }
};

namespace Model
{
    class HomeForm : public Model_HomeForm
    {
    public:
        HomeForm(ViewModel_Ckl *p_vm = nullptr) : Model_HomeForm(p_vm) {};
    };
}

#endif // MODEL_HOMEFORM_H
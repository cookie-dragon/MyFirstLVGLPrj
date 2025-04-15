#ifndef MODEL_CKLMAINWINDOW_H
#define MODEL_CKLMAINWINDOW_H

#include "cklgui/cklmodel.h"

class Model_CKLMainWindow : public CklModel
{
public:
    Model_CKLMainWindow(ViewModel_Ckl *p_vm = nullptr) : CklModel(p_vm) {};

public:
    void setupModel()
    {
    }
};

namespace Model
{
    class CklMainWindow : public Model_CKLMainWindow
    {
    public:
        CklMainWindow(ViewModel_Ckl *p_vm = nullptr) : Model_CKLMainWindow(p_vm) {};
    };
}

#endif // MODEL_CKLMAINWINDOW_H
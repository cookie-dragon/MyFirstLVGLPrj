#ifndef MODEL_MAINWINDOW_H
#define MODEL_MAINWINDOW_H

#include "cklgui/cklmodel.h"

class Model_MainWindow : public CklModel
{
public:
    Model_MainWindow(ViewModel_Ckl *p_vm = nullptr) : CklModel(p_vm) {};

public:
    void setupModel()
    {
    }
};

namespace Model
{
    class MainWindow : public Model_MainWindow
    {
    public:
        MainWindow(ViewModel_Ckl *p_vm = nullptr) : Model_MainWindow(p_vm) {};
    };
}

#endif // MODEL_MAINWINDOW_H
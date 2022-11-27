#include "../h/confgui.h"
#include "ui_confgui.h"

ConfGui::ConfGui(QWidget *parent) : QMainWindow(parent), ui(new Ui::ConfGui)
{
    ui->setupUi(this);
}

ConfGui::~ConfGui()
{
    delete ui;
}

/*
 * Decrease the amount of program pairs need to judge by user.
 * i.e.
 * Assume there are three programs, say A, B and C.
 * If we have judged that A is equal with B and C, then this function will automatically add C to B's equal program set.
*/
void ConfGui::res_update(){

}

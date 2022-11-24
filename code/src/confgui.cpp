#include "confgui.h"
#include "ui_confgui.h"

ConfGui::ConfGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ConfGui)
{
    ui->setupUi(this);
}

ConfGui::~ConfGui()
{
    delete ui;
}


#ifndef CONFGUI_H
#define CONFGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ConfGui; }
QT_END_NAMESPACE

class ConfGui : public QMainWindow
{
    Q_OBJECT

public:
    ConfGui(QWidget *parent = nullptr);
    ~ConfGui();

private:
    Ui::ConfGui *ui;
};
#endif // CONFGUI_H

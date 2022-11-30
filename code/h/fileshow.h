#ifndef FILESHOW_H
#define FILESHOW_H

#include <QDialog>
#include <QTextCursor>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "../h/codediff.h"

namespace Ui {
class FileShow;
}

class FileShow : public QDialog
{
    Q_OBJECT

public:
    explicit FileShow(QWidget *parent = nullptr);
    ~FileShow();

    //Function to show this widget.
    void show_widget(std::vector<std::string>& file1, std::vector<std::string>& file2, std::vector<CommonStmt>& common_stmt, std::string folder_name, std::string file1_name, std::string file2_name);

    //Slot function when user click the equal button.
    void click_equal();

    //Slot function when user click the inequal button.
    void click_inequal();

private:
    Ui::FileShow *ui;

    //Show the contents of the two programs to help user judge the equality og these two programs manually.
    void show_program_pair(std::vector<std::string>& file1, std::vector<std::string>& file2, std::vector<CommonStmt>& common_stmt);

    //The name of current shown files and the folder to which they belong.
    std::string file1, file2, folder;

signals:
    //Signal that pass the judge result and the two judged files' name.
    void judge_res(std::string folder_name, std::string file1, std::string file2, bool res);
};

#endif // FILESHOW_H

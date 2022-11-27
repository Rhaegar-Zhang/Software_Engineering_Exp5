#ifndef CONFGUI_H
#define CONFGUI_H

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
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

    //Show the contents of the two programs to help user judge the equality og these two programs manually.
    void show_program_pair();

    //Update the judge result when user click equal button.
    void click_equal_btn();

    //Update the judge result when user click inequal button.
    void click_inequal_btn();

    /*
     * Decrease the amount of program pairs need to judge by user.
     * i.e.
     * Assume there are three programs, say A, B and C.
     * If we have judged that A is equal with B and C, then this function will automatically add C to B's equal program set.
    */
    void res_update(std::string folder_name, std::string file1, std::string file2, bool judge_res);

private:
    Ui::ConfGui *ui;

    //Equal result of manual judgment.
    std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_set<std::string> > > equal_res;

    //Inequal result of manual judgment.
    std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_set<std::string> > > inequal_res;

    /*
     * The recommended program pair need to shown.
     * The pair has the two paograms' name and the folder name to which they belong.
     */
    std::pair<std::string, std::string> file_pair;

    //The contents of the first program's source code.
    std::vector<std::string> file1;

    //The contents of the second program's source code.
    std::vector<std::string> file2;

    //Read the source code of the two files need to shown.
    void read_src_file();
};
#endif // CONFGUI_H

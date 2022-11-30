#ifndef CONFGUI_H
#define CONFGUI_H

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <QMainWindow>
#include "../h/codediff.h"
#include "../h/readoutput.h"
#include "../h/recommend.h"
#include "../h/fileshow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ConfGui; }
QT_END_NAMESPACE

class ConfGui : public QMainWindow
{
    Q_OBJECT

public:
    ConfGui(QWidget *parent = nullptr);
    ~ConfGui();

    /*
     * Decrease the amount of program pairs need to judge by user.
     * i.e.
     * Assume there are three programs, say A, B and C.
     * If we have judged that A is equal with B and C, then this function will automatically add C to B's equal program set.
    */
    void res_update(std::string folder_name, std::string file1, std::string file2, bool judge_res);

    //Function to run this file.
    void show_widget();

    //Save the manual result to files.
    void save_res();

private:
    Ui::ConfGui *ui;

    //Result of machine judgment.
    std::unordered_map<std::string, DirFile*> mach_res;

    //Result of manual judgment.
    std::unordered_map<std::string, DirFile*> manual_res;

    //Read the source code of the two files need to shown.
    void read_src_file(std::string path, std::vector<std::string>& file);

    //Get the path of input folder.
    std::string get_input_path();

    //If both contents of a pair is not empty then return true, otherwise return false.
    bool not_empty_pair(std::pair<std::string, std::string> p);

    /*
     * Find the folder in manual judging result.
     * If the folder doesn't exit then add one new folder into manual judging rersult.
     * Return the iterator of the folder's position.
     */
    std::unordered_map<std::string, DirFile*>::iterator find_folder(std::string folder_name);

    //Add one new equal or inequal program pair.
    void add_new_pair(std::string folder_name, std::string file1, std::string file2, bool judge_res);

    //Add one file to another file's equal file set or inequal file set.
    void add_file(std::string file1, std::string file2, std::unordered_map<std::string, std::unordered_set<std::string> >& target);
};
#endif // CONFGUI_H

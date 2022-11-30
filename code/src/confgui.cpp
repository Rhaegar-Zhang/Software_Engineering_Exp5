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

//Save the manual result to files.
void ConfGui::save_res(){
    std::string output_path;
    char *buf = getcwd(NULL, 0);
    output_path = buf;
    output_path = output_path.substr(0, output_path.find("Exp_5") + 5);
    std::string input_path = output_path;
    input_path += "/input/";
    output_path += "/output";
    std::string equal_path = output_path + "/equal.csv";
    std::string inequal_path = output_path + "/inequal.csv";
    std::ofstream equal_fout(equal_path);
    std::ofstream inequal_fout(inequal_path);
    equal_fout << "file1,file2\n";
    inequal_fout << "file1,file2\n";
    for(auto i = manual_res.begin(); i != manual_res.end(); ++i){
        for(auto j = i->second->equal_file_pairs.begin(); j != i->second->equal_file_pairs.end(); ++j)
            for(auto k = j->second.begin(); k != j->second.end(); ++k)
                equal_fout << input_path + i->first + '/' + j->first << ',' << input_path + i->first + '/' + *k << '\n';
        for(auto j = i->second->inequal_file_pairs.begin(); j != i->second->inequal_file_pairs.end(); ++j)
            for(auto k = j->second.begin(); k != j->second.end(); ++k)
                inequal_fout << input_path + i->first + '/' + j->first << ',' << input_path + i->first + '/' + *k << '\n';
    }
}

/*
 * Update the manual judging result.
*/
void ConfGui::res_update(std::string folder_name, std::string file1, std::string file2, bool judge_res){
    add_new_pair(folder_name, file1, file2, judge_res);
}

/*
 * Find the folder in manual judging result.
 * If the folder doesn't exit then add one new folder into manual judging rersult.
 * Return the iterator of the folder's position.
 */
std::unordered_map<std::string, DirFile*>::iterator ConfGui::find_folder(std::string folder_name){
    if(manual_res.find(folder_name) != manual_res.end())
        return manual_res.find(folder_name);
    DirFile *p = new DirFile;
    p->equal_file_pairs = std::unordered_map<std::string, std::unordered_set<std::string> > ();
    p->inequal_file_pairs = std::unordered_map<std::string, std::unordered_set<std::string> > ();
    return manual_res.emplace(folder_name, p).first;
}

//Add one new equal or inequal program pair.
void ConfGui::add_new_pair(std::string folder_name, std::string file1, std::string file2, bool judge_res){
   std::unordered_map<std::string, DirFile*>::iterator it = find_folder(folder_name);
    if(judge_res)
        add_file(file1, file2, it->second->equal_file_pairs);
    else
        add_file(file1, file2, it->second->inequal_file_pairs);
}

//Add one file to another file's equal file set or inequal file set.
void ConfGui::add_file(std::string file1, std::string file2, std::unordered_map<std::string, std::unordered_set<std::string> >& target){
    std::unordered_map<std::string, std::unordered_set<std::string> >::iterator it;
    it = target.find(file1);
    if(it == target.end()){
        it = target.emplace(file1, std::unordered_set<std::string> ()).first;
        it->second.emplace(file2);
    }
    else
        it->second.emplace(file2);
}


//Function to run this file.
void ConfGui::show_widget(){
    std::string input_path = get_input_path();
    ReadOutput *readoutput = new ReadOutput();
    mach_res = readoutput->read_output();
    while(!mach_res.empty()){
        auto i = mach_res.begin();
        std::string folder_name = i->first;
        std::string folder_path = get_input_path() + folder_name + '/';
        Recommend *recommend = new Recommend(i->second->equal_file_pairs, i->second->inequal_file_pairs);
        std::pair<std::string, std::string> recmd_res = recommend->pair_recommend();
        while(not_empty_pair(recmd_res)){
            std::vector<std::string> file1, file2;
            read_src_file(folder_path + recmd_res.first, file1);
            read_src_file(folder_path + recmd_res.second, file2);
            CodeDiff *codediff = new CodeDiff(file1, file2);
            codediff->get_lcs();
            std::vector<CommonStmt> common_stmt = codediff->get_comm_stmt();
            FileShow *p = new FileShow();
            connect(p, &FileShow::judge_res, this, &ConfGui::res_update);
            p->show_widget(file1, file2, common_stmt, folder_name, recmd_res.first, recmd_res.second);
            delete p;
            recmd_res = recommend->pair_recommend();
        }
        mach_res.erase(mach_res.begin());
    }
    save_res();
    this->close();
}

//Get the path of input folder.
std::string ConfGui::get_input_path(){
    char* buf = getcwd(NULL, 0);
    std::string input_path = buf;
    input_path = input_path.substr(0, input_path.find("Exp_5") + 5);
    return input_path + "/input/";
}

//Read the source code of the two files need to shown.
void ConfGui::read_src_file(std::string path, std::vector<std::string>& file){
    std::ifstream fin(path);
    while(!fin.eof()){
        std::string s;
        if(!getline(fin, s))
            break;
        file.push_back(s);
    }
}

//If both contents of a pair is not empty then return true, otherwise return false.
bool ConfGui::not_empty_pair(std::pair<std::string, std::string> p){
    return !(p.first.empty() || p.second.empty());
}


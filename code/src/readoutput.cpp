#include "../h/readoutput.h"

/*
* Function to read the output of equality judge.
* The return value is an unordered map.
* The keys of this map represent the folders' path.
* The values of each key represents the equal and inequal pairs in this folder.
*/
std::unordered_map<std::string, DirFile*>* ReadOutput::read_output(){
    std::string output_path = get_output_path();
    std::string equal_file = output_path + "/equal.csv";
    std::string inequal_file = output_path + "/inequal.csv";
    std::ifstream fin(equal_file);
    bool first_line = true;
    while(!fin.eof()){
        if(first_line){
            first_line = false;
            continue;
        }
        std::string s;
        if(!getline(fin, s))
            break;
        std::string folder = resolve_path(s.substr(0, s.find(',')));
        std::string file1 = resolve_name(s.substr(0, s.find(',')));
        std::string file2 = resolve_name(s.substr(s.find(',') + 1, s.length()));
        add_equal_pair(folder, file1, file2);
    }
    fin.close();
    fin.open(inequal_file);
    first_line = true;
    while(!fin.eof()){
        if(first_line){
            first_line = false;
            continue;
        }
        std::string s;
        if(!getline(fin, s))
            break;
        std::string folder = resolve_path(s.substr(0, s.find(',')));
        std::string file1 = resolve_name(s.substr(0, s.find(',')));
        std::string file2 = resolve_name(s.substr(s.find(',') + 1, s.length()));
        add_inequal_pair(folder, file1, file2);
    }
    return &result;
}

/*
* Function to get folder output's path.
* Return value is the real path of the folder.
*/
std::string ReadOutput::get_output_path(){
    char* buf = getcwd(NULL, 0);
    std::string real_path = buf;
    if(real_path.find("Exp_5") != std::string::npos){
        real_path = real_path.substr(0, real_path.find("Exp_5") + 5);
    }
    return real_path + "/output";
}

/*
* Function to get the folder's path of one program.
* i.e. ./input/4A/127473352.cpp
* This function will return 4A.
*/
std::string ReadOutput::resolve_path(std::string path){
    int input_index = path.find("input") == std::string::npos ? -1 : path.find('input');
    if(input_index < 0)
        return std::string();
    int start, end;
    start = input_index + 6;
    end = path.rfind('/');
    return path.substr(start, end);
}

/*
* Function to get one program's name
* i.e. ./input/4A/127473352.cpp
* This function will return 127473352.cpp
*/
std::string ReadOutput::resolve_name(std::string path){
    int start = path.rfind('/') == std::string::npos ? -1 : path.rfind('/');
    if(start < 0)
        return std::string();
    return path.substr(start + 1, path.length());
}

/*
* Add one new folder to the result that stores every equal pair and inequal pair in different folders.
* Return an iterator points to the position of the newly inserted folder.
*/
std::unordered_map<std::string, DirFile*>::iterator ReadOutput::add_new_folder(std::string folder_name){
    DirFile *p = new DirFile;
    return result.emplace(folder_name, p).first;
}

/*
* Add one new equal pair to one folder.
*/
void ReadOutput::add_equal_pair(std::string folder_name, std::string file1, std::string file2){
    auto it = result.find(folder_name);
    if(it == result.end())
        it = add_new_folder(folder_name);
    if(it->second->equal_file_pairs.find(file1) != it->second->equal_file_pairs.end()){
        it->second->equal_file_pairs.find(file1)->second.emplace(file2);
    }
    else{
        auto pos = it->second->equal_file_pairs.emplace(file1, std::unordered_set<std::string>()).first;
        pos->second.emplace(file2);
    }
    if(it->second->equal_file_pairs.find(file2) != it->second->equal_file_pairs.end())
        it->second->equal_file_pairs.find(file2)->second.emplace(file1);
    else{
        auto pos = it->second->equal_file_pairs.emplace(file2, std::unordered_set<std::string>()).first;
        pos->second.emplace(file1);
    }
}

/*
* Add one new inequal pair to one folder.
*/
void ReadOutput::add_inequal_pair(std::string folder_name, std::string file1, std::string file2){
    auto it = result.find(folder_name);
    if(it == result.end())
        it = add_new_folder(folder_name);
    if(it->second->inequal_file_pairs.find(file1) != it->second->inequal_file_pairs.end()){
        it->second->inequal_file_pairs.find(file1)->second.emplace(file2);
    }
    else{
        auto pos = it->second->inequal_file_pairs.emplace(file1, std::unordered_set<std::string>()).first;
        pos->second.emplace(file2);
    }
    if(it->second->inequal_file_pairs.find(file2) != it->second->inequal_file_pairs.end())
        it->second->inequal_file_pairs.find(file2)->second.emplace(file1);
    else{
        auto pos = it->second->inequal_file_pairs.emplace(file2, std::unordered_set<std::string>()).first;
        pos->second.emplace(file1);
    }
}

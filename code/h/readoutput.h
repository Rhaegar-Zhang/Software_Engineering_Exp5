#ifndef READOUTPUT_H
#define READOUTPUT_H

#include <unistd.h>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

struct DirFile{
    std::unordered_map<std::string, std::unordered_set<std::string> > equal_file_pairs;
    std::unordered_map<std::string, std::unordered_set<std::string> > inequal_file_pairs;
};

class ReadOutput{
public:
    /*
    * Function to read the output of equality judge.
    * The return value is an unordered map.
    * The keys of this map represent the folders' path.
    * The values of each key represents the equal and inequal pairs in this folder.
    */
    std::unordered_map<std::string, DirFile*>* read_output();
private:
    /*
    * Variable to store equal pairs and inequal pairs.
    */
    std::unordered_map<std::string, DirFile*> result;

    /*
    * Function to get folder output's path.
    * Return value is the real path of the folder.
    */
    std::string get_output_path();

    /*
    * Function to get the folder's path of one program.
    * i.e. ./input/4A/127473352.cpp
    * This function will return 4A.
    */
    std::string resolve_path(std::string path);

    /*
    * Function to get one program's name
    * i.e. ./input/4A/127473352.cpp
    * This function will return 127473352.cpp
    */
    std::string resolve_name(std::string path);

    /*
    * Add one new folder to the result that stores every equal pair and inequal pair in different folders.
    * Return an iterator points to the position of the newly inserted folder.
    */
    std::unordered_map<std::string, DirFile*>::iterator add_new_folder(std::string folder_name);

    /*
    * Add one new equal pair to one folder.
    */
    void add_equal_pair(std::string folder_name, std::string file1, std::string file2);

    /*
    * Add one new inequal pair to one folder.
    */
    void add_inequal_pair(std::string folder_name, std::string file1, std::string file2);
};

#endif
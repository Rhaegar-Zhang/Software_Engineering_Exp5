#ifndef RECOMMEND_H
#define RECOMMEND_H

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

//Struct to store the number of pairs of each file.
struct PairsOfFile{
    std::string file_name;
    int pair_num;
};

class Recommend{
    //Store the number of pairs of each file.
    std::vector<PairsOfFile*> file_pair_num;

    //Equal pairs of each file in this folder.
    std::unordered_map<std::string, std::unordered_set<std::string> > equal_pairs;
    
    //Inequal pairs of each file in this folder.
    std::unordered_map<std::string, std::unordered_set<std::string> > inequal_pairs;

    //Get each file's pair number and sort according to the number of pairs.
    void get_file_pair_num();

    /*
    * Return the pointer of file with name file_name.
    * If the file doesn't exit in file_pair_num return NULL.
    */
    PairsOfFile* find_file(std::string file_name);

    /*
    * Add one file and its equal pairs' amount or inequal pairs' amount to file_pair_num.
    */
    void add_file(std::string file_name, int pair_num);
public:
    //Get each file's equal pairs and inequal pairs in this folder.
    Recommend(std::unordered_map<std::string, std::unordered_set<std::string> >& _equal_pairs, std::unordered_map<std::string, std::unordered_set<std::string> >& _inequal_pairs);
    
    //Recommend one program pair that need to judge by user.
    std::pair<std::string, std::string> pair_recommend();
};
#endif
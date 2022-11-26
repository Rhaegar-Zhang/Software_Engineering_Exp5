#include "../h/recommend.h"

bool Compare(PairsOfFile* a, PairsOfFile* b){
    return a->pair_num > b->pair_num;
}

//Get each file's equal pairs and inequal pairs in this folder.
Recommend::Recommend(std::unordered_map<std::string, std::unordered_set<std::string> >& _equal_pairs, std::unordered_map<std::string, std::unordered_set<std::string> >& _inequal_pairs){
    this->equal_pairs = _equal_pairs;
    this->inequal_pairs = _inequal_pairs;
}

//Recommend the first program pair that need to judge by user.
std::pair<std::string, std::string> Recommend::pair_recommend(){
    if((*(file_pair_num.begin()))->pair_num == 0)
        file_pair_num.erase(file_pair_num.begin());
    if(file_pair_num.begin() == file_pair_num.end())
        return std::pair<std::string, std::string>("", "");
    std::string file_name = (*(file_pair_num.begin()))->file_name, file2_name = "";
    std::unordered_map<std::string, std::unordered_set<std::string> >::iterator i = equal_pairs.find(file_name);
    if(i != equal_pairs.end()){
        if(i->second.size() > 0){
            file2_name = *(i->second.begin());
            i->second.erase(i->second.begin());
            (*(file_pair_num.begin()))->pair_num--;
            if(i->second.size() == 0){
                equal_pairs.erase(i);
            }
        }
    }
    else{
        i = inequal_pairs.find(file_name);
        if(i->second.size() > 0){
            file2_name = *(i->second.begin());
            i->second.erase(i->second.begin());
            (*(file_pair_num.begin()))->pair_num--;
            if(i->second.size() == 0){
                inequal_pairs.erase(i);
            }
        }
    }
    return std::pair<std::string, std::string>(file_name, file2_name);
}

//Get each file's pair number and sort according to the number of pairs.
void Recommend::get_file_pair_num(){
    for(auto i = equal_pairs.begin(); i != equal_pairs.end(); ++i)
        add_file(i->first, i->second.size());
    for(auto i = inequal_pairs.begin(); i != inequal_pairs.end(); ++i)
        add_file(i->first, i->second.size());
    std::sort(file_pair_num.begin(), file_pair_num.end(), Compare);
}


/*
* Return the iterator of file with name file_name.
* If the file doesn't exit in file_pair_num return NULL, otherwise return the iterator.
*/
PairsOfFile* Recommend::find_file(std::string file_name){
    PairsOfFile *p = NULL;
    for(int i = 0; i < file_pair_num.size(); ++i)
    {
        if(file_name == file_pair_num[i]->file_name){
            p = file_pair_num[i];
            break;
        }
    }
    return p;
}

/*
* Add one file and its equal pairs' amount or inequal pairs' amount to file_pair_num.
*/
void Recommend::add_file(std::string file_name, int pair_num){
    if(find_file(file_name) != NULL){
        find_file(file_name)->pair_num += pair_num;
    }
    else{
        PairsOfFile *p = new PairsOfFile;
        p->file_name = file_name;
        p->pair_num = pair_num;
        file_pair_num.push_back(p);
    }
}

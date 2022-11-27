#ifndef CODEDIFF_H
#define CODEDIFF_H

#include <vector>
#include <string>


//The struct represents the common statements in two files.
struct CommonStmt{
    //One common statement in file1 and file2.
    std::string stmt;

    //The index of this statement in file1.
    int file1_index;

    //The index of this statement in file2.
    int file2_index;
};

class CodeDiff{
    //An array stores all the common statements in two files.
    std::vector<CommonStmt> stmt_lcs;

    //All statements in file1.
    std::vector<std::string> file1;

    //All statements in file2.
    std::vector<std::string> file2;
public:
    /*
    * Find the common statements in two files.
    * The common statements are stored in array stmt_lcs.
    */
    void get_lcs();

    //Return the common statements of these two programs.
    std::vector<CommonStmt>& get_comm_stmt();
};

#endif
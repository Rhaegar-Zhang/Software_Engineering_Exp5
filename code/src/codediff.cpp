#include "../h/codediff.h"

/*
* Find the common statements in two files.
* The common statements are stored in array stmt_lcs.
*/
void CodeDiff::get_lcs(){
    int file1_size = file1.size(), file2_size = file2.size();
    std::vector<std::vector<int> > lcs_array(file1_size + 1, std::vector<int> (file2_size + 1));
    for(int i = 0; i < file2_size + 1; ++i)
        lcs_array[0][i] = 0;
    for(int i = 0; i < file1_size + 1; ++i)
        lcs_array[i][0] = 0;
    for(int i = 0; i < file1_size; ++i)
        for(int j = 0; j < file2_size; ++i){
            if(file1[i] == file2[j])
                lcs_array[i + 1][j + 1] = lcs_array[i][j] + 1;
            else
                lcs_array[i + 1][j + 1] = std::max(lcs_array[i][j + 1], lcs_array[i + 1][j]);
        }
    for(int i = file1_size; i >= 2; --i)
        for(int j = file2_size; j >= 2; --j){
            if(file1[i - 1] == file2[j - 1]){
                CommonStmt p;
                p.file1_index = i - 1;
                p.file2_index = j - 1;
                p.stmt = file1[i - 1];
                stmt_lcs.push_back(p);
            }
            else{
                if(lcs_array[i - 1][j] >= lcs_array[i][j - 1]){
                    CommonStmt p;
                    p.file1_index = i - 2;
                    p.file2_index = j - 1;
                    p.stmt = file1[i - 2];
                    stmt_lcs.push_back(p);
                }
                else if(lcs_array[i - 1][j] < lcs_array[i][j - 1]){
                    CommonStmt p;
                    p.file1_index = i - 1;
                    p.file2_index = j - 2;
                    p.stmt = file1[i - 1];
                    stmt_lcs.push_back(p);
                }
            }
        }
}

//Return the common statements of these two programs.
std::vector<CommonStmt>& CodeDiff::get_comm_stmt(){
    return stmt_lcs;
}

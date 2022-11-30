#include "../h/fileshow.h"
#include "ui_fileshow.h"

FileShow::FileShow(QWidget *parent) : QDialog(parent), ui(new Ui::FileShow)
{
    ui->setupUi(this);
    connect(ui->EqualBtn, &QPushButton::clicked, this, &FileShow::click_equal);
    connect(ui->InequalBtn, &QPushButton::clicked, this, &FileShow::click_inequal);
}

FileShow::~FileShow()
{
    delete ui;
}

//Slot function when user click the equal button.
void FileShow::click_equal(){
    emit judge_res(folder, file1, file2, true);
    this->close();
}

//Slot function when user click the inequal button.
void FileShow::click_inequal(){
    emit judge_res(folder, file1, file2, false);
    this->close();
}

//Function to show this widget.
void FileShow::show_widget(std::vector<std::string>& file1, std::vector<std::string>& file2, std::vector<CommonStmt>& common_stmt, std::string folder_name, std::string file1_name, std::string file2_name){
    this->file1 = file1_name;
    this->file2 = file2_name;
    this->folder = folder_name;
    show_program_pair(file1, file2, common_stmt);
    this->exec();
}

//Show the contents of the two programs to help user judge the equality og these two programs manually.
void FileShow::show_program_pair(std::vector<std::string>& file1, std::vector<std::string>& file2, std::vector<CommonStmt>& common_stmt){
    QTextCursor cursor_1st = ui->FirstProg->textCursor(), cursor_2nd = ui->SecondProg->textCursor();
    int file1_index = 0, file2_index = 0, file1_line_num = 1, file2_line_num = 1;
    for(int i = common_stmt.size() - 1; i >= 0; --i){
        if(common_stmt[i].file1_index == common_stmt[i].file2_index){
            for( ; file1_index <= common_stmt[i].file1_index; ++file1_index){
                cursor_1st.movePosition(QTextCursor::End);
                ui->FirstProg->setTextCursor(cursor_1st);
                std::string temp = std::to_string(file1_line_num);
                if(file1_index == common_stmt[i].file1_index)
                    temp = std::string(4 - temp.length(), ' ') + temp + "  ";
                else
                    temp = std::string(4 - temp.length(), ' ') + temp + "- ";
                ui->FirstProg->insertPlainText(QString::fromStdString(temp + file1[file1_index] + '\n'));
                file1_line_num++;
            }
            for( ; file2_index <= common_stmt[i].file2_index; ++file2_index){
                cursor_2nd.movePosition(QTextCursor::End);
                ui->SecondProg->setTextCursor(cursor_2nd);
                std::string temp = std::to_string(file2_line_num);
                if(file2_index == common_stmt[i].file2_index)
                    temp = std::string(4 - temp.length(), ' ') + temp + "  ";
                else
                    temp = std::string(4 - temp.length(), ' ') + temp + "+ ";
                ui->SecondProg->insertPlainText(QString::fromStdString(temp + file2[file2_index] + '\n'));
                file2_line_num++;
            }
        }
        else{
            while(file1_index < common_stmt[i].file1_index && file2_index < common_stmt[i].file2_index){
                cursor_1st.movePosition(QTextCursor::End);
                cursor_2nd.movePosition(QTextCursor::End);
                ui->FirstProg->setTextCursor(cursor_1st);
                ui->SecondProg->setTextCursor(cursor_2nd);
                std::string temp1, temp2;
                temp1 = std::to_string(file1_line_num);
                temp2 = std::to_string(file2_line_num);
                temp1 = std::string(4 - temp1.length(), ' ') + temp1 + "- ";
                temp2 = std::string(4 - temp2.length(), ' ') + temp2 + "+ ";
                ui->FirstProg->insertPlainText(QString::fromStdString(temp1 + file1[file1_index] + '\n'));
                ui->SecondProg->insertPlainText(QString::fromStdString(temp2 + file2[file2_index] + '\n'));
                file1_index++;
                file2_index++;
                file1_line_num++;
                file2_line_num++;
            }
            for(; file1_index < common_stmt[i].file1_index; file1_index++){
                cursor_1st.movePosition(QTextCursor::End);
                cursor_2nd.movePosition(QTextCursor::End);
                ui->FirstProg->setTextCursor(cursor_1st);
                ui->SecondProg->setTextCursor(cursor_2nd);
                std::string temp1;
                temp1 = std::to_string(file1_line_num);
                temp1 = std::string(4 - temp1.length(), ' ') + temp1 + "- ";
                ui->FirstProg->insertPlainText(QString::fromStdString(temp1 + file1[file1_index] + '\n'));
                ui->SecondProg->insertPlainText(QString::fromStdString("      \n"));
                file1_line_num++;
            }
            for(; file2_index < common_stmt[i].file2_index; file2_index++){
                cursor_1st.movePosition(QTextCursor::End);
                cursor_2nd.movePosition(QTextCursor::End);
                ui->FirstProg->setTextCursor(cursor_1st);
                ui->SecondProg->setTextCursor(cursor_2nd);
                std::string temp2;
                temp2 = std::to_string(file2_line_num);
                temp2 = std::string(4 - temp2.length(), ' ') + temp2 + "+ ";
                ui->FirstProg->insertPlainText(QString::fromStdString("      \n"));
                ui->SecondProg->insertPlainText(QString::fromStdString(temp2 + file2[file2_index] + '\n'));
                file2_line_num++;
            }
            cursor_1st.movePosition(QTextCursor::End);
            cursor_2nd.movePosition(QTextCursor::End);
            ui->FirstProg->setTextCursor(cursor_1st);
            ui->SecondProg->setTextCursor(cursor_2nd);
            std::string temp1, temp2;
            temp1 = std::to_string(file1_line_num);
            temp2 = std::to_string(file2_line_num);
            temp1 = std::string(4 - temp1.length(), ' ') + temp1 + "  ";
            temp2 = std::string(4 - temp2.length(), ' ') + temp2 + "  ";
            ui->FirstProg->insertPlainText(QString::fromStdString(temp1 + file1[file1_index] + '\n'));
            ui->SecondProg->insertPlainText(QString::fromStdString(temp2 + file2[file2_index] + '\n'));
            file1_index++;
            file2_index++;
            file1_line_num++;
            file2_line_num++;
        }
    }
    for( ; file1_index < file1.size(); ++file1_index){
        cursor_1st.movePosition(QTextCursor::End);
        ui->FirstProg->setTextCursor(cursor_1st);
        std::string temp = std::to_string(file1_line_num);
        temp = std::string(4 - temp.length(), ' ') + temp + "- ";
        ui->FirstProg->insertPlainText(QString::fromStdString(temp + file1[file1_index] + '\n'));
        file1_line_num++;
    }
    for( ; file2_index < file2.size(); ++file2_index){
        cursor_2nd.movePosition(QTextCursor::End);
        ui->SecondProg->setTextCursor(cursor_2nd);
        std::string temp = std::to_string(file2_line_num);
        temp = std::string(4 - temp.length(), ' ') + temp + "+ ";
        ui->SecondProg->insertPlainText(QString::fromStdString(temp + file2[file2_index] + '\n'));
        file2_line_num++;
    }
}

#include <iostream>
#include <fstream>
#include <string>
#include <istream>

struct Stuinformation{
    std::string StuNum = "\000";
    std::string StuName = "\000";
    std::string StuClass = "\000";
    char StuSex = '\000';
    std::string StuMajor = "\000";
};
Stuinformation students[100];
struct Classtable{
    std::string ClassNO = "\000";
    std::string ClassName = "\000";
    double ClassScore = '\000';
    std::string ClassDetail = "\000";
};
Classtable classes[100];
struct Grade_table{
    std::string StuNum = "\000";
    std::string ClassNO = "\000";
    int ClassScore = '\000';
};
Grade_table grades[100];

void tianjia1(Stuinformation (&students)[100],std::fstream &read1);
void delete1(Stuinformation (&students)[100],std::fstream &output);
void modify1();
void lookup1();
void tianjia2();
void delete2();
void modify2();
void lookup2();
void readGradeinfo(std::fstream &open1);
void readClassInfo(std::ifstream &open1);
void tianjia3();
void delete3();
void modify3();
void lookup3();
void outputscore1(Stuinformation (&students)[100]);
double calculateGPA(std::string &stu_num,int Sumxuefen);
void Rankings();
std::string WhatYourName(std::string Stunum);
std::string WhatyourClass(std::string Stunum);
std::string returnsomeapces(std::string str);

float choice = 0;
int main(int argc, char *argv[]) {
    std::fstream read1;
    read1.open("a");
    if (!read1) {
        std::cout << "未能成功打开文件，请检查学生信息文件是否存在！" << std::endl;
        return -1;
    } else {
        readagain:
        for (int i = 0;; i++) {
            if (read1.eof())
                break;
            std::getline(read1, students[i].StuNum);
            std::getline(read1, students[i].StuName);
            std::getline(read1, students[i].StuClass);
            read1 >> students[i].StuSex;
            std::string temp;
            std::getline(read1,temp);
            std::getline(read1, students[i].StuMajor);
        }
    }

    again:
    std::cout << std::endl << "***欢迎访问河北工业大学学生成绩管理系统***" << std::endl;
    std::cout << "Powered by wyj       Version 0.9.9" << std::endl;
    std::cout << "[1] 维护学生信息" << std::endl << "[2] 维护课程信息" << std::endl << "[3] 维护成绩信息"
    << std::endl << "[4] 输出成绩单" << std::endl << "[5] 输出绩点排名" << std::endl << "[6] 退出系统" << std::endl;
    std::cout << "请选择相应的功能： ";
    float choice = 0;
    input1:
    std::cin >> choice;
    std::cin.get();
    if (choice > 6 || choice <= 0|| int(choice)!=choice ){                                             //输入主序号
        std::cout << "输入的序号有误，请重新输入！ ";
        goto input1;}
    if (choice == 1 || choice == 2|| choice == 3) {                             //输入维护的序号
        std::cout << "请选择进一步的操作：[1]添加 [2]删除 [3]修改 [4]查询 ";
        float temp = 0;
        input2:
        std::cin >> temp;
        std::cin.get();
        if (temp < 0||temp > 4|| int(temp)!=temp ) {
            std::cout << "输入的序号有误，请重新输入！ ";
            goto input2;
        }else if(temp == 1) {                                                    //添加
            if (choice == 1) {
                tianjia1(students,read1);
                goto readagain;
            }else
            if (choice == 2) tianjia2();else
            if (choice == 3) tianjia3();
        }else if (temp == 2){                                                    //删除
            if (choice == 1) {
                delete1(students,read1);
                goto readagain;
            }else
            if (choice == 2) delete2();else
            if (choice == 3) delete3();
        }else if (temp ==3){                                                     //修改
            if (choice == 1) modify1();else
            if (choice == 2) modify2();else
            if (choice == 3) modify3();
        }else if(temp == 4){                                                    //查询
            if (choice == 1) lookup1();else
            if (choice == 2) lookup2();else
            if (choice == 3) lookup3();
        }
    }
    if (choice == 4){
        outputscore1(students);
    }else if (choice == 5){
        Rankings();
    }else if (choice == 6){
            std::cout << "感谢您的使用，祝您生活愉快，期待您下次使用，再见！" << std::endl;
            std::cout << "Press any key to continue......";
            std::string temp;
            std::getline(std::cin,temp);
            return 0;
        }
    goto again;
}

void readGradeinfo(std::ifstream &open1){
    for (int i = 0; ;i++){
        std::getline(open1,grades[i].StuNum);
        if (grades[i].StuNum == "\000")
            break;
        std::getline(open1,grades[i].ClassNO);
        open1 >> grades[i].ClassScore;
        std::string tempstr;
        std::getline(open1,tempstr);
    }
}

void readClassInfo(std::ifstream &open1){
    for (int i = 0; ;i++){
        if (open1.eof())
            break;
        std::getline(open1,classes[i].ClassNO);
        std::getline(open1,classes[i].ClassName);
        open1 >> classes[i].ClassScore;
        std::string tempstr;
        std::getline(open1,tempstr);
        std::getline(open1,classes[i].ClassDetail);
    }
}


void tianjia1(Stuinformation (&students)[100],std::fstream &read1){
    retry:
        std::cout << "请输入学号：";
        {
            std::string xuehao;
            loop:
            std::getline(std::cin, xuehao);
            for (int i = 0; students[i].StuNum != "\000"; i++){
                if (xuehao == students[i].StuNum){
                    std::cout << "学号不能有重复，请重新输入！";
                    goto loop;
                }

            }
            read1.close();
            read1.open("a",std::fstream::app);
            read1 << xuehao << std::endl;
        }
        std::cout << "请输入姓名：";
        {
            std::string Name;
            std::getline(std::cin, Name);
            read1 << Name << std::endl;
        }
        std::cout << "请输入班级：";
        {
            std::string Class;
            std::getline(std::cin, Class);
            read1 << Class << std::endl;
        }
        std::cout << "请输入性别（填m或者f）：";
        {
            char Sex;
            std::cin >> Sex;
            std::cin.get();
            read1 << Sex << std::endl;
        }
        std::cout << "请输入专业：";
        {
            std::string Major;
            std::getline(std::cin, Major);
            read1 << Major << std::endl;
        }
    read1.close();
    read1.open("a");
}


void delete1(Stuinformation (&students)[100],std::fstream &output){
    again:
        std::cout << "请输入要删除的同学的学号：";
        std::string num1;
        std::cin >> num1;
        std::cin.get();
        int i;
        int State = 0;
        for (i = 0;students[i].StuNum != "\000";i++){
            if (students[i].StuNum == num1) {
                for (; students[i].StuNum != "\000"; i++) {
                    students[i].StuNum = students[i + 1].StuNum;
                    students[i].StuMajor = students[i + 1].StuMajor;
                    students[i].StuSex = students[i + 1].StuSex;
                    students[i].StuClass = students[i + 1].StuClass;
                    students[i].StuName = students[i + 1].StuName;
                    State = 1;
                }
            }
        }
    if (State == 0)
    {std::cout << "未找到该学号，请重新输入！" << std::endl;
    goto again;}
    output.close();
    std::ofstream output1("a");
        for (int i = 0;students[i].StuNum != "\000";i++){
        output1 << students[i].StuNum << std::endl;
        output1 << students[i].StuName << std::endl;
        output1 << students[i].StuClass << std::endl;
        output1 << students[i].StuSex << std::endl;
        output1 << students[i].StuMajor << std::endl;
    }
        output1.close();
        output.open("a",std::fstream::in |std::fstream::out);
}

void modify1(){
    std::ifstream open1("a");
    for (int i = 0; ;i++){
        if (open1.eof())
            break;
        std::getline(open1,students[i].StuNum);
        std::getline(open1,students[i].StuName);
        std::getline(open1,students[i].StuClass);
        open1 >> students[i].StuSex;
        std::string temp;
        std::getline(open1,temp);
        std::getline(open1,students[i].StuMajor);
    }
    again:
    std::cout << "请输入想要修改的同学的学号：";
    std::string num1;
    std::cin >> num1;
    std::cin.get();
    for (int i = 0; students[i].StuNum != "\000"; i++){
        if (students[i].StuNum == num1){
            std::cout << "找到该同学，请选择要修改的内容：[1]学号 [2]姓名 [3]班级 [4]性别 [5]专业";
            int k;
            input:
            std::cin >> k;
            std::cin.get();
            if (k < 1||k > 5){
                std::cout << "序号错误，请重新输入！";
                goto input;
            }
            std::string neww;
            switch (k) {
                case 1:
                    std::cout << "请输入新内容：";
                    std::getline(std::cin,neww);
                    students[i].StuNum = neww;
                    break;
                case 2:
                    std::cout << "请输入新内容：";
                    std::getline(std::cin,neww);
                    students[i].StuName = neww;
                    break;
                case 3:
                    std::cout << "请输入新内容：";
                    std::getline(std::cin,neww);
                    students[i].StuClass = neww;
                    break;
                case 4:
                    std::cout << "请输入新内容(m or f):";
                    char ii;
                    std::cin >> ii;
                    std::cin.get();
                    students[i].StuSex = ii;
                    break;
                case 5:
                    std::cout << "请输入新内容：";
                    std::getline(std::cin,neww);
                    students[i].StuMajor = neww;
                    break;
            }
            open1.close();
            std::ofstream output("a");
            for (int i = 0;students[i].StuNum != "\000";i++){
                output << students[i].StuNum << std::endl;
                output << students[i].StuName << std::endl;
                output << students[i].StuClass << std::endl;
                output << students[i].StuSex << std::endl;
                output << students[i].StuMajor << std::endl;
            }
            output.close();
            return ;
        }else std::cout << "搜索中..." << std::endl;
    }
    std::cout << "没找到哈,是否想重新输入？（Y或者N）" ;
    char c;
    std::cin >> c;
    std::cin.get();
    if (c == 'Y'){
        goto again;
    }else ;
}

void lookup1(){
    std::ifstream open1("a");
    for (int i = 0; ;i++){
        if (open1.eof())
            break;
        std::getline(open1,students[i].StuNum);
        std::getline(open1,students[i].StuName);
        std::getline(open1,students[i].StuClass);
        open1 >> students[i].StuSex;
        std::string temp;
        std::getline(open1,temp);
        std::getline(open1,students[i].StuMajor);
    }
    again:
    std::cout << "请输入想要查询的同学的学号：";
    std::string num1;
    std::cin >> num1;
    std::cin.get();
    for (int i = 0; students[i].StuNum != "\000"; i++){
        if (students[i].StuNum == num1){
            std::cout << "找到该同学" << std::endl;
                    std::cout << std::endl << "学号：" << students[i].StuNum;

                    std::cout << std::endl << "姓名: " << students[i].StuName;

                    std::cout << std::endl << "班级：" << students[i].StuClass;

                    std::cout << std::endl << "性别：" ;
            if (students[i].StuSex == 'm') std::cout << "男";
            else std::cout << "女";

                    std::cout << std::endl << "专业：" << students[i].StuMajor << std::endl <<std::endl;
            open1.close();
            std::cout << "请按回车键继续......";
            std::string temp;
            std::getline(std::cin,temp) ;
            return ; //结束运行
            }else std::cout << "搜索中..." << std::endl;
    }
open1.close();
    std::cout << "没找到哈" << std::endl;
    std::cout << "是否想重新输入？（Y或者N）" ;
    char c;
    std::cin >> c;
    std::cin.get();
    if (c == 'Y'){
        goto again;
    }else ;
}

void tianjia2(){
        std::fstream read1;
        read1.open("b", std::ofstream::app);
            std::cout << "请输入课程号：";
        {
            std::string xuehao;
            std::getline(std::cin,xuehao);
            read1 << xuehao << std::endl;
        }
        std::cout << "请输入课程名：";
        {
            std::string Name;
            std::getline(std::cin,Name);
            read1 << Name << std::endl;
        }
        std::cout << "请输入学分（整数）：";
        {
            double Xuefen;
            std::cin >> Xuefen;
            std::cin.get();
            read1 << Xuefen << std::endl;
        }
        std::cout << "请输入课程描述（仅限一行，以回车结束）：";
        {
            std::string description;
            std::getline(std::cin,description);
            read1 << description << std::endl;
        }
        std::cout << "信息录入成功，即将返回主菜单";
    read1.close();
    return ;
}

void delete2(){
    std::ifstream open1("b");
    for (int i = 0; ;i++){
        if (open1.eof())
            break;
        std::getline(open1,classes[i].ClassNO);
        std::getline(open1,classes[i].ClassName);
        open1 >> classes[i].ClassScore;
        std::string tempstr;
        std::getline(open1,tempstr);
        std::getline(open1,classes[i].ClassDetail);
    }
    again:
    std::cout << "希望通过那种方式查询？[1]课程号 [2]课程名 [3]学分 [4]课程描述 :";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>4){
        std::cout << "输入的序号有误，请重新输入！";
    goto again;}else
    std::cout << "请输入要删除的课程的";
    std::string thisisastr;
    int xuefen = 0;
    switch (t){
        case 1:
            std::cout << "课程号 ";
            std::getline(std::cin,thisisastr);
            break;

        case 2:
            std::cout << "课程名 ";
            std::getline(std::cin,thisisastr);
            break;

        case 3:
            std::cout << "学分 ";
            std::cin >> xuefen;
            std::cin.get();
            break;

        case 4:
            std::cout << "课程描述（仅限一行，以回车结束）";
            std::getline(std::cin,thisisastr);
            break;

    }
    int State = 0;
    if (t == 1||t == 2||t == 4) {
        int i;
        for (i = 0; classes[i].ClassNO != "\000"; i++) {
            if (classes[i].ClassNO == thisisastr || classes[i].ClassDetail == thisisastr || classes[i].ClassName == thisisastr) {
                std::cout << "找到符合条件的课程，是否要删除？" << std::endl;
                std::cout << "课程名：" << classes[i].ClassName << std::endl << "课程号：" << classes[i].ClassNO << std:: endl <<
                "课程描述：" << classes[i].ClassDetail << std::endl <<
                "学分：" << classes[i].ClassScore << std::endl;
                char t;
                choose:
                std::cout << "请选择（输入Y或N）:";
                std::cin >> t;
                std::cin.get();
                if(t == 'N'){
                    open1.close();
                    std::ofstream output("b");
                    for (int count = 0;classes[count].ClassNO != "\000";count++){
                        output << classes[count].ClassNO << std::endl;
                        output << classes[count].ClassName << std::endl;
                        output << classes[count].ClassScore << std::endl;
                        output << classes[count].ClassDetail << std::endl;
                        State = 1;
                    }
                    output.close();
                }else if(t != 'Y'){
                    std::cout << "您输入的字母有误，请重新输入！";
                    goto choose;
                }else {
                    for (int count = i; classes[count].ClassNO != "\000"; count++) {
                        classes[count].ClassNO = classes[count + 1].ClassNO;
                        classes[count].ClassName = classes[count + 1].ClassName;
                        classes[count].ClassDetail = classes[count + 1].ClassDetail;
                        classes[count].ClassScore = classes[count + 1].ClassScore;
                        State = 1;
                    }
                    i--;
                    std::cout << "课程成功删除" << std::endl;
                }
            }
        }
    }else {
        int i;
        for (i = 0; classes[i].ClassNO != "\000"; i++) {
            if (classes[i].ClassScore == xuefen) {
                std::cout << "找到符合条件的课程，是否要删除？" << std::endl;
                std::cout << "课程号：" << classes[i].ClassNO << std::endl <<
                          "课程名：" << classes[i].ClassName << std::endl <<
                          "课程描述：" << classes[i].ClassDetail << std::endl <<
                          "学分：" << classes[i].ClassScore << std::endl;
                char t;
                choose2:
                std::cout << "请选择（输入Y或N）:";
                std::cin >> t;
                std::cin.get();
                if(t == 'N'){
                    open1.close();
                    std::ofstream output("b");
                    for (int count = 0;classes[count].ClassNO != "\000";count++){
                        output << classes[count].ClassNO << std::endl;
                        output << classes[count].ClassName << std::endl;
                        output << classes[count].ClassScore << std::endl;
                        output << classes[count].ClassDetail << std::endl;
                        State = 1;
                    }
                    output.close();
                }else if(t != 'Y'&&t != 'N'){
                    std::cout << "您输入的字母有误，请重新输入！";
                    goto choose2;
                }else{
                for (int count = i; classes[count].ClassNO != "\000"; count++) {
                    classes[count].ClassNO = classes[count + 1].ClassNO;
                    classes[count].ClassName = classes[count + 1].ClassName;
                    classes[count].ClassDetail = classes[count + 1].ClassDetail;
                    classes[count].ClassScore = classes[count + 1].ClassScore;
                    State = 1;
                }
                i--;
                std::cout << "课程成功删除" << std::endl;
                }
            }
        }
    }
    if (State == 0)
    {std::cout << "未找到对应的课程，请重新输入！" << std::endl;
        goto again;}
    open1.close();
    std::ofstream output("b");
    for (int i = 0;classes[i].ClassNO != "\000";i++){
        output << classes[i].ClassNO << std::endl;
        output << classes[i].ClassName << std::endl;
        output << classes[i].ClassScore << std::endl;
        output << classes[i].ClassDetail << std::endl;
    }
    output.close();
}

void modify2(){
    std::ifstream open1("b");
    for (int i = 0; ;i++){
        if (open1.eof())
            break;
        std::getline(open1,classes[i].ClassNO);
        std::getline(open1,classes[i].ClassName);
        open1 >> classes[i].ClassScore;
        std::string tempstr;
        std::getline(open1,tempstr);
        std::getline(open1,classes[i].ClassDetail);
    }
    again:
    std::cout << "希望通过那种方式查询？[1]课程号 [2]课程名 [3]学分 [4]课程描述 :";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>4){
        std::cout << "输入的序号有误，请重新输入！";
        goto again;}else
        std::cout << "请输入要修改的课程的";
    std::string thisisastr;
    int xuefen = 0;
    switch (t){
        case 1:
            std::cout << "课程号 ";
            std::getline(std::cin,thisisastr);
            break;

        case 2:
            std::cout << "课程名 ";
            std::getline(std::cin,thisisastr);
            break;

        case 3:
            std::cout << "学分 ";
            std::cin >> xuefen;
            std::cin.get();
            break;

        case 4:
            std::cout << "课程描述（仅限一行，以回车结束）";
            std::getline(std::cin,thisisastr);
            break;

    }
    int State = 0;
    int i;
    for (i = 0; classes[i].ClassNO != "\000"; i++) {
        if (classes[i].ClassNO == thisisastr || classes[i].ClassDetail == thisisastr || classes[i].ClassName == thisisastr || classes[i].ClassScore == xuefen) {
                std::cout << "找到符合条件的课程，是否要修改？" << std::endl;
                std::cout << "课程名：" << classes[i].ClassName << std::endl << "课程号：" << classes[i].ClassNO << std:: endl <<
                          "课程描述：" << classes[i].ClassDetail << std::endl <<
                          "学分：" << classes[i].ClassScore << std::endl;
                char t;
                choose:
                std::cout << "请选择（输入Y或N）:";
                std::cin >> t;
                std::cin.get();
                if (t == 'N'){
                    open1.close();
                    std::ofstream output("b");
                    for (int count = 0;classes[count].ClassNO != "\000";count++){
                        output << classes[count].ClassNO << std::endl;
                        output << classes[count].ClassName << std::endl;
                        output << classes[count].ClassScore << std::endl;
                        output << classes[count].ClassDetail << std::endl;
                    }
                    State = 1;
                    output.close();
                }else if(t != 'Y'){
                    std::cout << "您输入的字母有误，请重新输入！";
                    goto choose;
                }else {
                    int choicee = 0;
                    std::cout << "请输入要修改的内容对应的序号：[1]课程号 [2]课程名 [3]学分 [4]课程描述（输入一个数字）：";
                    std::cin >> choicee;
                    std::cin.get();
                    std::string neww;
                    switch (choicee) {
                        case 1:
                            std::cout << "请输入新内容：";
                            std::getline(std::cin,neww);
                            classes[i].ClassNO = neww;
                            break;
                        case 2:
                            std::cout << "请输入新内容：";
                            std::getline(std::cin,neww);
                            classes[i].ClassName = neww;
                            break;
                        case 3:
                            std::cout << "请输入新内容:";
                            int ss;
                            std::cin >> ss;
                            std::cin.get();
                            classes[i].ClassScore = ss;
                            break;
                        case 4:
                            std::cout << "请输入新内容：";
                            std::getline(std::cin,neww);
                            classes[i].ClassDetail = neww;
                            break;
                    }
                    open1.close();
                    std::ofstream output("b");
                    for (int count = 0;classes[count].ClassNO != "\000";count++){
                        output << classes[count].ClassNO << std::endl;
                        output << classes[count].ClassName << std::endl;
                        output << classes[count].ClassScore << std::endl;
                        output << classes[count].ClassDetail << std::endl;
                    }
                    State = 1;
                    output.close();
                    std::cout << "课程成功修改" << std::endl;
                }
            }
        }
    if (State == 0)
    {std::cout << "未找到对应的课程，请重新输入！" << std::endl;
        goto again;}
    open1.close();
    std::ofstream output("b");
    for (int i = 0;classes[i].ClassNO != "\000";i++){
        output << classes[i].ClassNO << std::endl;
        output << classes[i].ClassName << std::endl;
        output << classes[i].ClassScore << std::endl;
        output << classes[i].ClassDetail << std::endl;
    }
    output.close();
}

void lookup2(){
    std::ifstream open1("b");
    for (int i = 0; ;i++){
        if (open1.eof())
            break;
        std::getline(open1,classes[i].ClassNO);
        std::getline(open1,classes[i].ClassName);
        open1 >> classes[i].ClassScore;
        std::string tempstr;
        std::getline(open1,tempstr);
        std::getline(open1,classes[i].ClassDetail);
    }
    again:
    std::cout << "希望通过那种方式查询？[1]课程号 [2]课程名 [3]学分 [4]课程描述 :";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>4){
        std::cout << "输入的序号有误，请重新输入！";
        goto again;}else
        std::cout << "请输入要查询的课程的";
    std::string thisisastr;
    int xuefen = 0;
    switch (t){
        case 1:
            std::cout << "课程号 ";
            std::getline(std::cin,thisisastr);
            break;

        case 2:
            std::cout << "课程名 ";
            std::getline(std::cin,thisisastr);
            break;

        case 3:
            std::cout << "学分 ";
            std::cin >> xuefen;
            std::cin.get();
            break;

        case 4:
            std::cout << "课程描述（仅限一行，以回车结束）";
            std::getline(std::cin,thisisastr);
            break;

    }
    int State = 0;
    if (t == 1||t == 2||t == 4) {
        int i;
        for (i = 0; classes[i].ClassNO != "\000"; i++) {
            if (classes[i].ClassNO == thisisastr || classes[i].ClassDetail == thisisastr || classes[i].ClassName == thisisastr) {
                std::cout << "找到符合条件的课程" << std::endl;
                std::cout << "课程名：" << classes[i].ClassName << std::endl << "课程号：" << classes[i].ClassNO << std:: endl <<
                          "课程描述：" << classes[i].ClassDetail << std::endl <<
                          "学分：" << classes[i].ClassScore << std::endl;
                std::cout << "请按回车键继续......";
                std::string temp;
                std::getline(std::cin,temp) ;
                State = 1;
            }
        }
    }else {
        int i;
        for (i = 0; classes[i].ClassNO != "\000"; i++) {
            if (classes[i].ClassScore == xuefen) {
                std::cout << "找到符合条件的课程" << std::endl;
                std::cout << "课程号：" << classes[i].ClassNO << std::endl <<
                          "课程名：" << classes[i].ClassName << std::endl <<
                          "课程描述：" << classes[i].ClassDetail << std::endl <<
                          "学分：" << classes[i].ClassScore << std::endl;
                std::cout << "请按回车键继续......";
                std::string temp;
                std::getline(std::cin,temp) ;
                State = 1;
            }
        }
    }
    if (State == 0)
    {std::cout << "未找到对应的课程，请重新输入！" << std::endl;
        goto again;}
    return;
}

void tianjia3(){
    std::ifstream read2;
    read2.open("c",std::ifstream::app); //
    readGradeinfo(read2);
    read2.close();
    std::fstream read1;
    read1.open("c",std::fstream::app);
    std::cout << "请输入学号：";
    {
        std::string xuehao;
        loop1:
        std::getline(std::cin,xuehao);
//        for (int i = 0;grades[i].StuNum != "\000";i++){
//            if (xuehao == grades[i].StuNum) {
//                std::cout << "学号重复，请重新输入！";
//                goto loop1;
//            }
//        }
        read1 << xuehao << std::endl;
    }
    std::cout << "请输入课程号：";
    {
        std::string Name;
        loop2:
        std::getline(std::cin,Name);
        for (int i = 0;grades[i].StuNum != "\000";i++){
            if (Name == grades[i].ClassNO) {
                std::cout << "课程号重复，请重新输入！";
                goto loop2;
            }
        }
        read1 << Name << std::endl;
    }
    std::cout << "请输入成绩（整数）：";
    {
        double Xuefen;
        loop3:
        std::cin >> Xuefen;
        std::cin.get();
//        for (int i = 0;grades[i].StuNum != "\000";i++){
//            if (Xuefen == grades[i].ClassScore) {
//                std::cout << "成绩重复，请重新输入！";
//                goto loop3;
//            }
//        }
        read1 << Xuefen << std::endl;
    }
    std::cout << "信息录入成功，即将返回主菜单";
    read1.close();
}

void delete3(){
    std::ifstream open1("c");
    readGradeinfo(open1);
    again:
    std::cout << "希望通过那种方式查询？[1]学号 [2]课程号 [3]成绩 :";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>3){
        std::cout << "输入的序号有误，请重新输入！";
        goto again;}else
        std::cout << "请输入要删除的成绩的";
    std::string thisisastr;
    int xuefen = 0;
    switch (t){
        case 1:
            std::cout << "学号 ";
            std::getline(std::cin,thisisastr);
            break;

        case 2:
            std::cout << "课程号 ";
            std::getline(std::cin,thisisastr);
            break;

        case 3:
            std::cout << "成绩 ";
            std::cin >> xuefen;
            std::cin.get();
            break;

    }
    int State = 0;
    if (t == 1||t == 2) {
        int i;
        for (i = 0; grades[i].ClassNO != "\000"; i++) {
            if (grades[i].ClassNO == thisisastr || grades[i].StuNum == thisisastr) {
                std::cout << "找到符合条件的成绩，是否要删除？" << std::endl;
                std::cout << "学号：" << grades[i].StuNum << std::endl <<
                          "课程号：" << grades[i].ClassNO << std::endl <<
                          "成绩：" << grades[i].ClassScore << std::endl;
                char t;
                choose:
                std::cout << "请选择（输入Y或N）:";
                std::cin >> t;
                std::cin.get();
                if(t == 'N'){
                    open1.close();
                    std::ofstream output("c");
                    for (int count = 0;grades[count].ClassNO != "\000";count++){
                        output << grades[count].StuNum << std::endl;
                        output << grades[count].ClassNO << std::endl;
                        output << grades[count].ClassScore << std::endl;
                        State = 1;
                    }
                    output.close();
                }else if(t != 'Y'){
                    std::cout << "您输入的字母有误，请重新输入！";
                    goto choose;
                }else {
                    for (int count = i; grades[count].ClassNO != "\000"; count++) {
                        grades[count].StuNum = grades[count + 1].StuNum;
                        grades[count].ClassNO = grades[count + 1].ClassNO;
                        grades[count].ClassScore = grades[count + 1].ClassScore;
                        State = 1;
                    }
                    i--;
                    std::cout << "课程成功删除" << std::endl;
                }
            }
        }
    }else {
        int i;
        for (i = 0; grades[i].ClassNO != "\000"; i++) {
            if (grades[i].ClassScore == xuefen) {
                std::cout << "找到符合条件的课程，是否要删除？" << std::endl;
                std::cout << "学号：" << grades[i].StuNum << std::endl <<
                          "课程号：" << grades[i].ClassNO << std::endl <<
                          "成绩：" << grades[i].ClassScore << std::endl;
                char t;
                choose2:
                std::cout << "请选择（输入Y或N）:";
                std::cin >> t;
                std::cin.get();
                if(t == 'N'){
                    open1.close();
                    std::ofstream output("c");
                    for (int count = 0;grades[count].ClassNO != "\000";count++){
                        output << grades[count].StuNum << std::endl;
                        output << grades[count].ClassNO << std::endl;
                        output << grades[count].ClassScore << std::endl;
                        State = 1;
                    }
                    output.close();
                }else if(t != 'Y'&&t != 'N'){
                    std::cout << "您输入的字母有误，请重新输入！";
                    goto choose2;
                }else{
                    for (int count = i; grades[count].ClassNO != "\000"; count++) {
                        grades[count].StuNum = grades[count + 1].StuNum;
                        grades[count].ClassNO = grades[count + 1].ClassNO;
                        grades[count].ClassScore = grades[count + 1].ClassScore;
                        State = 1;
                    }
                    i--;
                    std::cout << "课程成功删除" << std::endl;
                }
            }
        }
    }
    if (State == 0)
    {std::cout << "未找到对应的成绩，请重新输入！" << std::endl;
        goto again;}
    open1.close();
    std::ofstream output("c");
    for (int count = 0;grades[count].ClassNO != "\000";count++){
        output << grades[count].StuNum << std::endl;
        output << grades[count].ClassNO << std::endl;
        output << grades[count].ClassScore << std::endl;
    }
    output.close();
}

void modify3(){
    std::ifstream open1("c");
    readGradeinfo(open1);
    again:
    std::cout << "希望通过那种方式查询？[1]学号 [2]课程号 [3]成绩:";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>3){
        std::cout << "输入的序号有误，请重新输入！";
        goto again;}else
        std::cout << "请输入要修改的课程的";
    std::string thisisastr;
    int xuefen = 0;
    switch (t) {
        case 1:
            std::cout << "学号 ";
            std::getline(std::cin, thisisastr);
            break;

        case 2:
            std::cout << "课程号 ";
            std::getline(std::cin, thisisastr);
            break;

        case 3:
            std::cout << "成绩 ";
            std::cin >> xuefen;
            std::cin.get();
            break;

    }
    int State = 0;
    int i;
    for (i = 0; grades[i].ClassNO != "\000"; i++) {
        if (grades[i].ClassNO == thisisastr || grades[i].StuNum == thisisastr || grades[i].ClassScore == xuefen) {
            std::cout << "找到符合条件的成绩，是否要修改？" << std::endl;
            std::cout <<  "学号：" << grades[i].StuNum << std::endl <<
                      "课程号：" << grades[i].ClassNO << std::endl <<
                      "成绩：" << grades[i].ClassScore << std::endl;
            char t;
            choose:
            std::cout << "请选择（输入Y或N）:";
            std::cin >> t;
            std::cin.get();
            if (t == 'N'){
                open1.close();
                std::ofstream output("c");
                for (int count = 0;grades[count].StuNum != "\000";count++){
                    output << grades[count].StuNum << std::endl;
                    output << grades[count].ClassNO << std::endl;
                    output << grades[count].ClassScore << std::endl;
                }
                State = 1;
                output.close();
            }else if(t != 'Y'){
                std::cout << "您输入的字母有误，请重新输入！";
                goto choose;
            }else {
                int choicee = 0;
                std::cout << "请输入要修改的内容对应的序号：[1]学号 [2]课程号 [3]成绩（输入一个数字）：";
                std::cin >> choicee;
                std::cin.get();
                std::string neww;
                loop2:
                switch (choicee) {
                    case 1:{
                        std::cout << "请输入新内容：";
                        std::getline(std::cin,neww);
                        for (int count = 0;grades[count].ClassNO != "\000";count++) {
                            if (neww == grades[count].StuNum){
                                std::cout << "输入的内容不能重复，请重新输入！";
                                goto loop2;}
                        }
                        grades[i].StuNum = neww;
                        break;}
                    case 2:{
                        std::cout << "请输入新内容：";
                        std::getline(std::cin,neww);
                        for (int count = 0;grades[count].ClassNO != "\000";count++) {
                            if (neww == grades[count].ClassNO){
                                std::cout << "输入的内容不能重复，请重新输入！";
                                goto loop2;}
                        }
                        grades[i].ClassNO = neww;
                        break;}
                    case 3:{
                        std::cout << "请输入新内容:";
                        int ss;
                        std::cin >> ss;
                        std::cin.get();
                        for (int count = 0;grades[count].ClassNO != "\000";count++) {
                            if (ss == grades[count].ClassScore){
                                std::cout << "输入的内容不能重复，请重新输入！";
                                goto loop2;}
                        }
                        grades[i].ClassScore = ss;
                        break;}
                }
                open1.close();
                std::ofstream output("c");
                for (int count = 0;grades[count].ClassNO != "\000";count++){
                    output << grades[count].StuNum << std::endl;
                    output << grades[count].ClassNO << std::endl;
                    output << grades[count].ClassScore << std::endl;
                }
                State = 1;
                output.close();
                std::cout << "成绩成功修改" << std::endl;
            }
        }
    }
    if (State == 0)
    {std::cout << "未找到对应的成绩，请重新输入！" << std::endl;
        goto again;}
    open1.close();
    std::ofstream output("c");
    for (int count = 0;grades[count].ClassNO != "\000";count++){
        output << grades[count].StuNum << std::endl;
        output << grades[count].ClassNO << std::endl;
        output << grades[count].ClassScore << std::endl;
    }
    output.close();
}

void lookup3(){
    std::ifstream open2("b");
    readClassInfo(open2);
    std::ifstream open1("c");
    readGradeinfo(open1);
    again:
    std::cout << "希望通过那种方式查询？[1]学号 [2]课程号 [3]成绩 :";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>3){
        std::cout << "输入的序号有误，请重新输入！";
        goto again;}else
        std::cout << "请输入要查询的成绩的";
    std::string thisisastr;
    int xuefen = 0;
    switch (t){
        case 1:
            std::cout << "学号 ";
            std::getline(std::cin,thisisastr);
            break;

        case 2:
            std::cout << "课程号 ";
            std::getline(std::cin,thisisastr);
            break;

        case 3:
            std::cout << "成绩 ";
            std::cin >> xuefen;
            std::cin.get();
            break;

    }
    int State = 0;
    if (t == 1||t == 2) {
        int i;
        for (i = 0; grades[i].ClassNO != "\000"; i++) {
            if (grades[i].ClassNO == thisisastr || grades[i].StuNum == thisisastr ) {
                std::cout << "找到符合条件的成绩" << std::endl;
                std::cout << "学号：" << grades[i].StuNum << std::endl <<
                          "课程号：" << grades[i].ClassNO << std::endl <<
                          "成绩：" << grades[i].ClassScore << std::endl;
                std::string classno = grades[i].ClassNO;
                for (int i = 0;classes[i].ClassNO != "\000";i++){
                    if (classes[i].ClassNO == classno)
                        std::cout << "课程名：" << classes[i].ClassName << std::endl;
                }
                std::cout << "请按回车键继续......";
                std::string temp;
                std::getline(std::cin,temp) ;
                State = 1;
                std::cout << std::endl;
            }
        }
    }else {
        int i;
        for (i = 0; grades[i].ClassNO != "\000"; i++) {
            if (grades[i].ClassScore == xuefen) {
                std::cout << "找到符合条件的成绩" << std::endl;
                std::cout << "学号：" << grades[i].StuNum << std::endl <<
                          "课程号：" << grades[i].ClassNO << std::endl ;
                std::string classno = grades[i].ClassNO;
                for (int i = 0;classes[i].ClassNO != "\000";i++){
                    if (classes[i].ClassNO == classno)
                        std::cout << "课程名：" << classes[i].ClassName << std::endl;
                }
                          std::cout << "成绩：" << grades[i].ClassScore << std::endl;
                std::cout << "请按回车键继续......";
                std::string temp;
                std::getline(std::cin,temp) ;
                State = 1;
            }
        }
    }
    if (State == 0)
    {std::cout << "未找到对应的课程，请重新输入！" << std::endl;
        goto again;}
    return;
}

double calcu_GPA(int score){
    double GPAs;
        if (score >= 90){
            GPAs = 4.0;
        }else if (score < 90 && score >=60){
            GPAs = 4.0 - (90 - score) / 10.0;
        }else GPAs = 0.0;
    return GPAs;
};

void outputscore1(Stuinformation (&Stuinfo)[100]) {
    std::ifstream classinfo;
    classinfo.open("b");
    readClassInfo(classinfo);
    int sumxuefen = 0;
    for (int i = 0; classes[i].ClassNO != "\000"; i++) {
        sumxuefen += classes[i].ClassScore;
    }
    std::cout << "请输入学生的[1]姓名 或[2]学号：";
    int choice;
    std::cin >> choice;
    std::cin.get();
    std::string StuNumber;
    if (choice == 1) {
        int count = 0;
        std::cout << "请输入学生的姓名：";
        std::string StuName;
        std::getline(std::cin, StuName);
        int FoundNamesame[100];
        for (int i = 0; Stuinfo[i].StuNum != "\000"; i++) {
            if (Stuinfo[i].StuName == StuName) {
                StuNumber = Stuinfo[i].StuNum;
                count += 1;
                FoundNamesame[count - 1] = i;
            }
        }
        if (count == 0) {
            std::cout << "没找到哈";
            return;
        } else if (count > 1) {
            std::cout << "共找到" << count << "个结果，哪个是想要查询的同学？" << std::endl;
            for (int temp2 = 0; temp2 <= count; temp2++) {
                std::cout << "第" << temp2 + 1 << "个同学";
                std::cout << std::endl << "学号：" << students[FoundNamesame[temp2]].StuNum;
                std::cout << std::endl << "姓名: " << students[FoundNamesame[temp2]].StuName;
                std::cout << std::endl << "班级：" << students[FoundNamesame[temp2]].StuClass;
                std::cout << std::endl << "性别：";
                if (students[FoundNamesame[temp2]].StuSex == 'm') std::cout << "男";
                else std::cout << "女";
                std::cout << std::endl << "专业：" << students[FoundNamesame[temp2]].StuMajor << std::endl << std::endl;
            }
            int who;
            std::cin >> who;
            std::cin.get();
            StuNumber = students[FoundNamesame[0]].StuNum;
        }
    }else {
        std::cout << "请输入学号：";
        std::getline(std::cin, StuNumber);}
    std::ifstream Stu_Scores;
    Stu_Scores.open("c");
    readGradeinfo(Stu_Scores);
    double chengji[100] = {0};
    int i = -1;
    for (int countNum = 0; grades[countNum].StuNum != "\000"; countNum++) {
        if (grades[countNum].StuNum == StuNumber) {
            i++;
            int k;
            std::cout << grades[countNum].ClassNO << " " ;
            std::cout << grades[countNum].ClassScore << "    " << "学分绩点：" << calcu_GPA(grades[countNum].ClassScore)  << "  ";
            for (int count = 0;classes[count].ClassNO != "\000";count++){
                if (classes[count].ClassNO == grades[countNum].ClassNO)
                    std::cout << classes[count].ClassName << "  ";
            }
            std::cout << std::endl;
            for (k = 0;classes[k].ClassNO !=grades[countNum].ClassNO;k++) { ;
            }
            chengji[i] = calcu_GPA(grades[countNum].ClassScore) * classes[k].ClassScore ; //这一科目的平均绩点

        }
    }
    double chengjisum;
    for (int i = 0;chengji[i] != 0;i++){
        chengjisum += chengji[i];
    }
    double avr_GPA = chengjisum / sumxuefen;
            std::cout << "该学生的学分绩点为：" << avr_GPA << std::endl;
}

double calculateGPA(std::string &stu_num,int Sumxuefen){
std::ifstream open;
open.open("c");
readGradeinfo(open);
    double chengji[100] = {0};
    int k = -1;
    for (int i = 0;grades[i].StuNum != "\000";i++) {
        if (grades[i].StuNum == stu_num){
            k++;
            int count;
            for (count = 0;classes[count].ClassNO !=grades[i].ClassNO;count++) { ;
            }
            chengji[k] = calcu_GPA(grades[i].ClassScore) * classes[count].ClassScore;
        }
    }
    double chengjisum = 0.0;
    for (int i = 0;chengji[i] != 0;i++){
        chengjisum += chengji[i];
    }
    double avr_GPA = chengjisum / Sumxuefen;
    return avr_GPA;

}

std::string WhatYourName(std::string Stunum){
    for (int i = 0;students[i].StuNum != "\000";i++){
        if (students[i].StuNum == Stunum)
            return students[i].StuName;
    }
}

std::string WhatyourClass(std::string Stunum){
    for (int i = 0;students[i].StuNum != "\000";i++){
        if (students[i].StuNum == Stunum)
            return students[i].StuClass;
    }
}

std::string returnsomespaces(std::string &str){
    std::string space;
    if(str.size()==6){
        space = "  ";
    }else if (str.size()==4){
        space = "    ";
    }else space = " ";
    return space;
}

void Rankings(){
    struct StuScore{
        std::string StuN = "\000";
        double GPAs = 0.0;
    };
    StuScore students_scores[100] = {{"\000",0.0}};
    std::cout << "请问要查询哪个专业的同学的成绩？" ;
    std::string Major;
    std::getline(std::cin,Major);
    std::ifstream classinfo; //calculate  sumXuefen
    classinfo.open("b");
    readClassInfo(classinfo);
    classinfo.close();
    int sumxuefen = 0;
    for (int i = 0; classes[i].ClassNO != "\000"; i++) {
        sumxuefen += classes[i].ClassScore;
    }
    int countt = -1,state = 0;
    for (int i = 0;students[i].StuNum !=  "\000";i++){  //从人名册中找到该专业的学生并计算出该学生的绩点
        if (students[i].StuMajor == Major){
            countt++;
            students_scores[countt].GPAs =  calculateGPA(students[i].StuNum,sumxuefen);
            students_scores[countt].StuN = students[i].StuNum;
            state = 1;
        }
    }
    if (state == 0){
        std::cout << "没有找到相应的学生！" << std::endl;
        return;
    }
    int count = 0;
    int N;
    for (N = 1; students_scores[N - 1].GPAs != 0.0; ++N) { }
    for (int i = 0;i < N - 1;i++){
        int index_max = i;
        for (int count = i + 1;count < N;count++){
            if (students_scores[index_max].GPAs < students_scores[count].GPAs){
                index_max = count;
            }
        }
        if (index_max != i){
            double temp = students_scores[i].GPAs;
            students_scores[i].GPAs = students_scores[index_max].GPAs;
            students_scores[index_max].GPAs = temp;
            std::string temp2 = students_scores[i].StuN;
            students_scores[i].StuN = students_scores[index_max].StuN;
            students_scores[index_max].StuN = temp2;
        }
    }

    std::cout << "序号" << "  " << "学号" << "    " << "姓名" << "    " << "班级"  << "     " << "绩点" << "   " << "排名" << std::endl;
    int cunt = 0;
    for (int i = 0;students_scores[i].GPAs != 0.0;i++) {
        std::cout << i + 1 << "    " << students_scores[i].StuN << "  " << WhatYourName(students_scores[i].StuN)  ;
        std::string ttemp;
        ttemp = WhatYourName(students_scores[i].StuN);
        std::cout << returnsomespaces(ttemp) << WhatyourClass(students_scores[i].StuN)
        << "    " << students_scores[i].GPAs << "  " ;
        if (students_scores[i].GPAs == students_scores[i - 1].GPAs && i != 0){
            cunt++;
            std::cout << i - cunt;
        }else if (i == 0)
            std::cout << i+1;
        else if (students_scores[i].GPAs != students_scores[i - 1].GPAs && i != 0){
            cunt = 0;
            std::cout << i + 1;
        }
        std::cout << std::endl ;
    }
    return ;
}

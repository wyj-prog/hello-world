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
        std::cout << "δ�ܳɹ����ļ�������ѧ����Ϣ�ļ��Ƿ���ڣ�" << std::endl;
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
    std::cout << std::endl << "***��ӭ���ʺӱ���ҵ��ѧѧ���ɼ�����ϵͳ***" << std::endl;
    std::cout << "Powered by ���       Version 0.9.9" << std::endl;
    std::cout << "[1] ά��ѧ����Ϣ" << std::endl << "[2] ά���γ���Ϣ" << std::endl << "[3] ά���ɼ���Ϣ"
    << std::endl << "[4] ����ɼ���" << std::endl << "[5] �����������" << std::endl << "[6] �˳�ϵͳ" << std::endl;
    std::cout << "��ѡ����Ӧ�Ĺ��ܣ� ";
    float choice = 0;
    input1:
    std::cin >> choice;
    std::cin.get();
    if (choice > 6 || choice <= 0|| int(choice)!=choice ){                                             //���������
        std::cout << "���������������������룡 ";
        goto input1;}
    if (choice == 1 || choice == 2|| choice == 3) {                             //����ά�������
        std::cout << "��ѡ���һ���Ĳ�����[1]��� [2]ɾ�� [3]�޸� [4]��ѯ ";
        float temp = 0;
        input2:
        std::cin >> temp;
        std::cin.get();
        if (temp < 0||temp > 4|| int(temp)!=temp ) {
            std::cout << "���������������������룡 ";
            goto input2;
        }else if(temp == 1) {                                                    //���
            if (choice == 1) {
                tianjia1(students,read1);
                goto readagain;
            }else
            if (choice == 2) tianjia2();else
            if (choice == 3) tianjia3();
        }else if (temp == 2){                                                    //ɾ��
            if (choice == 1) {
                delete1(students,read1);
                goto readagain;
            }else
            if (choice == 2) delete2();else
            if (choice == 3) delete3();
        }else if (temp ==3){                                                     //�޸�
            if (choice == 1) modify1();else
            if (choice == 2) modify2();else
            if (choice == 3) modify3();
        }else if(temp == 4){                                                    //��ѯ
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
            std::cout << "��л����ʹ�ã�ף��������죬�ڴ����´�ʹ�ã��ټ���" << std::endl;
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
        std::cout << "������ѧ�ţ�";
        {
            std::string xuehao;
            loop:
            std::getline(std::cin, xuehao);
            for (int i = 0; students[i].StuNum != "\000"; i++){
                if (xuehao == students[i].StuNum){
                    std::cout << "ѧ�Ų������ظ������������룡";
                    goto loop;
                }

            }
            read1.close();
            read1.open("a",std::fstream::app);
            read1 << xuehao << std::endl;
        }
        std::cout << "������������";
        {
            std::string Name;
            std::getline(std::cin, Name);
            read1 << Name << std::endl;
        }
        std::cout << "������༶��";
        {
            std::string Class;
            std::getline(std::cin, Class);
            read1 << Class << std::endl;
        }
        std::cout << "�������Ա���m����f����";
        {
            char Sex;
            std::cin >> Sex;
            std::cin.get();
            read1 << Sex << std::endl;
        }
        std::cout << "������רҵ��";
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
        std::cout << "������Ҫɾ����ͬѧ��ѧ�ţ�";
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
    {std::cout << "δ�ҵ���ѧ�ţ����������룡" << std::endl;
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
    std::cout << "��������Ҫ�޸ĵ�ͬѧ��ѧ�ţ�";
    std::string num1;
    std::cin >> num1;
    std::cin.get();
    for (int i = 0; students[i].StuNum != "\000"; i++){
        if (students[i].StuNum == num1){
            std::cout << "�ҵ���ͬѧ����ѡ��Ҫ�޸ĵ����ݣ�[1]ѧ�� [2]���� [3]�༶ [4]�Ա� [5]רҵ";
            int k;
            input:
            std::cin >> k;
            std::cin.get();
            if (k < 1||k > 5){
                std::cout << "��Ŵ������������룡";
                goto input;
            }
            std::string neww;
            switch (k) {
                case 1:
                    std::cout << "�����������ݣ�";
                    std::getline(std::cin,neww);
                    students[i].StuNum = neww;
                    break;
                case 2:
                    std::cout << "�����������ݣ�";
                    std::getline(std::cin,neww);
                    students[i].StuName = neww;
                    break;
                case 3:
                    std::cout << "�����������ݣ�";
                    std::getline(std::cin,neww);
                    students[i].StuClass = neww;
                    break;
                case 4:
                    std::cout << "������������(m or f):";
                    char ii;
                    std::cin >> ii;
                    std::cin.get();
                    students[i].StuSex = ii;
                    break;
                case 5:
                    std::cout << "�����������ݣ�";
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
        }else std::cout << "������..." << std::endl;
    }
    std::cout << "û�ҵ���,�Ƿ����������룿��Y����N��" ;
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
    std::cout << "��������Ҫ��ѯ��ͬѧ��ѧ�ţ�";
    std::string num1;
    std::cin >> num1;
    std::cin.get();
    for (int i = 0; students[i].StuNum != "\000"; i++){
        if (students[i].StuNum == num1){
            std::cout << "�ҵ���ͬѧ" << std::endl;
                    std::cout << std::endl << "ѧ�ţ�" << students[i].StuNum;

                    std::cout << std::endl << "����: " << students[i].StuName;

                    std::cout << std::endl << "�༶��" << students[i].StuClass;

                    std::cout << std::endl << "�Ա�" ;
            if (students[i].StuSex == 'm') std::cout << "��";
            else std::cout << "Ů";

                    std::cout << std::endl << "רҵ��" << students[i].StuMajor << std::endl <<std::endl;
            open1.close();
            std::cout << "�밴�س�������......";
            std::string temp;
            std::getline(std::cin,temp) ;
            return ; //��������
            }else std::cout << "������..." << std::endl;
    }
open1.close();
    std::cout << "û�ҵ���" << std::endl;
    std::cout << "�Ƿ����������룿��Y����N��" ;
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
            std::cout << "������γ̺ţ�";
        {
            std::string xuehao;
            std::getline(std::cin,xuehao);
            read1 << xuehao << std::endl;
        }
        std::cout << "������γ�����";
        {
            std::string Name;
            std::getline(std::cin,Name);
            read1 << Name << std::endl;
        }
        std::cout << "������ѧ�֣���������";
        {
            double Xuefen;
            std::cin >> Xuefen;
            std::cin.get();
            read1 << Xuefen << std::endl;
        }
        std::cout << "������γ�����������һ�У��Իس���������";
        {
            std::string description;
            std::getline(std::cin,description);
            read1 << description << std::endl;
        }
        std::cout << "��Ϣ¼��ɹ��������������˵�";
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
    std::cout << "ϣ��ͨ�����ַ�ʽ��ѯ��[1]�γ̺� [2]�γ��� [3]ѧ�� [4]�γ����� :";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>4){
        std::cout << "���������������������룡";
    goto again;}else
    std::cout << "������Ҫɾ���Ŀγ̵�";
    std::string thisisastr;
    int xuefen = 0;
    switch (t){
        case 1:
            std::cout << "�γ̺� ";
            std::getline(std::cin,thisisastr);
            break;

        case 2:
            std::cout << "�γ��� ";
            std::getline(std::cin,thisisastr);
            break;

        case 3:
            std::cout << "ѧ�� ";
            std::cin >> xuefen;
            std::cin.get();
            break;

        case 4:
            std::cout << "�γ�����������һ�У��Իس�������";
            std::getline(std::cin,thisisastr);
            break;

    }
    int State = 0;
    if (t == 1||t == 2||t == 4) {
        int i;
        for (i = 0; classes[i].ClassNO != "\000"; i++) {
            if (classes[i].ClassNO == thisisastr || classes[i].ClassDetail == thisisastr || classes[i].ClassName == thisisastr) {
                std::cout << "�ҵ����������Ŀγ̣��Ƿ�Ҫɾ����" << std::endl;
                std::cout << "�γ�����" << classes[i].ClassName << std::endl << "�γ̺ţ�" << classes[i].ClassNO << std:: endl <<
                "�γ�������" << classes[i].ClassDetail << std::endl <<
                "ѧ�֣�" << classes[i].ClassScore << std::endl;
                char t;
                choose:
                std::cout << "��ѡ������Y��N��:";
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
                    std::cout << "���������ĸ�������������룡";
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
                    std::cout << "�γ̳ɹ�ɾ��" << std::endl;
                }
            }
        }
    }else {
        int i;
        for (i = 0; classes[i].ClassNO != "\000"; i++) {
            if (classes[i].ClassScore == xuefen) {
                std::cout << "�ҵ����������Ŀγ̣��Ƿ�Ҫɾ����" << std::endl;
                std::cout << "�γ̺ţ�" << classes[i].ClassNO << std::endl <<
                          "�γ�����" << classes[i].ClassName << std::endl <<
                          "�γ�������" << classes[i].ClassDetail << std::endl <<
                          "ѧ�֣�" << classes[i].ClassScore << std::endl;
                char t;
                choose2:
                std::cout << "��ѡ������Y��N��:";
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
                    std::cout << "���������ĸ�������������룡";
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
                std::cout << "�γ̳ɹ�ɾ��" << std::endl;
                }
            }
        }
    }
    if (State == 0)
    {std::cout << "δ�ҵ���Ӧ�Ŀγ̣����������룡" << std::endl;
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
    std::cout << "ϣ��ͨ�����ַ�ʽ��ѯ��[1]�γ̺� [2]�γ��� [3]ѧ�� [4]�γ����� :";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>4){
        std::cout << "���������������������룡";
        goto again;}else
        std::cout << "������Ҫ�޸ĵĿγ̵�";
    std::string thisisastr;
    int xuefen = 0;
    switch (t){
        case 1:
            std::cout << "�γ̺� ";
            std::getline(std::cin,thisisastr);
            break;

        case 2:
            std::cout << "�γ��� ";
            std::getline(std::cin,thisisastr);
            break;

        case 3:
            std::cout << "ѧ�� ";
            std::cin >> xuefen;
            std::cin.get();
            break;

        case 4:
            std::cout << "�γ�����������һ�У��Իس�������";
            std::getline(std::cin,thisisastr);
            break;

    }
    int State = 0;
    int i;
    for (i = 0; classes[i].ClassNO != "\000"; i++) {
        if (classes[i].ClassNO == thisisastr || classes[i].ClassDetail == thisisastr || classes[i].ClassName == thisisastr || classes[i].ClassScore == xuefen) {
                std::cout << "�ҵ����������Ŀγ̣��Ƿ�Ҫ�޸ģ�" << std::endl;
                std::cout << "�γ�����" << classes[i].ClassName << std::endl << "�γ̺ţ�" << classes[i].ClassNO << std:: endl <<
                          "�γ�������" << classes[i].ClassDetail << std::endl <<
                          "ѧ�֣�" << classes[i].ClassScore << std::endl;
                char t;
                choose:
                std::cout << "��ѡ������Y��N��:";
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
                    std::cout << "���������ĸ�������������룡";
                    goto choose;
                }else {
                    int choicee = 0;
                    std::cout << "������Ҫ�޸ĵ����ݶ�Ӧ����ţ�[1]�γ̺� [2]�γ��� [3]ѧ�� [4]�γ�����������һ�����֣���";
                    std::cin >> choicee;
                    std::cin.get();
                    std::string neww;
                    switch (choicee) {
                        case 1:
                            std::cout << "�����������ݣ�";
                            std::getline(std::cin,neww);
                            classes[i].ClassNO = neww;
                            break;
                        case 2:
                            std::cout << "�����������ݣ�";
                            std::getline(std::cin,neww);
                            classes[i].ClassName = neww;
                            break;
                        case 3:
                            std::cout << "������������:";
                            int ss;
                            std::cin >> ss;
                            std::cin.get();
                            classes[i].ClassScore = ss;
                            break;
                        case 4:
                            std::cout << "�����������ݣ�";
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
                    std::cout << "�γ̳ɹ��޸�" << std::endl;
                }
            }
        }
    if (State == 0)
    {std::cout << "δ�ҵ���Ӧ�Ŀγ̣����������룡" << std::endl;
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
    std::cout << "ϣ��ͨ�����ַ�ʽ��ѯ��[1]�γ̺� [2]�γ��� [3]ѧ�� [4]�γ����� :";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>4){
        std::cout << "���������������������룡";
        goto again;}else
        std::cout << "������Ҫ��ѯ�Ŀγ̵�";
    std::string thisisastr;
    int xuefen = 0;
    switch (t){
        case 1:
            std::cout << "�γ̺� ";
            std::getline(std::cin,thisisastr);
            break;

        case 2:
            std::cout << "�γ��� ";
            std::getline(std::cin,thisisastr);
            break;

        case 3:
            std::cout << "ѧ�� ";
            std::cin >> xuefen;
            std::cin.get();
            break;

        case 4:
            std::cout << "�γ�����������һ�У��Իس�������";
            std::getline(std::cin,thisisastr);
            break;

    }
    int State = 0;
    if (t == 1||t == 2||t == 4) {
        int i;
        for (i = 0; classes[i].ClassNO != "\000"; i++) {
            if (classes[i].ClassNO == thisisastr || classes[i].ClassDetail == thisisastr || classes[i].ClassName == thisisastr) {
                std::cout << "�ҵ����������Ŀγ�" << std::endl;
                std::cout << "�γ�����" << classes[i].ClassName << std::endl << "�γ̺ţ�" << classes[i].ClassNO << std:: endl <<
                          "�γ�������" << classes[i].ClassDetail << std::endl <<
                          "ѧ�֣�" << classes[i].ClassScore << std::endl;
                std::cout << "�밴�س�������......";
                std::string temp;
                std::getline(std::cin,temp) ;
                State = 1;
            }
        }
    }else {
        int i;
        for (i = 0; classes[i].ClassNO != "\000"; i++) {
            if (classes[i].ClassScore == xuefen) {
                std::cout << "�ҵ����������Ŀγ�" << std::endl;
                std::cout << "�γ̺ţ�" << classes[i].ClassNO << std::endl <<
                          "�γ�����" << classes[i].ClassName << std::endl <<
                          "�γ�������" << classes[i].ClassDetail << std::endl <<
                          "ѧ�֣�" << classes[i].ClassScore << std::endl;
                std::cout << "�밴�س�������......";
                std::string temp;
                std::getline(std::cin,temp) ;
                State = 1;
            }
        }
    }
    if (State == 0)
    {std::cout << "δ�ҵ���Ӧ�Ŀγ̣����������룡" << std::endl;
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
    std::cout << "������ѧ�ţ�";
    {
        std::string xuehao;
        loop1:
        std::getline(std::cin,xuehao);
//        for (int i = 0;grades[i].StuNum != "\000";i++){
//            if (xuehao == grades[i].StuNum) {
//                std::cout << "ѧ���ظ������������룡";
//                goto loop1;
//            }
//        }
        read1 << xuehao << std::endl;
    }
    std::cout << "������γ̺ţ�";
    {
        std::string Name;
        loop2:
        std::getline(std::cin,Name);
        for (int i = 0;grades[i].StuNum != "\000";i++){
            if (Name == grades[i].ClassNO) {
                std::cout << "�γ̺��ظ������������룡";
                goto loop2;
            }
        }
        read1 << Name << std::endl;
    }
    std::cout << "������ɼ�����������";
    {
        double Xuefen;
        loop3:
        std::cin >> Xuefen;
        std::cin.get();
//        for (int i = 0;grades[i].StuNum != "\000";i++){
//            if (Xuefen == grades[i].ClassScore) {
//                std::cout << "�ɼ��ظ������������룡";
//                goto loop3;
//            }
//        }
        read1 << Xuefen << std::endl;
    }
    std::cout << "��Ϣ¼��ɹ��������������˵�";
    read1.close();
}

void delete3(){
    std::ifstream open1("c");
    readGradeinfo(open1);
    again:
    std::cout << "ϣ��ͨ�����ַ�ʽ��ѯ��[1]ѧ�� [2]�γ̺� [3]�ɼ� :";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>3){
        std::cout << "���������������������룡";
        goto again;}else
        std::cout << "������Ҫɾ���ĳɼ���";
    std::string thisisastr;
    int xuefen = 0;
    switch (t){
        case 1:
            std::cout << "ѧ�� ";
            std::getline(std::cin,thisisastr);
            break;

        case 2:
            std::cout << "�γ̺� ";
            std::getline(std::cin,thisisastr);
            break;

        case 3:
            std::cout << "�ɼ� ";
            std::cin >> xuefen;
            std::cin.get();
            break;

    }
    int State = 0;
    if (t == 1||t == 2) {
        int i;
        for (i = 0; grades[i].ClassNO != "\000"; i++) {
            if (grades[i].ClassNO == thisisastr || grades[i].StuNum == thisisastr) {
                std::cout << "�ҵ����������ĳɼ����Ƿ�Ҫɾ����" << std::endl;
                std::cout << "ѧ�ţ�" << grades[i].StuNum << std::endl <<
                          "�γ̺ţ�" << grades[i].ClassNO << std::endl <<
                          "�ɼ���" << grades[i].ClassScore << std::endl;
                char t;
                choose:
                std::cout << "��ѡ������Y��N��:";
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
                    std::cout << "���������ĸ�������������룡";
                    goto choose;
                }else {
                    for (int count = i; grades[count].ClassNO != "\000"; count++) {
                        grades[count].StuNum = grades[count + 1].StuNum;
                        grades[count].ClassNO = grades[count + 1].ClassNO;
                        grades[count].ClassScore = grades[count + 1].ClassScore;
                        State = 1;
                    }
                    i--;
                    std::cout << "�γ̳ɹ�ɾ��" << std::endl;
                }
            }
        }
    }else {
        int i;
        for (i = 0; grades[i].ClassNO != "\000"; i++) {
            if (grades[i].ClassScore == xuefen) {
                std::cout << "�ҵ����������Ŀγ̣��Ƿ�Ҫɾ����" << std::endl;
                std::cout << "ѧ�ţ�" << grades[i].StuNum << std::endl <<
                          "�γ̺ţ�" << grades[i].ClassNO << std::endl <<
                          "�ɼ���" << grades[i].ClassScore << std::endl;
                char t;
                choose2:
                std::cout << "��ѡ������Y��N��:";
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
                    std::cout << "���������ĸ�������������룡";
                    goto choose2;
                }else{
                    for (int count = i; grades[count].ClassNO != "\000"; count++) {
                        grades[count].StuNum = grades[count + 1].StuNum;
                        grades[count].ClassNO = grades[count + 1].ClassNO;
                        grades[count].ClassScore = grades[count + 1].ClassScore;
                        State = 1;
                    }
                    i--;
                    std::cout << "�γ̳ɹ�ɾ��" << std::endl;
                }
            }
        }
    }
    if (State == 0)
    {std::cout << "δ�ҵ���Ӧ�ĳɼ������������룡" << std::endl;
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
    std::cout << "ϣ��ͨ�����ַ�ʽ��ѯ��[1]ѧ�� [2]�γ̺� [3]�ɼ�:";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>3){
        std::cout << "���������������������룡";
        goto again;}else
        std::cout << "������Ҫ�޸ĵĿγ̵�";
    std::string thisisastr;
    int xuefen = 0;
    switch (t) {
        case 1:
            std::cout << "ѧ�� ";
            std::getline(std::cin, thisisastr);
            break;

        case 2:
            std::cout << "�γ̺� ";
            std::getline(std::cin, thisisastr);
            break;

        case 3:
            std::cout << "�ɼ� ";
            std::cin >> xuefen;
            std::cin.get();
            break;

    }
    int State = 0;
    int i;
    for (i = 0; grades[i].ClassNO != "\000"; i++) {
        if (grades[i].ClassNO == thisisastr || grades[i].StuNum == thisisastr || grades[i].ClassScore == xuefen) {
            std::cout << "�ҵ����������ĳɼ����Ƿ�Ҫ�޸ģ�" << std::endl;
            std::cout <<  "ѧ�ţ�" << grades[i].StuNum << std::endl <<
                      "�γ̺ţ�" << grades[i].ClassNO << std::endl <<
                      "�ɼ���" << grades[i].ClassScore << std::endl;
            char t;
            choose:
            std::cout << "��ѡ������Y��N��:";
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
                std::cout << "���������ĸ�������������룡";
                goto choose;
            }else {
                int choicee = 0;
                std::cout << "������Ҫ�޸ĵ����ݶ�Ӧ����ţ�[1]ѧ�� [2]�γ̺� [3]�ɼ�������һ�����֣���";
                std::cin >> choicee;
                std::cin.get();
                std::string neww;
                loop2:
                switch (choicee) {
                    case 1:{
                        std::cout << "�����������ݣ�";
                        std::getline(std::cin,neww);
                        for (int count = 0;grades[count].ClassNO != "\000";count++) {
                            if (neww == grades[count].StuNum){
                                std::cout << "��������ݲ����ظ������������룡";
                                goto loop2;}
                        }
                        grades[i].StuNum = neww;
                        break;}
                    case 2:{
                        std::cout << "�����������ݣ�";
                        std::getline(std::cin,neww);
                        for (int count = 0;grades[count].ClassNO != "\000";count++) {
                            if (neww == grades[count].ClassNO){
                                std::cout << "��������ݲ����ظ������������룡";
                                goto loop2;}
                        }
                        grades[i].ClassNO = neww;
                        break;}
                    case 3:{
                        std::cout << "������������:";
                        int ss;
                        std::cin >> ss;
                        std::cin.get();
                        for (int count = 0;grades[count].ClassNO != "\000";count++) {
                            if (ss == grades[count].ClassScore){
                                std::cout << "��������ݲ����ظ������������룡";
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
                std::cout << "�ɼ��ɹ��޸�" << std::endl;
            }
        }
    }
    if (State == 0)
    {std::cout << "δ�ҵ���Ӧ�ĳɼ������������룡" << std::endl;
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
    std::cout << "ϣ��ͨ�����ַ�ʽ��ѯ��[1]ѧ�� [2]�γ̺� [3]�ɼ� :";
    int t;
    std::cin >> t;
    std::cin.get();
    if (t<1||t>3){
        std::cout << "���������������������룡";
        goto again;}else
        std::cout << "������Ҫ��ѯ�ĳɼ���";
    std::string thisisastr;
    int xuefen = 0;
    switch (t){
        case 1:
            std::cout << "ѧ�� ";
            std::getline(std::cin,thisisastr);
            break;

        case 2:
            std::cout << "�γ̺� ";
            std::getline(std::cin,thisisastr);
            break;

        case 3:
            std::cout << "�ɼ� ";
            std::cin >> xuefen;
            std::cin.get();
            break;

    }
    int State = 0;
    if (t == 1||t == 2) {
        int i;
        for (i = 0; grades[i].ClassNO != "\000"; i++) {
            if (grades[i].ClassNO == thisisastr || grades[i].StuNum == thisisastr ) {
                std::cout << "�ҵ����������ĳɼ�" << std::endl;
                std::cout << "ѧ�ţ�" << grades[i].StuNum << std::endl <<
                          "�γ̺ţ�" << grades[i].ClassNO << std::endl <<
                          "�ɼ���" << grades[i].ClassScore << std::endl;
                std::string classno = grades[i].ClassNO;
                for (int i = 0;classes[i].ClassNO != "\000";i++){
                    if (classes[i].ClassNO == classno)
                        std::cout << "�γ�����" << classes[i].ClassName << std::endl;
                }
                std::cout << "�밴�س�������......";
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
                std::cout << "�ҵ����������ĳɼ�" << std::endl;
                std::cout << "ѧ�ţ�" << grades[i].StuNum << std::endl <<
                          "�γ̺ţ�" << grades[i].ClassNO << std::endl ;
                std::string classno = grades[i].ClassNO;
                for (int i = 0;classes[i].ClassNO != "\000";i++){
                    if (classes[i].ClassNO == classno)
                        std::cout << "�γ�����" << classes[i].ClassName << std::endl;
                }
                          std::cout << "�ɼ���" << grades[i].ClassScore << std::endl;
                std::cout << "�밴�س�������......";
                std::string temp;
                std::getline(std::cin,temp) ;
                State = 1;
            }
        }
    }
    if (State == 0)
    {std::cout << "δ�ҵ���Ӧ�Ŀγ̣����������룡" << std::endl;
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
    std::cout << "������ѧ����[1]���� ��[2]ѧ�ţ�";
    int choice;
    std::cin >> choice;
    std::cin.get();
    std::string StuNumber;
    if (choice == 1) {
        int count = 0;
        std::cout << "������ѧ����������";
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
            std::cout << "û�ҵ���";
            return;
        } else if (count > 1) {
            std::cout << "���ҵ�" << count << "��������ĸ�����Ҫ��ѯ��ͬѧ��" << std::endl;
            for (int temp2 = 0; temp2 <= count; temp2++) {
                std::cout << "��" << temp2 + 1 << "��ͬѧ";
                std::cout << std::endl << "ѧ�ţ�" << students[FoundNamesame[temp2]].StuNum;
                std::cout << std::endl << "����: " << students[FoundNamesame[temp2]].StuName;
                std::cout << std::endl << "�༶��" << students[FoundNamesame[temp2]].StuClass;
                std::cout << std::endl << "�Ա�";
                if (students[FoundNamesame[temp2]].StuSex == 'm') std::cout << "��";
                else std::cout << "Ů";
                std::cout << std::endl << "רҵ��" << students[FoundNamesame[temp2]].StuMajor << std::endl << std::endl;
            }
            int who;
            std::cin >> who;
            std::cin.get();
            StuNumber = students[FoundNamesame[0]].StuNum;
        }
    }else {
        std::cout << "������ѧ�ţ�";
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
            std::cout << grades[countNum].ClassScore << "    " << "ѧ�ּ��㣺" << calcu_GPA(grades[countNum].ClassScore)  << "  ";
            for (int count = 0;classes[count].ClassNO != "\000";count++){
                if (classes[count].ClassNO == grades[countNum].ClassNO)
                    std::cout << classes[count].ClassName << "  ";
            }
            std::cout << std::endl;
            for (k = 0;classes[k].ClassNO !=grades[countNum].ClassNO;k++) { ;
            }
            chengji[i] = calcu_GPA(grades[countNum].ClassScore) * classes[k].ClassScore ; //��һ��Ŀ��ƽ������

        }
    }
    double chengjisum;
    for (int i = 0;chengji[i] != 0;i++){
        chengjisum += chengji[i];
    }
    double avr_GPA = chengjisum / sumxuefen;
            std::cout << "��ѧ����ѧ�ּ���Ϊ��" << avr_GPA << std::endl;
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
    std::cout << "����Ҫ��ѯ�ĸ�רҵ��ͬѧ�ĳɼ���" ;
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
    for (int i = 0;students[i].StuNum !=  "\000";i++){  //�����������ҵ���רҵ��ѧ�����������ѧ���ļ���
        if (students[i].StuMajor == Major){
            countt++;
            students_scores[countt].GPAs =  calculateGPA(students[i].StuNum,sumxuefen);
            students_scores[countt].StuN = students[i].StuNum;
            state = 1;
        }
    }
    if (state == 0){
        std::cout << "û���ҵ���Ӧ��ѧ����" << std::endl;
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

    std::cout << "���" << "  " << "ѧ��" << "    " << "����" << "    " << "�༶"  << "     " << "����" << "   " << "����" << std::endl;
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
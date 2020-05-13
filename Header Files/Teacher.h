#include <string>
using namespace std;
#pragma once

class Teacher
{
    private:
    string f_name;
    string l_name;

    int age;
    int phone_num;

    string address;
    string city;

    public:
    Teacher();

    Teacher(string f_name, string l_name, int age, int phone_num, string address, string city);

    ~Teacher();
    
    void get_iD();

    void get_pos();

    void set_iD(string f_name, string l_name, int age, int phone_num);

    void set_pos(string address, string city);

    void GradeStudent();

    void SitInClass();

    string Get_Name();

    

};
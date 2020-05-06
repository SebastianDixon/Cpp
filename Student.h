#include <string>
using namespace std;
#pragma once

class Student
{
    private:
    string f_name;
    string l_name;

    int age;
    int phone_num;

    string address;
    string city;

    public:
    Student();

    Student(string f_name, string l_name, int age, int phone_num, string address, string city);

    ~Student();

    void get_iD();

    void get_pos();

    void set_iD(string f_name, string l_name, int age, int phone_num);

    void set_pos(string address, string city);

    void SitInClass();
};
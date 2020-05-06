#include <string>
using namespace std;
#pragma once

class Course
{
    private:
    string c_name;
    string student[3];
    string teacher;

    public:
    Course();

    Course(string c_name);

    ~Course();

    void add_course(string c_name);

    void add_student(string student[]);

    void add_teacher(string T);

    string get_name();

};
#include <iostream>
#include <string>
#include "Course.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

//Course

Course::Course(){}
Course::Course(string c_name){}
Course::~Course(){}

void Course::add_course(string c_name)
{   
    cout << "Course name: " << c_name << endl;
    this->c_name = c_name;
}
void Course::add_student(string *student)
{
    *this->student = *student;
}
void Course::add_teacher(string T)
{
    this->teacher = T;
}

string Course::get_name()
{
    cout << c_name << endl;
    return c_name;
}


//Student

Student::Student(){}
Student::Student(string f_name, string l_name, int age, int phone_num, string address, string city){}
Student::~Student(){}

void Student::get_iD()
{
    cout << f_name << l_name << age << phone_num << endl;
}
void Student::get_pos()
{
    cout << address << city << endl;
}
void Student::set_iD(string f_name, string l_name, int age, int phone_num)
{
    this->f_name = f_name;
    this->l_name = l_name;
    this->age = age;
    this->phone_num = phone_num;
}
void Student::set_pos(string address, string city)
{
    this->address = address;
    this->city = city;
}
void Student::SitInClass()
{
    cout << "Sitting in main theater" << endl;
}

//Teacher

Teacher::Teacher(){}
Teacher::Teacher(std::string f_name, std::string l_name, int age, int phone_num, std::string address, std::string city){}
Teacher::~Teacher(){}
void Teacher::get_iD()
{
    cout << f_name << l_name << age << phone_num << endl;
}
void Teacher::get_pos()
{
    cout << address << city << endl;
}
void Teacher::set_iD(std::string f_name, std::string l_name, int age, int phone_num)
{
    this->f_name = f_name;
    this->l_name = l_name;
    this->age = age;
    this->phone_num = phone_num;
}
void Teacher::set_pos(std::string address, std::string city)
{
    this->address = address;
    this->city = city;
}
void Teacher::GradeStudent()
{
    cout << "Student graded" << endl;
}
void Teacher::SitInClass()
{
    cout << "Sitting at front of class" << endl;
}

string Teacher::Get_Name()
{
    return f_name;
}



//classes application
//Teacher::Teacher(std::string f_name, std::string l_name, int age, int phone_num, std::string address, std::string city){}



int main()
{

    Student Stud1;

    Student * Student1 = new Student{"Fred", "Smith", 18, 999, "LongStreet", "London"};
    Student * Student2 = new Student{"Bob", "Smith", 19, 998, "LongStreet", "London"};
    Student * Student3 = new Student{"Rick", "Smith", 20, 997, "LongStreet", "London"};

    Course * C1 = new Course("Intermediate C++");

    string Students[3] = {"Fred", "Bob", "Rick"};

    C1->add_student(Students);

    Teacher * T1 = new Teacher("Ricky", "Gervais", 50, 100, "RoundSquare", "Reading");

    C1->add_teacher(T1->Get_Name());

    cout << "Course name: " << C1->get_name() << endl;

    delete Student1;
    delete Student2;
    delete Student3;
    delete C1;
    delete T1;


    return 0;
}

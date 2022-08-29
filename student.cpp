#include <iostream>
#include "course.cpp"

using namespace std;

class Student
{
public:
    vector<Course> courses;
    void AddCourse(Course c);
};

void Student::AddCourse(Course c)
{
    courses.push_back(c);
}
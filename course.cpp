#include <iostream>
#include <vector>

using namespace std;

class Course
{
public:
    string cno;
    int classno;
    string cname;
    string teacher;
    class CourseTime
    {
    public:
        vector<int> week;
        vector<int> day;
        vector<int> lesson;
    } time;
};

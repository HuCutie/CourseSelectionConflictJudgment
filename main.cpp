#include <iostream>
#include <algorithm>
#include "student.cpp"

using namespace std;

bool isIntersected(vector<int> v1, vector<int> v2)
{
    vector<int> v;
	sort(v1.begin(),v1.end());   
	sort(v2.begin(),v2.end());   
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v));

    return !v.empty();
}

bool isConflictive(Student s, Course c)
{
    for(vector<Course>::iterator course = s.courses.begin(); course != s.courses.end(); course++)
    {
        if(isIntersected(c.time.week, (*course).time.week) 
        && isIntersected(c.time.day, (*course).time.day) 
        && isIntersected(c.time.lesson, (*course).time.lesson))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Course c1, c2, c3, c4;
    Student s;
    s.AddCourse(c1);
    s.AddCourse(c2);
    s.AddCourse(c3);

    cout << isConflictive(s, c4) << endl;

    return 0;
}
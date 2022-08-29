#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <fstream>
#include <istream>
#include <sstream>
#include <streambuf>
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

vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if("" == str) return res;
	char * strs = new char[str.length() + 1];
	strcpy(strs, str.c_str()); 
 
	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());
 
	char * p = strtok(strs, d);
	while(p) {
		string s = p;
		res.push_back(s);
		p = strtok(NULL, d);
	}
 
	return res;
}

void InitCourse(string line_data)
{
    vector<Course> courses;
    // cout << line_data << endl;
    vector<string> str = split(line_data, ",");
    // for(vector<string>::iterator str = line_data.begin(); str != line_data.end(); str++)
    // {
        // string weeks = str[0];
        // cout << weeks << endl;
        // string days = str[1];
        // cout << days << endl;
        // string lessons = str[2];
        // cout << lessons << endl;
    // }

    // return courses;
}

void ReadCsv()
{
    ifstream csv_data("data.csv", ios::in);
    if (!csv_data.is_open())
	{
		cout << "Error: opening file fail" << endl;
		exit(1);
	}

    vector<string> words;
	string word;
    string line;

	getline(csv_data, line);
	istringstream sin;
    vector<Course> courses;
	while (getline(csv_data, line))
	{
		words.clear();
		sin.clear();
		sin.str(line);
		while (getline(sin, word))
		{
			cout << word << endl;
            word.erase(remove(word.begin(), word.end(), '"'), word.end());
			words.push_back(word);
            InitCourse(word);
		}
    }
	csv_data.close();
}

int main()
{
    ReadCsv();

    Course c1, c2, c3, c4;
    Student s;

    c1.time.week = {6, 7, 8};
    c1.time.day = {1};
    c1.time.lesson = {1, 2, 3, 4};

    c2.time.week = {6, 7, 8};
    c2.time.day = {1};
    c2.time.lesson = {1, 2, 3, 4};

    c3.time.week = {6, 7, 8};
    c3.time.day = {1};
    c3.time.lesson = {1, 2, 3, 4};

    s.AddCourse(c1);
    s.AddCourse(c2);

    cout << isConflictive(s, c3) << endl;

    return 0;
}
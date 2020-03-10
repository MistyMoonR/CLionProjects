//
// Created by moon misty on 2019-08-21.
//
#include <iostream>
#include <iomanip> // parameterized stream manipulators 参数化流操纵器
#include "GradeBook.h"
using namespace std;

// constructor initializes courseName with string supplied as argument (constructor使用作为参数提供的字符串初始化courseName)
GradeBook::GradeBook(std::string name)
{
    setCourseName( name ); //validate and store courseName 验证并存储courseName
}

// function to set the course name;
// ensures that the course name has at most 25 characters
void GradeBook::setCourseName(std::string name)
{
    if ( name.size() <= 25 )
        courseName = name; //store and course name in the object
    else
    {
        courseName = name.substr(0,25); //select first 25 characters
        cerr << "Name\"" << name << "\" exceeds maximum length (25).\n"
          << "Limiting courseName to first 25 characters.\n" <<endl;
    }
}

//function to retrieve the course name
string GradeBook::getCourseName() const
{
    return courseName;
}

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
    cout << "welcome to the grade book for\n" << getCourseName() <<"!\n"
     <<endl;
}

//determine class average based on 10 grades entered by user
void GradeBook::determineClassAverage() const
{
    //initialization phase 初始化阶段
    int total = 0; //sum of grades entered by user
    unsigned int gradeCounter = 1; // unsigned int 从1开始，非负值

    //processing phase
    //prompt for input and read grade from user
    cout << "Enter grade or -1 to quit: ";
    int grade = 0;
    cin >> grade;

    //loop until sentinel value read from user
    while ( grade != -1 )
    {
        total = total + grade;
        gradeCounter = gradeCounter + 1;

        //prompt for input and read next grade from user
        cout << "Enter grade or -1 to quit: ";
        cin >> grade;
    }

    //termination phase 终止阶段
    if ( gradeCounter != 0 ) // if user entered at least one grade...
    {
        //
        double average = static_cast< double >(total) / gradeCounter; //ok to mix declaration and calculation 可以混合声明和计算

        //display total and average(with two digits of precision) 显示总计和平均值（精度为两位数）
        cout << "\nTotal of all " << gradeCounter - 1 << " grades entered is "
           << total <<endl;
        cout << setprecision(2) <<fixed; // 对average 四舍五入输出，小数点后两位
        cout << "Class average is " << average << endl;
    }
    else //no grade were entered, so output appropriate message
        cout << "No grades were entered" << endl;
}
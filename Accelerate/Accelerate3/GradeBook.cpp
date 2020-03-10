//
// Created by moon misty on 2019-08-22.
//
#include <iostream>
#include "GradeBook.h"
using namespace std;

// constructor initializes courseName with string supplied as argument
// initializes counter data members to 0 将计数器数据成员初始化为0
GradeBook::GradeBook(string name)
  : aCount( 0 ),
    bCount( 0 ),
    cCount( 0 ),
    dCount( 0 ),
    fCount( 0 ) //初始化为0
{
    setCourseName( name );
}

// function to set the course name; limits name to 25 or fewer character
void GradeBook::setCourseName(std::string name)
{
    if ( name.size() <=25 )
        courseName = name;
    else
    {
        courseName = name.substr( 0, 25 );
        cerr << "Name \"" << name << "\" exceeds maximum length (25).\n"
        << "Limiting courseName to first 25 characters.\n" << endl;
    }
}

//function to retrieve the course name 检索课程名称的功能
string GradeBook::getCourseName() const
{
    return courseName;
}

//display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
    //
    //
    cout << "Welcome to the grade book for\n" << getCourseName() << "!\n"
    << endl;
}

//input arbitrary number of grades from user; update grade conter
void GradeBook::inputGrades()
{
    int grade;

    cout << "Enter the letter grades." << endl
    << "Enter the EOF character to end input." << endl;

    //loop until user types end-of-file key sequence
    while ( (grade = cin.get())!= EOF)  //组合键 command + D 退出
    {
        //determine which grade was enter
        switch (grade)
        {
            case 'A':
            case 'a':
                ++aCount;
                break;

            case 'B':
            case 'b':
                ++bCount;
                break;

            case 'C':
            case 'c':
                ++cCount;
                break;

            case 'D':
            case 'd':
                ++dCount;
                break;

            case 'F':
            case 'f':
                ++fCount;
                break;

            case '\n': //ignore newlines
            case '\t': //tabs
            case ' ': // and space in input
                break;

            default: //catch all other characters
                cout << "Incorrect letter grade entered."
                << " Enter a new grade." << endl;
                break;
        } //end switch
    } //end while
} //end function inputGrade

//display a report based on the grade entered by user
void GradeBook::displayGradeReport() const
{
    //output summary of results
    cout << "\n\nNumber of students who received each letter grade:"
    << "\nA: " << aCount
    << "\nB: " << bCount
    << "\nC: " << cCount
    << "\nD: " << dCount
    << "\nF: " << fCount
    << endl;
} //end function displayGradeReport


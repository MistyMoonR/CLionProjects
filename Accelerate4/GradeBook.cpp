//
// Created by moon misty on 2019-08-23.
//
#include <iostream>
using namespace std;

#include "GradeBook.h"

//
//initializes
GradeBook::GradeBook(std::string name)
    : maximumGrade ( 0 ) // this value will be replaced by the maximum grade
{
    setCourseName( name ); // validate and store courseName 验证和存储
}

//function to set the course name;
void GradeBook::setCourseName(std::string name)
{
    if (name.size() <= 25 )
        courseName = name;
    else
    {
        courseName = name.substr( 0 , 25 );
        cerr << "Name\"" << name << "\" exceeds maximum length(25).\n"
        << "Limiting courseName to first 25 characters.\n" << endl;
    }
}

//function to retrieve the course name 检索课程名称的功能
string GradeBook::getCourseName() const
{
    return courseName;
}

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
    //
    //
    cout << "Welcome to the grade book for\n" << getCourseName() << "!\n"
    <<endl;
}

// input three grades from user; determine maximum
void GradeBook::inputGrades()
{
    int grade1;
    int grade2;
    int grade3;

    cout << "Enter three integer grades:";
    cin >> grade1 >> grade2 >> grade3;

    //store maximum in member maximumGrade
    maximumGrade = maximum( grade1, grade2, grade3 );
} // end

// returns the maximum of its three integer parameters
int GradeBook::maximum(int x, int y , int z) const
{
    int maximumValue = x;

    //
    if ( y > maximumValue )
        maximumValue = y;


    if ( z > maximumValue )
        maximumValue = z;

    return maximumValue;
}

//display a report based on the grades entered by user
void GradeBook::displayGradeReport() const
{
    //output
    cout << "Maximum of grades entered: " << maximumGrade << endl;
}

void function1()
{
    std::cout << "function 1" << std::endl;
}

void function2(void)
{
    std::cout << "function 2" << std::endl;
}
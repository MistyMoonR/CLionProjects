//
// Created by moon misty on 2019-08-28.
//
#include <iostream>
#include <iomanip>
#include "GradeBook.h"
using namespace std;



// constructor initializes courseName and grades array//构造函数初始化courseName和grade数组
GradeBook::GradeBook(const std::string &name, std::array<std::array<int,tests>, students> &gradesArray)
: courseName(name), grades(gradesArray)
{
}

// function to set the course name
//void GradeBook::setCourseName(const std::string &name)
//{
//    courseName = name;
//}

//function to retrieve the course name
string GradeBook::getCourseName() const
{
    return courseName;
}

//display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
    //this statement calls getCourseName to get the
    //name of the course this GradeBook represents
    cout << "Welcome to the grade book for\n" << getCourseName() << "!"
         << endl;
}

void GradeBook::outputGrades() const
{
    cout << "\nThe grades are:\n\n";
    cout << "               ";
    //output each student's grade
    for (size_t test = 0; test < tests; ++test)
        cout << "test" <<  test + 1 << "   " ;

    cout << "Average" << endl;
    for (size_t student = 0; student < grades.size(); ++student)
    {
        cout << "Student" << setw(2) << student + 1;
        for (size_t test = 0; test < grades[student].size(); ++test)
            cout << setw(8) << grades[student][test];
        double average = getAverage(grades[student]);
        cout << setw(11) << setprecision(2) << fixed << average << endl;
    }
}


//output bar chart displaying grade distribution
void GradeBook::outputBarChart() const
{
    cout << "\nOverall grade distribution: " << endl;

    //stores frequency of grades in each range of 10 grades
    const size_t frequencySize = 11;
    array<unsigned int, frequencySize> frequency = {};

    //for each grade, increment the appropriate frequency
    for (auto const &student:grades)
        for(auto const &test:student)
            ++frequency[test / 10];

    //for each grade frequency, print bar in chart
    for (size_t count = 0; count < frequencySize; ++count)
    {
        //output bar labels
        if (0 == count)
            cout << " 0-9: ";
        else if (10 == count)
            cout << " 100: ";
        else
            cout << count * 10 << "-" << (count * 10) + 9 << ":";

        //print bar of asterisks
        for (unsigned int stars = 0; stars < frequency[count]; ++stars)
            cout << '*';

        cout << endl;
    }
}


//find minimum grade
int GradeBook::getMinimum() const
{
    int lowGrade = 100; //assume

    //loop through grades array
    for (auto const &student:grades)
    {
        for (auto const &grade:student)
        {
            if (grade < lowGrade)
                lowGrade = grade;
        }
    }
    return lowGrade;
}

//find maximum grade
int GradeBook::getMaximum() const
{
    int highGrade = 0;

    //loop through grades array
    for (auto const &student:grades)
    {
        for (auto const &grade:student)
        {
            if (grade > highGrade)
                highGrade = grade;
        }
    }
    return highGrade;
}

//determine average grade for test
double GradeBook::getAverage(const std::array<int, tests>&setOfGrades) const
{
    int total = 0;

    //sum grade in array
    for (int grade:setOfGrades)
        total += grade;

    return static_cast<double >(total) / setOfGrades.size();
}

//perform various operation on the data//对数据执行各种操作
void GradeBook::processGrades() const
{
//    outputGrades();

    //call function getAverage to calculate the average grade
    cout << "\nLowest grade in the grade book is " << getMinimum()
         << "\nHighest grade in the grade book is " << getMaximum() << endl;

//    outputBarChart();
}












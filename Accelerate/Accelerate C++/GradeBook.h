//
// Created by moon misty on 2019-08-21.
#include <iostream>
#include <string> // class GradeBook uses C++ standard string class

//GradeBook class definition
class GradeBook
{
public:
    explicit GradeBook( std::string );
    void setCourseName( std::string );
    std::string getCourseName() const;
    void displayMessage() const;

private:
    std::string courseName; //course name for this GradeBook
};

#ifndef ACCELERATE_C___GRADEBOOK_H
#define ACCELERATE_C___GRADEBOOK_H

#endif //ACCELERATE_C___GRADEBOOK_H

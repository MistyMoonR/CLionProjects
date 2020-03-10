//
// Created by moon misty on 2019-08-21.
// Member function are defined in GradeBook.cpp
#include <string>

//GradeBook class definition
class GradeBook
{
public:
    explicit GradeBook( std::string ); //initializes course name
    void setCourseName( std::string ); // set the course name
    std::string getCourseName() const; // retrieve the course name
    void displayMessage() const; // display a welcome message
    void determineClassAverage() const; // averages user-entered grades
private:
    std::string courseName; // course name for this GradBook
};
//#ifndef ACCELERATE2_GRADEBOOK_H
//#define ACCELERATE2_GRADEBOOK_H
//
//#endif //ACCELERATE2_GRADEBOOK_H

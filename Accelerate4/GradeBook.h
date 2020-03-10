//
// Created by moon misty on 2019-08-23.
// Member functions are defined in GradeBook.cpp
#include <string>

//Definition
class GradeBook
{
public:
    explicit GradeBook( std::string );
    void setCourseName( std::string );
    std::string getCourseName() const;
    void displayMessage() const;
    void inputGrades();
    void displayGradeReport() const;
    int maximum(int, int, int) const;
private:
    std::string courseName;
    int maximumGrade;
}; //end


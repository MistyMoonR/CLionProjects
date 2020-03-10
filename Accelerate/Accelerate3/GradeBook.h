// Created by moon misty on 2019-08-22.
#ifndef ACCELERATE3_GRADEBOOK_H
#define ACCELERATE3_GRADEBOOK_H

#include <string>

//Definition
class GradeBook
{
public:
    explicit  GradeBook( std::string );
    void setCourseName( std::string );
    std::string getCourseName() const;
    void displayMessage() const;
    void inputGrades();
    void displayGradeReport() const;
private:
    std::string courseName; //course name for this GradeBook
    unsigned int aCount;
    unsigned int bCount;
    unsigned int cCount;
    unsigned int dCount;
    unsigned int fCount;
};


#endif //ACCELERATE3_GRADEBOOK_H

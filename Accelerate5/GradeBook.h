//
//
// Created by moon misty on 2019-08-28.
#include <string>
#include <array>

class GradeBook
{
public:
    // constant -- number of students who took the test
    static const size_t students = 10;
    static const size_t tests = 3;


    //constructor initializes course name and array of grades
    GradeBook(const std::string &,
            std::array<std::array<int,tests>, students> &);

//    void setCourseName(const std::string &);
    std::string getCourseName() const;
    void displayMessage() const;
    void processGrades() const;
    int getMinimum() const;
    int getMaximum() const;
    double getAverage(const std::array<int,tests>&) const;
    void outputBarChart() const;
    void outputGrades() const;
private:
    std::string courseName;
    std::array<std::array<int,tests>, students> grades;
};



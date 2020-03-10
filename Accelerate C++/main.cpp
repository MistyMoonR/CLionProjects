//
// Create and manipulate a GradeBook object with these functions.
#include <iostream>
#include "GradeBook.h" //include definition of class GradeBook
using namespace std;

//function main begins program execution
int main()
{
    // create two GradeBook objects
    GradeBook gradeBook1( "cse101");  //create a GradeBook object nemed mygGradeBook
    GradeBook gradeBook2( "cse102");

    //display initial value of courseName
    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
       << " \ngradeBook1 created for course: " << gradeBook2.getCourseName()
       <<endl;
} //end main

/*
int main()
{
    int number1 = 0;
    int number2 = 0;
    cout << "Enter two integers to compare:" << endl;
    cin >> number1 >> number2; //read two integers from user
    if( number1 == number2 )
        cout << number1 << " == " <<number2<<endl;

    if( number1 != number2 )
        cout << number1 << " != " <<number2<<endl;

    if( number1 < number2 )
        cout << number1 << " < " <<number2<<endl;

    if( number1 > number2 )
        cout << number1 << " > " <<number2<<endl;

    return 0;
}
 */

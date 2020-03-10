//main.cpp
//Create GradeBook object and invoke its determineClassAverage function
#include <iostream>
using namespace std;

int main()
{
    // initializing variables in declarations 初始化声明中的变量
    unsigned int passes = 0;
    unsigned int failures = 0;
    unsigned int studentCounter = 1;

    //process 10 students using counter-controlled loop
    while ( studentCounter <= 10 )
    {
        //prompt user for input and obtain value from user 提示用户输入并从用户获取值
        cout << "Enter result (1 = pass, 2 = fail):";
        int result = 0;
        cin >> result;

        // if...else nested in while
        if ( result == 1 )
            passes = passes + 1;
        else
            failures = failures + 1;

        //increment studentCounter so loop eventually terminates 使循环最终终止
        studentCounter = studentCounter + 1;
    }

    //termination phase: display number of passes and failures
    cout << "Passed " << passes << "\nFailed " << failures << endl;

    //
    if ( passes > 8 )
        cout << "Bonus to instructor " << endl;

}
//#include "GradeBook.h"
/*int main()
{
    // create GradeBook object myGradeBook and
    // pass course name to constructor
    GradeBook myGradeBook( "CS101 C++ Programming");

    myGradeBook.displayMessage();
    myGradeBook.determineClassAverage(); //find average of 10 grades
}
*/
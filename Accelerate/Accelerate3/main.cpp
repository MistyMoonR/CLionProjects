//
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include "GradeBook.h"
using namespace std;

int main()
{
    //creat GradeBook object
    GradeBook myGradeBook( "CS101 C++ Programming ");

    myGradeBook.displayMessage();
    myGradeBook.inputGrades();
    myGradeBook.displayGradeReport();
}

/*
int main()
{
    unsigned int counter = 1;
    do
    {
        cout << counter << " ";
        ++counter;
    } while (counter <= 10 );
    cout << endl;
}
*/
/*
int main()
{
    double amount;
    double principal = 1000.0;
    double rate = .05;

    //display
    cout << "Year" << setw( 21 ) << "Amount on deposit" << endl;

    //set floating-point number format
    cout << fixed << setprecision( 2 );

    // calculate amount on deposit for each of ten years 计算十年每年的存款金额
    for (unsigned int year = 1; year <= 10; ++year )
    {
        // calculate new amount for specified year
        amount = principal * pow( 1.0 +rate, year);

        //display
        cout << setw( 4 ) << year << setw( 21 ) << amount << endl;
    }

}
*/
/*
int main()
{
    for ( unsigned int counter = 1; counter <= 10; ++counter )
        cout << counter << " ";

    cout << endl;
}
*/
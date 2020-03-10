//
//
#include <iostream>
#include <iomanip>
using namespace std;

unsigned long factorial(unsigned long);

int main()
{
    // calculate the factorials of 0 through 10
    for (int counter = 0; counter <= 10; counter++ )
        cout << setw(2) << counter << "! = " << factorial( counter )
        << endl;
}

unsigned long factorial(unsigned long number)
{
    unsigned long result = 1;

    for (unsigned long i = number; i >= 1; i-- )
        result *= i;
    return result;
}

/*
unsigned long fibonacci(unsigned long);

int main()
{
    // calculate the fibonacci values of 0 through 10
    for ( int counter = 0; counter <= 10 ; counter++)
        cout << "fibonacci( " << counter << " ) = "
        << fibonacci( counter ) << endl;

    // display higher fibonacci values
    cout << "fibonacci( 20 ) = " << fibonacci( 20 ) << endl;
    cout << "fibonacci( 30 ) = " << fibonacci( 30 ) << endl;
    cout << "fibonacci( 35 ) = " << fibonacci( 35 ) << endl;
}

// recursive function fibonacci
unsigned long fibonacci(unsigned long number)
{
    if ((number == 0) || (number == 1))
        return number;
    else
        return fibonacci( number - 1 ) + fibonacci( number - 2 );
}
*/
/*
unsigned long factorial(unsigned long); // function prototype 功能原型

int main()
{
    // calculate the factorials of 0 through 10
    for ( int counter = 0; counter <= 10; counter++)
        cout << setw( 2 ) << counter << " ! = " << factorial( counter )
        << endl;
}

// recursive definition of function factorial
unsigned long factorial(unsigned long number)
{
    if (number <= 1) //test for base case
        return 1; // base cases: 0! and 1! = 1
    else
        return number*factorial(number - 1 );
}
*/
/*
int main()
{
    // demo
    int int1, int2, int3;

    cout << " Input three integer values: ";
    cin >> int1 >> int2 >> int3;

    // invoke int version of maximum//调用最大的int版本
    cout << " The maximum integer values is: "
    << maximum( int1, int2, int3);

    double double1, double2, double3;

    cout << " \n\nInput three integer values: ";
    cin >> double1 >> double2 >> double3;

    cout << " The maximum integer values is: "
         << maximum( double1, double2, double3);

    char char1, char2, char3;

    cout << " \n\nInput three integer values: ";
    cin >> char1 >> char2 >> char3;

    cout << " The maximum integer values is: "
         << maximum( char1, char2, char3);
}
*/
/*
int square( int x )
{
    cout << " integer " << x << " is ";
    return x * x;
}

double square( double y )
{
    cout << " double " << y << " is ";
    return y * y;
}

int main()
{
    cout << square( 7 );
    cout << endl;
    cout << square(7.5);
    cout << endl;
}
*/
/*
int number = 7; // global variable named number

int main()
{
    double number = 10.5; // local variable named number

    // display
    cout << "Local " << number << "\nGlobal " << ::number << endl;
}

*/
/*
// function prototype that specifies default arguments
unsigned int boxVolume(unsigned int length = 1, unsigned int width = 1,
        unsigned int height = 1);

int main()
{
    // no arguments--use default values for all dimensions
    cout << "The default box volume is: " << boxVolume();

    // specify length; default width and height
    cout << "\n\nThe volume of a box with length 10,\n"
    << "width 1 and height 1 is: " << boxVolume( 10 );

    cout << "\n\nThe volume of a box with length 10,\n"
         << "width 5 and height 1 is: " << boxVolume( 10 , 5);

    cout << "\n\nThe volume of a box with length 10,\n"
         << "width 1 and height 1 is: " << boxVolume( 10, 5, 2 )
        << endl;
}

// function boxVolume calculate the volume of a box
unsigned int boxVolume(unsigned int length, unsigned int width,
        unsigned int height )
{
    return length * width * height;
}
*/
/*
int squareByValue( int ); //function prototype(value pass)
void squareByReference (int & ); //function prototype(reference pass)

int main()
{
    int x = 2;
    int z = 4;

    // demonstrate squareByValue
    cout << "x= " << x << " before squareByValue\n";
    cout << "Value returned by squareByValue: "
    << squareByValue( x ) << endl;
    cout << "x=" << x << " after squareByValue\n" << endl;

    // demonstrate squareByReference
    cout << "z = " << z << " before squareByReference" << endl;
    squareByReference( z );
    cout << "z = " << z << " after squareByReference" << endl;
}

// squareByValue multiplies number by itself, stores the//squareByValue自身乘以数字，存储
// result in number and returns the new value of number//结果编号并返回number的新值
int squareByValue ( int number )
{
    return number *= number; // caller's argument not modified
}

// squareByReference multiplies numberRef by itself and stores the result// squareByReference将numberRef与其自身相乘并存储结果
// in the variable to which numberRef refers in function main//在函数main中numberRef引用的变量中
void squareByReference( int &numberRef )
{
    numberRef *= numberRef;
}
*/
/*
// definition of inline function cube. definition of function appears//内联函数多维数据集的定义。出现功能定义
// before function is called, so a function prototype is not required.//在调用函数之前，因此不需要函数原型。
// first line of function definition acts as the prototype.//函数定义的第一行充当原型。
inline double cube( const double side )
{
    return side * side * side;
}

int main()
{
    double sideValue;
    cout << "Enter the side length of your cube; ";
    cin >> sideValue;

    // calculate cube of sideValue and display result
    cout << "Volume of cube with side "
    << sideValue << " is " << cube(sideValue) << endl;
}
*/
/*
void function1();
void function2( void );

int main()
{
    function1();
    function2();
}
*/
/*
int square( int );

int main()
{
    int a = 10; // value to square (local automatic variable in main)

    cout << a << " squared: " << square( a ) << endl; // display a squared
}

// returns the square of an integer
int square( int x ) // x is a local variable
{
    return x * x; //calculate square and return result
}
*/
/*
void useLocal(); //function prototype 功能原型
void useStaticLocal();
void useGlobal();

int x = 1;

int main()
{
    cout << "global x in main is " << x << endl;

    int x = 5; // local variable to main 局部变量为main

    cout << " local x in main's outer scope is " << x << endl;

    { // start new scope 开始新的范围
        int x = 7; // hides both x in outer scope and global x

        cout << " local x in main's inner scope is " << x << endl;
    }

    cout << "local x in main's outer scope is " << x << endl;

    useLocal();
    useStaticLocal();
    useGlobal();
    useLocal();
    useStaticLocal();
    useGlobal();

    cout << "\nlocal x in main is " << x << endl;
} //end main

// useLocal reinitializes local variable x during each  all useLocal在每个all中重新初始化局部变量x
void useLocal()
{
    int x = 25; // initialized each time useLocal is called 每次调用useLocal时都会初始化

    cout << "\nlocal x is " << x << " on entering useLocal" << endl;
    ++x;
    cout << "local x is " << x << " on exiting useLocal" << endl;
}

// useStaticLocal initializes static local variable x only the//useStaticLocal仅初始化静态局部变量x
// first time the function is called; value of x is saved//第一次调用函数; x的值被保存
// between calls to this function//在调用此函数之间
void useStaticLocal()
{
    static int x = 50; // initialized first time useStaticLocal is called

    cout << "\nlocal static x is " << x << " on entering useStaticLocal"
    << endl;
    ++x;
    cout << "local static x is " << x << " on exiting useStaticLocal"
    << endl;
}

// useGlobal modifies global variable x during each call
void useGlobal()
{
    cout << "\nglobal x is " << x << " on entering useGlobal" << endl;
    x *= 10;
    cout << "global x is " << x << " on exiting useGlobal" << endl;
}
*/
#include <cstdlib> //contains function prototype for rand
#include <random>
#include <iomanip>
#include <ctime>
#include <cmath>
#include "GradeBook.h"
#include "maximum.h"
/*
int main()
{
    //use the default random-number generation engine to  使用默认的随机数生成引擎
    //produce uniformly distributed pseudorandom int values from 1 to 6 生成从1到6的均匀分布的伪随机int值
    default_random_engine engine(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> randomInt( 1, 6 );

    //loop 10 times
    for (unsigned int counter = 1; counter <= 10; ++counter)
    {
        //pick random number from 1 to 6 and output it
        cout << setw( 10) << randomInt(engine);

        //if counter is divisible by 5, start a new line of output
        if (counter %5 == 0 )
            cout << endl;
    }
}
*/
/*
unsigned int rollDice();

int main()
{
    // enumeration with constants that represent the game status 使用表示游戏状态的常量进行枚举
    enum Status { CONTINUE, WON, LOST }; // all caps in constants 所有常量上限

    // randomize random number generator using current time 使用当前时间随机化随机数生成器
    srand(static_cast<unsigned int>( time( 0 )));

    unsigned int myPoint = 0; // point if no win or loss on first roll
    Status gameStatus = CONTINUE;
    unsigned int sumOfDice = rollDice(); //first roll of the dice

    // determine game status and point (if need) based on first roll
    switch ( sumOfDice )
    {
        case 7:
        case 11:
            gameStatus = WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sumOfDice;
            cout << "Point is " << myPoint << endl;
            break;
    }


// While game is not complete
    while ( CONTINUE == gameStatus )
    {
        sumOfDice = rollDice();

        // determine game status
        if ( sumOfDice == myPoint )
            gameStatus = WON;
        else
            if (sumOfDice == 7 )
                gameStatus = LOST;
    }

    //display
     if (WON == gameStatus )
        cout << "wins" << endl;
     else
         cout << "loses " << endl;
}

// roll dice, calculate sum and display results
unsigned int rollDice()
{
    //pick random die values
    unsigned int die1 = 1+ rand() % 6; //first die roll
    unsigned int die2 = 1+ rand() % 6; //second die roll

    unsigned int sum = die1 + die2;

    //display
    cout << "Player rolled " << die1 << " + " << die2
    << " = " << sum << endl;
    return sum;
}
*/
/*
int main()
{
    unsigned int seed = 0;

    cout << "Enter seed: ";
    cin >> seed;
    srand( seed ); //seed random number generator

    // loop 10 times
    for (unsigned int counter = 1; counter <= 10; ++ counter)
    {
        //pick random number from 1 to 6 and output it
        cout << setw( 10 ) << ( 1 + rand() % 6 );

        if ( counter % 5 == 0 )
            cout << endl;
    }

}
*/
/*
int main()
{
    //loop 20 times
    for (unsigned int counter = 1; counter <= 20; ++counter )
    {
        // pick random number from 1 to 6 and output it
        cout << setw( 10 ) << ( 1 + rand() % 6 );

        //if counter is divisible by 5, start a new line for output
        if ( counter % 5 == 0 )
            cout << endl;
    }
}
*/
/*int main()
{
    unsigned int frequency1 = 0;
    unsigned int frequency2 = 0;
    unsigned int frequency3 = 0;
    unsigned int frequency4 = 0;
    unsigned int frequency5 = 0;
    unsigned int frequency6 = 0;

    // summarize results of 6000000 rolls of a die
    for ( unsigned int roll = 1; roll <= 6000000; ++roll )
    {
        unsigned int face = 1 + rand() % 6; //random number from 1 to 6
        // determine roll value 1-6 and increment appropriate counter
        switch( face )
        {
            case 1:
                ++frequency1;
                break;
            case 2:
                ++frequency2;
                break;
            case 3:
                ++frequency3;
                break;
            case 4:
                ++frequency4;
                break;
            case 5:
                ++frequency5;
                break;
            case 6:
                ++frequency6;
                break;
            default: // invalid value 无效值
                cout << "Program should never get here!";

        }
    }

    cout << "Face " << setw( 13 ) << "Frequencey" << endl; //output headers
    cout << "  1" << setw( 13 ) << frequency1
            << "\n  2" << setw( 13 ) << frequency2
            << "\n  3" << setw( 13 ) << frequency3
            << "\n  4" << setw( 13 ) << frequency4
            << "\n  5" << setw( 13 ) << frequency5
            << "\n  6" << setw( 13 ) << frequency6 << endl;

}
*/
/*
#include "GradeBook.h"

int main()
{
    // create gradeBook object
    GradeBook myGradeBook( "CS101 C++ Programming" );

    myGradeBook.displayMessage();
    myGradeBook.inputGrades();
    myGradeBook.displayGradeReport();
}
*/
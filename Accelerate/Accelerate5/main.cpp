//
//8.28.4
#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "GradeBook.h"
using namespace std;


void outputVector(const vector<int> &);

void inputVector(vector<int> &);

int main()
{
    vector<int> integers1(7);
    vector<int> integers2(10);
    //print integers1 size and contents
    cout << "Size of vector integers1 is " << integers1.size()
         << "\nvector after initialization: " << endl;
    outputVector(integers1);

    //print integers2 size and contents
    cout << "size of vector integers2 is " << integers2.size()
         << "\nvector after initialization: " << endl;
    outputVector(integers2);

    //input and print integers1 and integers2
    cout << "\nEnter 17 integers: " << endl;
    inputVector(integers1);
    inputVector(integers2);

    cout << "\nAfter input, the vectors contain:\n"
         << "integers1: " << endl;
    outputVector(integers1);
    cout << "integers2: " << endl;
    outputVector(integers2);

    //use inequality(!=) operator with vector objects
    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integers1 != integers2)
        cout << "integers1 and integers2 are not equal" << endl;

    //create vector integers3 using integers1 as an
    //initializer: print size and contents
    vector<int> integers3(integers1);  // copy constructor

    cout << "\nSize of vector integers3 is " << integers3.size()
         << "\nvector after initialization:" << endl;
    outputVector(integers3);

    //use overloaded assignment (=) operator
    cout << "\nAssigning integers2 to integers1: " << endl;
    integers1 = integers2;

    cout << "integers1: " << endl;
    outputVector(integers1);
    cout << "integers2: " << endl;
    outputVector(integers2);

    // use equality (==) operator with vector objects
    cout << "\nintegers1[5] is " << integers1[5];

    //use square brackets to create lvalue
    cout << "\n\nAssigning 1000 to integers1[5]" << endl;
    integers1[5] = 1000;
    cout << "integers1:" << endl;
    outputVector(integers1);

    //attempt to use out-of-range subscript
    try
    {
        cout << "\nAttempt to display integers1.at(15)" << endl;
        cout << integers1.at(15) << endl; //ERROR: out of range
    }
    catch (out_of_range &ex)
    {
        cerr << "An exception occurred: " << ex.what() << endl;
    }

    //changing the size of a vector
    cout << "\nCurrent integers3 size is: " << integers3.size() << endl;
    integers3.push_back(1000); //add 1000 to the end of the vector
    cout << "\nCurrent integers3 size is: " << integers3.size() << endl;
    cout << "integers3 now contains: ";
    outputVector(integers3);
}

//output vector contents
void outputVector(const vector<int> &array)
{
    for(int item : array)
        cout << item << " ";
    cout << endl;
}

//input vector contents
void inputVector(vector<int> &array)
{
    for (int &item : array)
        cin >> item;
}
/*
int main()
{
    array<array<int, GradeBook::tests>, GradeBook::students> grades =
            {
                    87, 69, 70,
                    78, 87, 90,
                    94, 100, 90,
                    100, 81, 82,
                    83, 65, 86,
                    78, 87, 65,
                    85, 75, 83,
                    91, 94, 100,
                    76, 72, 84,
                    87, 93, 73
            };
    GradeBook myGradeBook("CS101 Introduction to C++ Programming", grades);
    myGradeBook.displayMessage();
    myGradeBook.outputGrades();
    myGradeBook.processGrades();
    myGradeBook.outputBarChart();

}
*/


/*
const size_t rows = 3; //行
const size_t columns = 2; //列

void printArray(const array<array<int, columns>, rows> &);

int main()
{
    array<array<int, columns>, rows> array1 = {1, 2, 3, 4, 5, 6,};
    array<array<int, columns>, rows> array2 = {1, 2, 3, 4, 5};

    cout << "Values in arrays1 by row are:" << endl;
    printArray(array1);

    cout << "\nValues in arrays2 by row are:" << endl;
    printArray(array2);
}


void printArray(const array<array<int, columns>, rows> &a)
{
    for (auto const &row:a)
    {
        for (auto const &element:row)
            cout << element << ' ';

        cout << endl;
    }
}
*/
/*
int main()
{
    const size_t arraySize = 7;//size of array colors
    array<string, arraySize> colors = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};
    //output original array
    cout << "Unsorted array:\n"; //未排序的数组
    for (string color:colors)
        cout << color << " ";

    sort(colors.begin(), colors.end());//sort contents of colors//颜色的排序内容

    //output sorted array
    cout << "\nSorted array:\n";
    for (string item:colors)
        cout << item << " ";

    //search for "indigo" in colors 靛蓝
    bool found = binary_search(colors.begin(), colors.end(), "indigo");
    cout << "\n\n'indigo' " << (found ? "was" : "was not") << " found in colors" << endl;

    //search for "cyan" in colors 青色
    found = binary_search(colors.begin(), colors.end(), "cyan");
    cout << "\n\n'cyan' " << (found ? "was" : "was not") << " found in colors" << endl;
}
*/
/*
int main()
{
    //array of student grades
    const array<int, GradeBook::student> grades =
            {87, 68, 94, 100, 83, 78, 85,
             91, 76, 87};
    string courseName = "CS101 Introduction to C++ Programming";

    GradeBook myGradeBook(courseName, grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
    myGradeBook.setCourseName();
}*/
/*
int main()
{
    array<int, 5> items = {1, 2, 3, 4, 5,};
    //display
    cout << "items before modification: ";
    for (int item:items)
        cout << item << " ";

    //multiply the elements of items by 2
    for (int &itemRef:items)
        itemRef *= 2;

    //display items after modification
    cout << "\nitems after modification: ";
    for (int item:items) {
        cout << item << " ";
    }
    cout << endl;
}
 */
/*
int main()
{
    cout<<"First call to each function:\n ";
    staticArrayInit();
    automaticArrayInit();

    cout << "\n\nSecond call to each function:\n";
    staticArrayInit();
    automaticArrayInit();
    cout << endl;
}
*/
/*
int main()
{
    //define array sizes
    const size_t responseSize = 20;
    const size_t frequencySize = 6;
    //place survey responses in array responses
    const array<unsigned int, responseSize> responses =
            {1, 2, 5, 4, 3, 5, 2, 1, 3, 1, 3, 4, 4, 4, 2, 4, 4, 2, 2, 5};
    // initialize frequency counters to 0
    array<unsigned int, frequencySize> frequency = {};

    //for each answer, select responses element and use that value
    //as frequency subscript to determine element to increment
    for (size_t answer = 0; answer < responses.size(); ++answer) {
        ++frequency[responses[answer]];
    }
    cout << "Rating" << setw(17) << "Frequency" << endl;

    //output each array element's value
    for (size_t rating = 1; rating < frequency.size(); ++rating) {
        cout << setw(6) << rating << setw(17) << frequency[rating] << endl;
    }
}
*/
/*
int main()
{
    //use the default random-number generation engine to//使用默认的随机数生成引擎
    //produce uniformly distributed pseudorandom int values from 1 to 6//生成从1到6的均匀分布的伪随机int值
    default_random_engine engine(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> randomInt(1, 6);

    const size_t arraySize = 7;
    array<unsigned int, arraySize> frequencey = {};

    // roll die 6000000 times; use die value as frequency index
    for (unsigned int roll = 1; roll <= 6000000; ++roll)
        ++frequencey[randomInt(engine)];

    cout << "Face" << setw(13) << "Frequency" << endl;

    //output each array element's value
    for (size_t face = 1; face < frequencey.size(); ++face) {
        cout << setw(4) << face << setw(13) << frequencey[face] << endl;
    }
}
 */
/*
int main()
{
    const size_t arraySize = 11;
    array< unsigned int, arraySize > n =
            {0,0,0,0,0,0,1,2,4,2,1};

    cout << "Grade distribution:" << endl;

    //for each element of array n, output a bar of the chart
    for ( size_t i = 0; i < n.size(); ++i )
    {
        //output bar labels ("0-9;"...
        if ( 0 == i)
            cout << "  0-9: ";
        else if( 10 == i)
            cout << "  100: ";
        else
            cout << i * 10 << "-" << (i * 10 ) + 9 << ": ";

        //print bar of asterisks
        for (unsigned int stars = 0; stars < n[i]; ++stars)
            cout << '*';

        cout << endl;
    }
}
*/
/*
int main()
{
//    array< int, 5 > n = { 32, 27, 64, 18, 95 }; // n is an array of 5 int values//n是一个包含5个int值的数组
    const size_t arraySize = 5; //must initialize in declaration//必须在声明中初始化

    array< int , arraySize > s{}; //array s has 5 element

    for(size_t i = 0; i < s.size(); ++i )
        s[i] = 2 + 2 * i;
    // initialize elements of array n to 0//将数组n的元素初始化为0
//    for (size_t i = 0; i < n.size(); ++i )
//        n[ i ] = 0; // set element at location i to 0// set element at location i to 0

        cout << "Element" << setw( 13) << "Value" << endl;

        // output each array element's value
        for ( size_t j = 0; j < s.size(); ++j )
            cout << setw( 7 ) << j << setw( 13 ) << s[j] << endl;
}
 */
#include <iostream>
using namespace std;
#include <string>
//string current_chapter = "Getting Started";
#include <fstream>
#include <vector>
//vector<string> chapter_titles(20);

//void read() { cout<<"read()\n";}
//void sort() { cout<<"s()\n";}
//void compact() { cout<<"c()\n";}
//void write() { cout<<"w()\n";}
//
//int read(){
//    read == 1;
//}
//
//int main()
//{
//    int count = read();
//    if(count > 1){
//        sort();
//        compact();
//    }
//    if (count == 0)
//        cout<< "no sales for this month\n";
//    else write();
//    return 0;
//}
//
//int main()
//{
//    int iterations = 0;
//    bool continue_loop = true;
//    while (continue_loop != false)
//    {
//        iterations++;
//
//        cout <<"the while loop has executed"
//             <<iterations<<"times\n";
//        if (iterations == 5)
//            continue_loop = false;
//    }
//    return 0;
//}
 //bool 1.3

/*int main()
{
    ofstream outfile("out_file");
    ifstream infile("in_file");

    if (!infile){
        cerr << "error: unable to open input file!\n";
        return -1;
    }

    if (!outfile)
    {
        cerr << "sorry! we were unable to open the file!\n";
        return -2;
    }
    string word;
    while (infile>>word)
        outfile << word << ' ';

    return 0;


}
*/ //1.4

/*
int main()
{
    std::cout << "please input two integers:\n";
    int small = 0, big = 0;
    std::cin >> small >> big;

    if (small > big)
    {
        int tmp = small;
        small = big;
        big = tmp;
    }

    for (int i = small; i != big; ++i)
        std::cout << i << std::endl;

    return 0;
}
*/

int main()
{
    int sum = 0;
    for (int val; std::cin >> val; sum += val);
    std::cout << sum << std::endl;

    return 0;
}


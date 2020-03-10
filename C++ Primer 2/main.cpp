#include <iostream>

/*
int main() {
    std::cout << "Hello, World65555556666!" << std::endl;
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;




    return 0;
}
 */
/*
int fibon[9] = {0,1,2,3,4,8,6,7,8};
int main()
{
    std::cout<< fibon[5]<<std::endl;
    return 0;
}

int main()
{
    int ia[10];
    int index;

    for (index = 0; index < 10; ++index )
        ia [index] = index;

    for ( index = 9; index >= 0 ; --index)
        std::cout<<ia[index] <<" "<<std::endl;
    return 0;

}
*/
/*class IntArray{
public:
    bool operator == (const IntArray& ) const;
    bool operator != (const IntArray& ) const;
    IntArray& operator= (IntArray );
    int size() const;
    static void sort();

    int min() const;
    int max() const;

    int find( int value ) const;

private:
};
*/
/*
int main()
{
    int a = 10;
    std::cout<< &a << std::endl;
    return 0;
}


IntArray myArray0, myArray1;


class IntArray{
public:
    int size() const { return _size;}

private:
    int _size;
    int *ia;

};
*/
/*练习 2.5

C++类的关键特征是接口与实现的分离

接口是一些 用户可以应用到类对象上的操作 的集合
它由三部分构成 这些操作的名字 它们的返回值 以及它们的参数表 一般地 这
些就是该类用户所需要知道的全部内容
私有实现包括为支持公有接口所必需的算法和数据
理想情况下 即使类的接口增长了 它也不用变得与以前的版本不相兼容 另一方面 在
类的 生命周期内其实现可以自由演化 从下面选择一个抽象 指类 并为该类编写一个公共接口

(a) Matrix (b) Boolean (c) Person
(e) Pointer (d) Date (f) Point


Class Date
        {
        public:
            Date( int year, int mouth, int data):m_iyear(year),m_imouth(mouth),
            m_idata(data)
        {

        }
        void setData(int year,int month,int data);
            Date(const Date &date)
        {
                m_iyear = date.year;
                m_imonth = date.month;
                m_idata = date.data;
        }
        private:
            int m_iyear;
            int m_imonth;
            int m_idata;

        };
void Date::setData( int year, int month, int data)
{
    m_iyear = year;
    m_imouth = month;
    m_idata = data;
};
*/
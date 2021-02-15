#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const long long size=100;//修改size的数值以改变最终输出的大小

long long zhishu[size/2];
void work()
{//主要程序
    zhishu[1] = 2;
    long long k = 2;
    for(long long i=3;i<=size;i++)
    {//枚举每个数

        bool ok = 1;
        for (long long j = 1; j < k; j++)
        {
            //枚举已经得到的质数
            if (i % zhishu[j] == 0) {
                ok = !ok;
                break;
            }
        }
        if (ok) {

            zhishu[k] = i;
            cout << "count" << k << ' ' << i << endl;
            k++;
        }
}
}


int main() {

    freopen("zhishu.out", "w", stdout);
    cout << "count1 2" << endl;
    work();
    return 0;
}

bool isPrime(unsigned long n) {

    if (n <= 3)
    {
        return n > 1;
    }
    else if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    else
        {
        for (unsigned short i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
            {
                return false;
            }
        }
        return true;
    }
}
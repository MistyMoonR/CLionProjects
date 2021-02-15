#include <iostream>
#include<bits/stdc++.h>

using namespace std;
const int MAXN=10010;
string LCS(string str1,string str2)
{
    string fin=str1;
    int length1,length2;
    int arr[MAXN][MAXN];
    length1 = str1.length();
    length2 = str2.length();
    memset(arr,0,sizeof(arr));
    for (int i=1; i<=length1; i++)
        for (int j=1; j<=length2; j++)
        {
            if (str1[i-1] == str2[j-1])
                arr[i][j]=arr[i-1][j-1]+1;
            else
                arr[i][j]=(arr[i-1][j] > arr[i][j-1]?arr[i-1][j]:arr[i][j-1]);
        }
    string print="";
    for (int i=length1,j=length2; i>=1&&j>=1;)
    {
        if (str1[i-1] == str2[j-1])
        {
            print = str1[i-1]+print;
            fin.erase(i-1,1);//删除
            i--;
            j--;
        }
        else
        {
            if(arr[i][j -1] >= arr[i - 1][j])
                j--;
            else
                i--;
        }
    }
    if(fin.length()==1)//删到只剩最后一个
        return "0";
    return fin;//删除回文序列之后的序列
}

int main()
{
    int n;
    cin>>n;
    int a[MAXN];
    string s="";
    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
        s+=char(a[i]+int('0'));
    }
    if(n==1)
        cout<<"1"<<endl;
    else
    {
        string s1(s.rbegin(),s.rend());//逆序
        string ss=LCS(s,s1);
        int cnt=1;
        while(1)
        {
            ++cnt;
            if(ss=="0")
                break;
            string s2(ss.rbegin(),ss.rend());//更新字符串为删除后的
            ss=LCS(ss,s2);
        }
        cout<<cnt<<endl;
    }
}

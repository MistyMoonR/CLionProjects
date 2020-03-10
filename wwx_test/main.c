



//int main()

//{
//    int i,j;
//    scanf("%d%d",&i,&j);
//    printf("i=%d,j=%d\n",i,j);
//    return 0;
//}
//{
//    int i;
//    printf("请给 i 赋值");
//    scanf("%d",&i);
//    printf("i=%d\n",i);
//    return 0;
//}
//{
//    int n;
//    printf("输入一个数");
//    scanf("%d",&n);
//    printf("八进制:%o\n",n);
//    printf("十六进制：%x\n",n);
//    return  0;
//}
//
//{
//   int name[5];
//   printf("write your name");
//   scanf("%s",& name);
//   printf("your name is %s",name);
//   return 0;
//}
//int main()
//{
//    int x;
//    int c1,c2,c3;
//    c1 = x/100;
//    c2=x/10 %10;
//    c3=x %10;
//    printf("请输入一个三位数x=");
//    scanf("%d",&x);
//    printf("%d %d %d", c1,c2,c3);
//    return 0;
//}
//    int main() {
//    int x;
//    int c1;
//    c1 = x % 10;
//    scanf("%d", &x);
//    printf("位上的数字为%d", c1);
//    return 0;
//}
//int main()
//{
//    int x;
//    int c1 ,c2 , c3;
//    printf("请输入一个三位数：");
//    scanf("%d",&x);
//    c1=x/100;
//    c2=x/10%10;
//    c3=x %10;
//    printf("%d %d %d", c1,c2,c3);
//    return 0;
//}
//
//int main()
//{
//    long long a;
//    double b;
//    double c;
//    while(1)
//    {
//    printf("输入一个十二位数字：");
//    scanf("%||d",&a);
//    b=double(a/1000000);
//    c=double(a%1000000);
//    printf("% if/%if=%if\n", b,c,b/c);
//    }
//}


//#include<string.h>
//int main()
//{
//    char name[]={"123"},destin[20]={};
//    strncpy(destin,name,3);
//    printf("%s\n",destin);
//}
#include <stdio.h>
int main()
{
    int a;
    int b,c;
    printf("a=");
    scanf("%11d",&a);
    b=floor(a/1000000);
    c=a%1000000;
    printf("%11d\n",b/c);
    return 0;
}
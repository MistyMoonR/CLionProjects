#include <stdio.h>

/* Exercise 6.1 Metric Conversions*/

double metersToFeet(double meters);
double gramToPounds(double gram);
double cToF(double g);

int main() {
    int add;
    double result;
    scanf("%d", &add);
    for (int i = 0; i < add; i++) {
        double inp;
        char end;
        scanf("%lf %c", &inp, &end);
        if (end == 'c') {
            result = cToF(inp);
            printf("%.2f f\n", result);
        } else if (end == 'm') {
            result = metersToFeet(inp);
            printf("%.2f ft\n", result);
        } else {
            result = gramToPounds(inp);
            printf("%.2f lbs\n", result);
        }
    }
    return 0;

}

double metersToFeet(double meters) {
    return 3.2808 * meters;
}
double gramToPounds(double gram) {
    return 0.002205 * gram;
}
double cToF(double g) {
    return 32 + 1.8 * g;
}

/*Assignment 6.1 Smallest with Min*/

int findMin(int inp[20], int c);

int main() {
    int inp[20];
    int c;
    int resulet;

    scanf("%d", &c);
    for (int i = 0; i < c; ++i) {
        scanf("%d", &inp[i]);
    }
    resulet = findMin(inp,c);
    printf("%d\n", resulet);
    return 0;
};

int findMin(int inp[20], int c) {
    int min = inp[0];
    for (int i = 0; i < c; ++i) {
        if (min > inp[i]) {
            min = inp[i];
        }
    }
    return min;
}

/*Assignment 6.2 Count Fives*/

int countFives(int inp);

int main() {
    int add;
    int inp;
    int resulet = 0;
    scanf("%d", &add);
    for (int i = 0; i < add; ++i) {
        scanf("%d", &inp);
        resulet += countFives(inp);
    }
    printf("%d\n", resulet);
    return 0;
}

int countFives(int inp) {
    int count = 0;
    int plus;
    while (inp) {
        plus = inp % 10;
        if (plus == 5) {
            count++;
            inp /= 10;
        } else {
            inp /= 10;
        }
    }
    return count;
}

/*Exercise 6.2 Fibonacci Sequence*/
int fibo(int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    int result = fibo(n);
    printf("%d\n", result);
    return 0;
}

int fibo(int n) {
    if (n < 2) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

/*Assignment 6.3 Digit Sum*/

//int digitSum(int inp);
//
//int main() {
//    int inp;
//    int result;
//    scanf("%d", &inp);
//    printf("%d\n", digitSum(inp));
//    return 0;
//}
//
//int digitSum(int inp) {
//    int n;
//    if(inp) {
//        scanf("%d", &n);
//        return n + digitSum(inp - 1);
//    }
//    return 0;
//}

int digitSum(int inp);

int main()
{
    int inp;
    int sum;
    scanf("%d", &inp);
    sum = digitSum(inp);
    printf("%d\n", sum);
}

int digitSum(int inp)
{
    int a;
    int sum=0;
    a = inp % 10;
    if (inp / 10 == 0) {
        return inp;
    } else {
        sum = a + digitSum(inp / 10);
    }
    return sum;
}
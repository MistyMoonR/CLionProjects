#include <stdio.h>

//void printArray(int * ptr, int size);
//int main() {
//    //! showMemory(start=65520)
//    int arr[3] = {25, 50, 75};
//    printArray(arr, 3);
//
//    return 0;
//}
//void printArray(int * ptr, int size) {
//    int i;
//    for (i=0; i<size; i++) {
//        printf("%d ", *(ptr+i));
//        //printf("%d ", ptr[i]);
//    }
//}

//Exercise 8.1 Sum First Skeleton Code
//int sumFirst(int *arr, int n);
//int main() {
//    int arr[30];
//    int id = 0;
//    int inp, num;
//    scanf("%d", &inp);
//    while (inp != -1) {
//        arr[id] = inp;
//        id++;
//        scanf("%d", &inp);
//    }
//    scanf("%d", &num);
//    sumFirst(arr, num);
//}
//
//int sumFirst(int *arr, int n) {
//    int result = 0;
//    for (int i = 0; i < n; ++i) {
//        result += arr[i];
//    }
//    printf("%d\n", result);
//}

//Assignment 8.1 Reverse AB
//reverseAB(int *arr, int a, int b);
//printArray(int *arr, int num);
//
//int main() {
//    int array[8] = {0, 1, 2, 3, 4, 5, 6, 7};
//    reverseAB(array, 2, 5);
//    printArray(array, 8);
//    printf("\n");
//}
//
//reverseAB(int *arr, int a, int b) {
//    while (a < b) {
//        int tmp = arr[a];
//        arr[a] = arr[b];
//        arr[b] = tmp;
//        a++;
//        b--;
//    }
//}
//printArray(int *arr, int num) {
//    for (int i = 0; i < num; ++i) {
//        printf("%d ", arr[i]);
//    }
//}

//Assignment 8.2 All Appear
//allAppear(int *array1, int num1, int *array2, int num2);
//
//int main() {
//    int array1[5] = {1, 2, 3, 4, 5};
//    int array2[2] = {6, 1};
//    printf("%d\n", allAppear(array1, 5, array2, 2));
////    int array1[5] = {1, 2, 3, 4, 5};
////    int array2[3] = {2, 3, 5};
////    printf("%d\n", allAppear(array1, 5, array2, 3));
//}
//int allAppear(int * arr1, int size1, int * arr2, int size2) {
//    for (int i = 0; i < size2; i++) {
//        int add = 0;
//        for (int j = 0; j < size1; j++) {
//            if (arr2[i] == arr1[j]){
//                add = 1;
//            }
//        }
//        if (add == 0) {
//            return 0;
//        }
//    }
//    return 1;
//}

//Assignment 8.3 Longest Reverse

int longestReverse(int * arr,int size);
int main() {
//    int array[9] = {1, 2, 3, 4, 5, 3, 2, 1, 6};
//    printf("%d", longestReverse(array, 9));
//    int array[6] = {3, 1, 2, 2, 1, 4};
//    printf("%d\n", longestReverse(array, 6));
//    int array[6] = {0, 5, 5, 5, 0, 0};
//    printf("%d\n", longestReverse(array, 3));
    int array[3] = {5, 5, 5};
    printf("%d\n", longestReverse(array, 3));

}

int longestReverse(int * arr,int size)
{
    int a = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = size; j > 0; j--) {
            if  (arr[i] == arr[j]) {
                a = 1;
                while (arr[i + a] == arr[j - a]) {
                    a++;
                }
                return a;
            }
        }
    }
    return a;
}


//int nums[] = {5, 2, 10, -5, 12, -3, 16, 74, -4, 8};
//int *ptr1, *ptr2;
//int x;
//ptr1 = nums + 3;
//ptr2 = &ptr1[5];
//
//printf("%d\n", *(ptr1 + x));
//
//int nums[] = {5, 2, 10, -5, 12, -3, 16, 74, -4, 8};
//int *ptr1, *ptr2;
//int x;
//ptr1 = nums+3;
//ptr2 = &ptr1[5];
//printf("%d\n", *ptr1 + x);
//
//int nums[] = {5, 2, 10, -5, 12, -3, 16, 74, -4, 8};
//int *ptr1, *ptr2;
//int x;
//ptr1 = nums+3;
//ptr2 = &ptr1[5];
//printf("%d\n", *ptr2 - x);
//
//
//int nums[] = {5, 2, 10, -5, 12, -3, 16, 74, -4, 8};
//int *ptr1, *ptr2;
//int x;
//ptr1 = nums+3;
//ptr2 = &ptr1[5];
//printf("%d\n", *(ptr1 + x));
//
//int nums[] = {5, 2, 10, -5, 12, -3, 16, 74, -4, 8};
//int *ptr1, *ptr2;int x;
//ptr1 = nums+3;
//ptr2 = &ptr1[5];
//printf("%d\n", *(ptr1 + x));
//
//int nums[] = {5, 2, 10, -5, 12, -3, 16, 74, -4, 8};
//int *ptr1, *ptr2;int x;
//ptr1 = nums+3;
//ptr2 = &ptr1[5];
//printf("%d\n", *(ptr1 + x));
//
//int nums[] = {5, 2, 10, -5, 12, -3, 16, 74, -4, 8};
//int *ptr1, *ptr2;int x;
//ptr1 = nums+3;
//ptr2 = &ptr1[5];
//printf("%d\n", *(ptr2 - x));
//
//int nums[] = {5, 2, 10, -5, 12, -3, 16, 74, -4, 8};
//int *ptr1, *ptr2;
//int x;
//ptr1 = nums+3;
//ptr2 = &ptr1[5];
//printf("%d\n", *(ptr2 - x));
//
//int nums[] = {5, 2, 10, -5, 12, -3, 16, 74, -4, 8};
//int *ptr1, *ptr2;
//int x;
//ptr1 = nums+3;
//ptr2 = &ptr1[5];
//printf("%d\n", *(ptr2 - x));
//int main() {
//    int a = 10;
//    int *b = &a;
//
//    printf("%d\n", a);
//    printf("%d\n", &a);
//    printf("%p\n", a);
//    printf("%d\n", b);
//    printf("%d\n", *b);
//
//}



#include <stdio.h>
#include <stdlib.h>

//int main() {
//    //! showMemory(start=338, cursors=[a,b,c])
//    int *a, *b, *c;
//    a = (int *) malloc(sizeof(int));
//    *a = 1;
//    printf("I stored %d at memory location %p.\n", *a, a);
//    b = (int *) malloc(sizeof(int));
//    *b = 2;
//    free(a);
//    c = (int *) malloc(sizeof(int));
//    *c = 3;
//    printf("I stored %d at memory location %p.\n", *a, a);
//    return 0;
//
//}

//int main() {
//    //! showMemory(start=272)
//    int * array;
//    array = (int *) malloc(3 * sizeof(int));
//    array[0] = 5;
//    array[1] = 2;
//    array[2] = -1;
//    free(array);
//    return 0;
//}
//

// Exercise 10.1 Allocate Int Array Hints
//double compAverage(int *, int);
//int * allocateIntArr(int);
//
//int main() {
//    int num, i;
//    int *array;
//    double average;
//    scanf("%d", &num);
//    // write a call to the function allocateIntArr and store the address returned in pointer array
//    array = allocateIntArr(num);
//
//    for (i = 0; i < num; i++) {
//        scanf("%d", array + i);
//    }
//    printf("%.2f\n", compAverage(array, num));
//    // write the code to free the dynamic memory
//    free(array);
//    return 0;
//}
//// write the definition of the function allocateIntArr
//int * allocateIntArr(int num){
//    int *out;
//    out = (int *) malloc(num * sizeof(int));
//    return out;
//}
//
//double compAverage(int * array, int num){
//    int i;
//    double sum = 0.0;
//    for (i=0; i<num; i++) {
//        sum += array[i];
//    }
//    return sum / num;
//}

//Assignment 10.1 Allocate String
//char *allocateString(int);
//int main() {
//    int length;
//    char *str;
//
//    scanf("%d", &length);
//    str = allocateString(length);
//    scanf("%s", str);
//    printf("%s\n", str);
//    free(str);
//    return 0;
//}
//
//char *allocateString(int numChar) {
//    char *out;
//    out = (char *) malloc(numChar * sizeof(char));
//    return out;
//}

//Assignment 10.2 Duplicate String
char *duplicateString(char *, int);
int main() {
    char *str = duplicateString("abc", 3);
    printf("%s\n", str);
    free(str);
}

char *duplicateString(char *str, int times) {
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }
    char *out;
    out = (char *) malloc(n * times * sizeof(char) + 100); //保险起见 直接+100
    int size1 = 0;
    for (int i = 0; i < times; ++i) {
        for (int j = 0; j < n; ++j) {
            out[size1] = str[j];
            size1++;
        }
    }
    out[size1] = 0; //我也不知道为啥 结尾必须要给0，内存大小明明给对的。估计是编译器的锅，反正能过就行
    return out;
}
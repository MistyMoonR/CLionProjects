#include <stdio.h>


//Exercise 7.1 Total Space

//int main() {
//    int add;
//    int result = 0;
//    scanf("%d", &add);
//    for (int i = 0; i < add; i++) {
//        int inp;
//        char end;
//        scanf("%d %c", &inp, &end);
//        if (end == 'c') {
//            char a[inp];
//            result += sizeof(a);
//        } else if (end == 'i') {
//            int i[inp];
//            result += sizeof(i);
//        } else if (end == 'd') {
//            double d[inp];
//            result += sizeof(d);
//        } else if (end != 'c' && end != 'i' && end != 'd') {
//            printf("invalid type\n");
//            return 0;
//        }
//    }
//    printf("%d bytes\n", result);
//    return 0;
//}

//Assignment 7.1 Display Total Memory
//int main() {
//    char first;
//    int end, resulet;
//    int mb, kb, b;
//    scanf("%c %d", &first, &end);
//    if (first == 'i') {
//        resulet = end * sizeof(int);
//    } else if (first == 's') {
//        resulet = end * sizeof(short);
//    } else if (first == 'd') {
//        resulet = end * sizeof(double);
//    } else { resulet = end * sizeof(char); }
//
//    mb = resulet / 1000000;
//    b = resulet % 1000;
//    if (resulet > 1000000) {
//        kb = (resulet - 1000000 * mb) / 1000;
//        printf("%d MB and %d KB and %d B\n", mb, kb, b);
//    } else if (resulet < 1000000 && resulet > 1000) {
//        kb = resulet / 1000;
//        printf("%d KB and %d B\n", kb, b);
//    } else {
//        printf("%d B\n", b);
//    }
//    return 0;
//
//}


//int main() {
//    //! showMemory(start=65520)
//    double d = 12.34;
//    double * addr_d = &d;
//    printf("address %p value %.2lf\n", addr_d, * addr_d);
//    char c = 'a';
//    char * addr_c = &c;
//    char b = * addr_c;
//    * addr_d = 5.0;
//    * addr_d = * addr_d + 1.0;
//    printf("address %p value %.2lf\n", addr_d, * addr_d);
//    return 0;
//}

//Exercise 7.2 Age Pointer Skeleton Code
//int main() {
//    int age;
//
//    // declare an integer pointer named ageptr :
//    scanf("%d", &age);
//    int *ageptr = &age;
//    // store the address of age in ageptr :
//    printf("You are now %d years old\n", *ageptr);
//    // using only ageptr, lower the age by 5 years :
//    age = age - 5;
//    printf("Five years ago, you are %d years old\n", *ageptr);
//    return 0;
//}

//void swap(int *, int *);
//int main() {
//    //! showMemory(start=65520)
//    int a = 2;
//    int b = 5;
//    swap(&a, &b);
//    printf("%d %d\n", a, b);
//    return 0;
//}
//void swap(int * a, int * b) {
//    int temp = * a;
//    * a = * b;
//    * b = temp;
//}
//void addTen(int *);
//int main() {
//    //! showMemory(start=65520)
//    int a = 5;
//    addTen(&a);
//    printf("%d\n", a);
//    return 0;
//}
//void addTen(int * aPtr) {
//    *aPtr = *aPtr + 10;
//    printf("%d\n", *aPtr);
//}

//Assignment 7.2 Left Right Slide
void swapo(int *, int *, int *);
void swape(int *, int *, int *);

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a % 2 == 0) {
        swape(&a, &b, &c);
    } else {
        swapo(&a, &b, &c);
    }
    return 0;
}

void swapo(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
    printf("%d %d %d\n", *a, *b, *c);
}
void swape(int *a, int *b, int *c) {
    int temp = *b;
    *b = *a;
    *a = *c;
    *c = temp;
    printf("%d %d %d\n", *a, *b, *c);
}



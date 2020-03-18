#include <stdio.h>

int main() {

//    int array[3];
//
//    for (int i = 0; i < 3; i++) {
//        scanf("%d", &array[i]);
//    }
//    for (int i = 0; i < 3; ++i) {
//        printf("array[%d] is %d.\n", i, array[i]);
//    }

//    double array[3];
//    int i;
//    for(i=0; i<3; i++) {
//        scanf("%lf", &array[i]);
//    }
//    for(i=0; i<3; i++) {
//        printf("array[%d] is %.2lf.\n", i, array[i]);
//    }

    //! showArray(ages, cursors=[i])
//    int ages[10];
//    int i, max = 0;
//    for(i=0; i<10; i++) {
//        scanf("%d", &ages[i]);
//        if(ages[i] > max) {
//            max = ages[i];
//        }
//    }
//    printf("The max age is %d.\n", max);

//Exercise 4.1
//
//    int array[10];
//    int num;
//    for (int i = 0; i < 10; ++i) {
//        scanf("%d", &array[i]);
//    }
//    scanf("%d", &num);
//    printf("%d\n", array[num - 1]);

////Exercise 4.2
//    int num;
//    double all = 0;
//    double averg;
//    scanf("%d", &num);
//    double array[20];
//    for (int i = 0; i < num; i++) {
//        scanf("%lf", &array[i]);
//    }
//    for (int j = 0; j < num; j++) {
//        all += array[j];
//    }
//    averg = all / num;
//    for (int k = 0; k < num; k++) {
//        printf("%.1lf\n", averg - array[k]);
//    }

//Assignment 4.1
//    int array1[25];
//    int array2[25];
//    int num, add = 0;
//    scanf("%d", &num);
//    for (int i = 0; i < num; i++) {
//        scanf("%d", &array1[i]);
//    }
//    for (int j = 0; j < num; j++) {
//        scanf("%d", &array2[j]);
//    }
//    for (int k = 0; k < num; k++) {
//        if ((array1[k] - array2[k]) <= 2 && (array2[k] - array1[k]) <= 2 &&(array1[k] - array2[k] != 0)) {
//            add++;
//        }
//
//    }
//    printf("%d\n", add);

//Assignment 4.2
//    int num;
//    double array1[10];
//    double array2[10];
//    double add = 0;
//    scanf("%d", &num);
//    for (int i = 0; i < num; i++) {
//        scanf("%lf", &array1[i]);
//    }
//    for (int j = 0; j < num; j++) {
//        scanf("%lf", &array2[j]);
//    }
//
//    for (int k = 0; k < num; k++) {
//        add += array1[k] * array2[k];
//    }
//
//    printf("%.3lf\n", add);
//

//Assignment 4.3
    int num;
    int array[20];
    int aim;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }
    scanf("%d", &aim);

    for (int j = 1; j < num-1; j++) {
        if (aim == array[j]) {
            if (array[j] != array[j + 1] && array[j] != array[j - 1]) {
                if (array[j - 1] < array[j + 1]) {
                    array[j] = array[j + 1];
                } else {
                    array[j] = array[j - 1];
                }
            }
        }
    }

    for (int k = 0; k < num; ++k) {
        printf("%d ", array[k]);
    }
    printf("\n");
    return 0;
}

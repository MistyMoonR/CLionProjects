#include <stdio.h>

int main() {

//    int num;
//    scanf("%d", &num);
//    for (int i = 0; i < 11; i++) {
//        printf("%dx%d = %d\n", i, num, i * num);
//    }

//    int sweets, box;
//    scanf("%d\n%d", &sweets, &box);
//    printf("%d\n%d ", sweets / box, sweets % box);


//    double d, num;
//    scanf("%lf\n%lf", &d, &num);
//    printf("%d", (int)(d/num));

//    char num;
//    scanf("%c", &num);
//    printf("++++%c++++\n+++%c%c%c+++\n++%c%c%c%c%c++\n+%c%c%c%c%c%c%c+\n%c%c%c%c%c%c%c%c%c", num, num, num, num, num,
//           num, num, num, num, num, num, num, num, num, num, num, num, num, num, num, num, num, num, num, num);

    double arr, sum = 0;
    int input = 0, num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &input);
        sum=sum+input;
    }
    arr = sum / num;
    printf("%0.2f\n", arr);

//    char A;
//    scanf("%c", &A);
//    int flag = 0;
//    int flagB = 1;
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 4 - flag; j++) {
//            printf("%c", '+');
//        }
//        for (int k = 0; k < flagB; k++) {
//            printf("%c", A);
//        }
//        for (int l = 0; l < 4 - flag; l++) {
//            printf("%c", '+');
//        }
//        flag++;
//        flagB += 2;
//        printf("\n");
//    }
//    return 0;

}

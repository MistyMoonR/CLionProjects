#include <stdio.h>

int main() {
//    int goodWeather;
//    goodWeather = 1;
//    if (goodWeather) {
//        printf("The weather is good\n");
//    } else {
//        printf("The wwather is bad\n");
//    }
//
//    int a = 2;
//    int b = 2;
//    int result;
//    result = a == b;
//    if (result) {
//        printf("That is TRUE\n");
//    } else {
//        printf("That is False");
//
//    }
//    int lowprice = 10;
//    int time, cost;
//    scanf("%d", &time);
//    cost = lowprice + time * 5;
//    if(cost >= 53) {
//        printf("%d\n", 53);
//    } else {
//        printf("%d\n", cost);
//    }
    int number;
    int weight;
    int A = 0, B = 0;

    scanf("%d", &number);
    for (int i = 1; i < number*2 + 1; i++) {
        scanf("%d", &weight);
        if (i % 2 == 0) {
            B += weight;
        } else {
            A += weight;
        }
    }

    if (A > B) {
        printf("Team 1 has an advantage\n");
    } else {
        printf("Team 2 has an advantage\n");
    }
    printf("Total weight for team 1: %d\n"
           "Total weight for team 2: %d\n", A, B);


    return 0;
}

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

//    int number;
//    int weight;
//    int A = 0, B = 0;
//
//    scanf("%d", &number);
//    for (int i = 1; i < number*2 + 1; i++) {
//        scanf("%d", &weight);
//        if (i % 2 == 0) {
//            B += weight;
//        } else {
//            A += weight;
//        }
//    }
//
//    if (A > B) {
//        printf("Team 1 has an advantage\n");
//    } else {
//        printf("Team 2 has an advantage\n");
//    }
//    printf("Total weight for team 1: %d\n"
//           "Total weight for team 2: %d\n", A, B);
//
// Assignment 3.1 Carpooling
//    int passenger;
//    double oilcost, cost;
//    scanf("%d ", &passenger);
//    scanf("%lf", &oilcost);
//    if (passenger > 0) {
//        cost = oilcost + 1;
//        printf("%.2f\n", cost / (passenger + 1));
//    } else {
//        cost = oilcost;
//        printf("%.2f\n", cost);
//    }

// Assignment 3.2 Youth Hostel2
//    int age, luggage,cost;
//    scanf("%d\n", &age);
//    scanf("%d", &luggage);
//    if (age < 11) {
//        cost = 5;
//        printf("%d", cost);
//    } else if (age > 59) {
//        cost = 0;
//        printf("%d", cost);
//    } else {
//        cost = 30;
//        if (luggage > 20) {
//            printf("%d", cost + 10);
//        } else {
//            printf("%d", cost);
//        }
//    }
//Assigment 3.3
    int num, city, b = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &city);
        if (city > 10000) {
            b++;
        }
    }
    printf("%d", b);



    return 0;
}

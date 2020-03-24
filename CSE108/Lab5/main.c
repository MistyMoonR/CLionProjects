#include <stdio.h>

int main() {
//    int diceValue, notSix;
//    scanf("%d", &diceValue);
//    notSix = diceValue != -1;
//    while (notSix) {
//        scanf("%d", &diceValue);
//        notSix = diceValue != -1;
//    }
//    printf("hello");

/* Exercise 5.1 Total Expense*/
//    int finput, input, sum = 0;
//    scanf("%d", &input);
//
//    while (input != -1) {
//        sum += input;
//        scanf("%d", &input);
//
//    }
//    printf("%d\n", sum);
//

//Example: Guess Number
//    int secretNum, guess, numGuess = 1;
//    scanf("%d", &secretNum);
//    scanf("%d", &guess);
//    while (guess != secretNum) {
//        if(guess > secretNum) {
//            printf("guess less\n");
//        } else {
//            printf("guess more\n");
//        }
//        numGuess++;
//        scanf("%d", &guess);
//    }
//    printf("number of guesses: %d\n", numGuess);

//Example: Collecting Signatures
//    int signaturesNeeded = 1000;
//    int day = 0;
//    int newSignatures = 3;
//    int totalSignatures = 3;
//    while (totalSignatures < 1000) {
//        day++;
//        newSignatures = 2 * newSignatures;
//        printf("Day %d: %d new signatures! ", day, newSignatures);
//        totalSignatures = totalSignatures + newSignatures;
//        printf("Total: %d\n", totalSignatures);
//    }

/*Assignment 5.1 Epidemic Spread(1)*/
    int signaturesNeeded;
    int day = 1;
    int newSignatures = 1;
    int totalSignatures = 1;
    int k;
    scanf("%d", &signaturesNeeded);
    scanf("%d", &k);
    while (totalSignatures < signaturesNeeded) {
        day++;
        newSignatures = k * newSignatures;
        totalSignatures = totalSignatures + newSignatures;
    }
    printf("%d\n", day);

/*Assignment 5.2 Temperature Monitoring */
//    int min, max;
//    int temp

    return 0;
}

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
//    return 0;

/* Exercise 5.1 Total Expense*/
    int sc1, sum = 0;
    scanf("%d", &sc1);

    while (sc1 != -1) {
        sum += sc1;
        scanf("%d", &sc1);

    }
    printf("%d\n", sum);
    return 0;

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
//    return 0;

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
//    return 0;

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
    return 0;


/*Assignment 5.2 Temperature Monitoring */
    int s, b;
    int sc[20];
    int inp = 0, i = 0;
    scanf("%d", &s);
    scanf("%d", &b);
    while (inp != -999) {
        i++;
        scanf("%d", &sc[i]);
        inp = sc[i];
    }
    for (int j = 1; j < i; ++j) {
        if (sc[j] >= s && sc[j] <= b) {
            printf("Normal\n");
        } else {
            printf("Alert!\n");
            return 0;
        }
    }
    return 0;

//    char word[4] = "fun";
//    printf("The word is: %s.\n", word);
//    printf("The characters are: <%c> <%c> <%c> <%c>\n",
//           word[0], word[1], word[2], word[3]);
//    return 0;

//    char word1[5];
//    char word2[8];
//    scanf("%s %s", word1, word2);
//    word1[3] = '\0';
//    word2[2] = '\0'; //截取前部分后面不显示
//    printf("%s %s\n", word1, word2);
//    return 0;



//Exercise 5.2 Swap Name 只要输入够快，输出就跟不上
    int add;
    char name1[20];
    char name2[20];
    scanf("%d", &add);
    for (int i = 0; i < add; i++) {
        scanf("%s %s", name1, name2);
        printf("%s %s\n", name2, name1);
    }
    return 0;



//    char word[30];
//    int i = 0;
//    printf("Please enter a word: ");
//    scanf("%s", word);
//    while(word[i] != '\0') {
//        i++;
//    }
//    printf("%s has length %d.\n", word, i);
//    return 0;


//! showArray(word, cursors=[i])
//    char word[30];
//    int i = 0;
//    printf("Please enter a word: ");
//    scanf("%s", word);
//    while(word[i] != '\0') {
//        i++;
//    }
//    printf("%s has length %d.\n", word, i);
//    return 0;


//Assignment 5.3 Even Odd Name
    char input1[30];
    int i = 0;
    scanf("%s", input1);
    while (input1[i] != '\0') {
        i++;
    }
    if (i % 2) {
        printf("odd\n");
    } else {
        printf("even\n");
    }
    return 0;


//Assignment 5.4 Longest Length
    char input[100];
    int add;
    int j = 0;
    scanf("%d", &add);
    for (int i = 0; i < add; ++i) {
        scanf("%s", input);

        while (input[j] != '\0') {
            j++;
        }
    }
    printf("%d\n", j);

    return 0;
}

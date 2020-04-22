#include <stdio.h>
//int main() {
//    //! showMemory(cursors=[matrix[0], matrix[1]], start=65520)
//    //! matrix = showArray2D(matrix, rowCursors=[line], colCursors=[col])
//    int matrix[2][3];
//    int line, col;
//    for(line = 0; line < 2; line++){
//        for(col = 0; col < 3; col++){
//            scanf("%d", &matrix[line][col]);
//        }
//    }
//    for(line = 0; line < 2; line++){
//        for(col = 0; col < 3; col++){
//            printf("%d ", matrix[line][col]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

////Exercise 9.1 Print String Lengths
//void printStrLen(char **, int);
//
//int main(){
//    char *input[3] = {"x", "55", "ab34"};
//    printStrLen(input, 3);
//}
//
//void printStrLen(char** input, int num) {
//    for (int i = 0; i < num; ++i) {
//        int n = 0;
//        while (input[i][n] != '\0') {
//            n++;
//        }
//        printf("%d\n", n);
//    }
//}

//Assignment 9.1 Copy String
//void copyStr(char *, char *);
//
//int main() {
//    char *source = "abc";
//    char target[101];
//    copyStr(source, target);
//    printf("%s", target);
//}
//
//void copyStr(char * source, char * target) {
//    while ((*target = *source) != '\0')
//    {
//        target++;
//        source++;
//    }
//}

//Assignment 9.2 Count End Char
//int countEndChar(char **, int, char);
//
//int main() {
//    char *input[5] = {"breaking", "bad", "abcd", "covid", "panda"};
//    printf("%d", countEndChar(input, 5, 'd'));
//}
//
//int countEndChar(char ** input, int size, char endChar) {
//    int out = 0;
//    for (int i = 0; i < size; ++i) {
//        int n = 0;
//        while (input[i][n] != '\0') {
//            n++;
//            }
//        if (input[i][n-1] == endChar) {
//            out++;
//        }
//    }
//    return out;
//}

//Assignment 9.3 Distinct Characters





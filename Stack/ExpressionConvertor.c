#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack_Array.h"

int OperatorRank(char a) {
    if (a == '(') {
        return 0;
    } else if (a == '+' || a == '-') {
        return 1;
    } else if (a == '*' || a == '/') {
        return 2;
    } else if (a == ')') {
        return 3;
    } else {
        return -1;
    }
}

char* stradd(char* str, char c) {
    // char* tmp = {'c', };
    // return strcat(str, tmp);
    return NULL;
}

void ExpressionConvertor(char* expression) {
    Stack S;
    InitStack(&S);
    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
            if (StackEmpty(&S) || c == '(') {
                Push(&S, c);
            } else {
                if (OperatorRank(c) > OperatorRank(S.stack_array[S.top-1])) {
                    if (c == ')') {
                        while (S.stack_array[S.top-1] != '(') {
                            printf("%c\n", Pop(&S));
                        }
                        Pop(&S);
                    } else {
                        Push(&S, c);
                    }
                } else {
                    while (!StackEmpty(&S) && (OperatorRank(c) <= OperatorRank(S.stack_array[S.top-1]))) {
                        printf("%c\n", Pop(&S));
                    }
                    Push(&S, c);
                }
            }
        } else {
            printf("%d\n", (int)expression[i] - 48);
        }
    }
    while (!StackEmpty(&S)) {
        printf("%c\n", Pop(&S));
    }
}

char* ExpressionConverter(char* expression) {
    Stack S;
    InitStack(&S);
    char* tmp = (char*) malloc(100 * sizeof(char*));
    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
            if (StackEmpty(&S) || c == '(') {
                Push(&S, c);
            } else {
                if (OperatorRank(c) > OperatorRank(S.stack_array[S.top-1])) {
                    if (c == ')') {
                        while (S.stack_array[S.top-1] != '(') {
                            // printf("%c\n", Pop(&S));
                            stradd(tmp, c);
                        }
                        Pop(&S);
                    } else {
                        Push(&S, c);
                    }
                } else {
                    while (!StackEmpty(&S) && (OperatorRank(c) <= OperatorRank(S.stack_array[S.top-1]))) {
                        // printf("%c\n", Pop(&S));
                        stradd(tmp, Pop(&S));
                    }
                    Push(&S, c);
                }
            }
        } else {
            // printf("%d\n", (int)expression[i] - 48);
            stradd(tmp, expression[i]);
        }
    }
    while (!StackEmpty(&S)) {
        printf("%c\n", Pop(&S));
        // stradd(tmp, Pop(&S));
    }
    return tmp;
}

int main() {
    char* a = "1+2*3+(4*5+6)*7";
    // char* a = "1+2";
    ExpressionConvertor(a);
    // char* b = ExpressionConverter(a);
    // for (int i = 0; i < strlen(a); i++) {
    //     printf("%c\n", b[i]);
    // }
    return 0;
}
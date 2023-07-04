#include <stdio.h>
#include "nellspsv.c"


void test1() {

    printf("Input: m = 3, n = 2, A[] = {1, 1, 1, 1, 2, 3}, b[] = {1, 1, 1}\n");

    int m = 3; // liczba wierszy A
    int n = 2; // liczba kolumn A

    double A[] = {1, 1, 1, 1, 2, 3};
    double b[] = {1, 1, 1};
    double x[n];

    nellspsv(m, n, A, b, x);
    printf("Solution:\n");
    printf("x = [ ");
    for (int i = 0; i < n; i++) {
         printf("%f ", x[i]);
    }
    printf("]\n");

}


void test2() {
    printf("Input: m = 4, n = 3, A[] = {1, 0, 3, 4, 4, 6, 13, 8, 9, 7, 11, 10}, b[] = {1, 1, 1, 1}\n");

    int m = 4;
    int n = 3;

    double A[] = {1, 0, 3, 4, 4, 6, 13, 8, 9, 7, 11, 10};
    double b[] = {1, 1, 1, 1};
    double x[n];

    nellspsv(m, n, A, b, x);
    printf("Solution:\n");
    printf("x = [ ");
    for (int i = 0; i < n; i++) {
         printf("%f ", x[i]);
    }
    printf("]\n");

}

void test3() {
    printf("Input: m = 3, n = 3, A[] = {1, 2, 4, 4, 9, 6, 7, 8, 5}, b[] = {1, 2, 3}\n");

    int m = 3;
    int n = 3;

    double A[] = {1, 2, 4, 4, 9, 6, 7, 8, 5};
    double b[] = {1, 2, 3};
    double x[n];

    nellspsv(m, n, A, b, x);
    printf("Solution:\n");
    printf("x = [ ");
    for (int i = 0; i < n; i++) {
         printf("%f ", x[i]);
    }
    printf("]\n");
}

int main() {

    test1();
    printf("\n");
    test2();
    printf("\n");
    test3();

    return 0;
}


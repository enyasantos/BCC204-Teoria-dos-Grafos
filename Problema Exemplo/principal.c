#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b) {
    return (a + b);
}

int main() {
    int a, b, x;
    scanf("%d", &a);
    scanf("%d", &b);
    x = sum(a, b);
    printf("X = %d\n", x);
    return 0;
}
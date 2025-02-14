#include <stdio.h>

void add(int *a, int *b, int *c, int *sum) {
    *sum = *a + *b + *c;
}

int main() {
    int x = 10, y = 20, z = 30, sum;
    add(&x, &y, &z, &sum);
    printf("Sum: %d\n", sum);
    return 0;
}

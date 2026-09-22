#include <stdio.h>

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("请输入n: ");
    scanf("%d", &n);

    printf("斐波那契数列第%d项是: %d\n", n, fib(n));

    printf("前%d项:", n + 1
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");


    return 0;
}

#include <stdio.h>


int fibonacci_tail(int n, int a, int b) {
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    }
    return fibonacci_tail(n - 1, b, a + b);
}


int fibonacci(int n) {
    return fibonacci_tail(n, 0, 1);
}

int main() {
    int n = 10; 
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    return 0;
}

//Na recursão em cauda, a chamada recursiva é a última operação realizada na função. O compilador pode otimizar isso para reutilizar o frame atual em vez de criar um novo, minimizando o uso da pilha e evitando o estouro de pilha.
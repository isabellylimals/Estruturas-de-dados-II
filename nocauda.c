#include <stdio.h>

// Função recursiva sem cauda para calcular o n-ésimo número de Fibonacci
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10; // Exemplo de cálculo do 10º número de Fibonacci
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    return 0;
}

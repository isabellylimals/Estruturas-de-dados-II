#include <stdio.h>

int cont = 0;

int funcRecursiva(int n) {
    if (n == 0) {
        return 1;
    }
    
    if (n == 5) {
        cont++;
    }
    int k = funcRecursiva(n - 1);
    return k + 1 / k;
}

int main() {
    funcRecursiva(5);
    printf("Número de vezes que funcRecursiva(5) é chamado: %d\n", cont);
    return 0;
}


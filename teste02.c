#include <stdio.h>

// Função para calcular o fatorial de um número
int fatorial(int n) {
    printf("Entrando na funcao fatorial com n = %d\n", n);
    if (n == 0) {
        printf("n eh igual a 0, retornando 1\n");
        return 1;
    } else {
        int resultado = n * fatorial(n - 1);
        printf("Resultado parcial do fatorial(%d) = %d\n", n, resultado);
        return resultado;
    }
}

int main() {
    int numero;
    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &numero); 
    int resultado = fatorial(numero);
    printf("O fatorial de %d é %d\n", numero, resultado);
    return 0;
}


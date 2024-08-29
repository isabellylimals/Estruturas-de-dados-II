#include <stdio.h>

int chamadaRecursivaCount = 0;
int retornoRecursivaCount = 0;
int atribuicaoSomaCount = 0;
int divisaoMultiplicacaoCount = 0;

int f(int n) {
    if (n==5){chamadaRecursivaCount++;  // Contador de chamadas recursivas
    }
    if (n == 0) {
        retornoRecursivaCount++;  // Contador de retornos de chamada recursiva
        return 1;
    }
    
   
    int result1 = f(n - 1);
    atribuicaoSomaCount++;  // Contador de atribuições e somas
    int result2 = 1 / f(n - 1);
    divisaoMultiplicacaoCount++;  // Contador de divisões e multiplicações
    
    retornoRecursivaCount++;  // Contador de retornos de chamada recursiva
    return result1 + result2;
}

int main() {
    int n = 20;
    int resultado = f(n);

    // Tempos em ns
    int chamadaRecursivaTempo = chamadaRecursivaCount * 2;
    int retornoRecursivaTempo = retornoRecursivaCount * 1;
    int atribuicaoSomaTempo = atribuicaoSomaCount * 0.5;
    int divisaoMultiplicacaoTempo = divisaoMultiplicacaoCount * 1.5;

    // Tempo total
    int tempoTotal = chamadaRecursivaTempo + retornoRecursivaTempo + atribuicaoSomaTempo + divisaoMultiplicacaoTempo;

    printf("Resultado: %d\n", resultado);
    printf("Total de chamadas recursivas: %d, Tempo total: %dns\n", chamadaRecursivaCount, chamadaRecursivaTempo);
    printf("Total de retornos de chamada recursiva: %d, Tempo total: %dns\n", retornoRecursivaCount, retornoRecursivaTempo);
    printf("Total de atribuições e somas: %d, Tempo total: %dns\n", atribuicaoSomaCount, atribuicaoSomaTempo);
    printf("Total de divisões e multiplicações: %d, Tempo total: %dns\n", divisaoMultiplicacaoCount, divisaoMultiplicacaoTempo);
    printf("Tempo total do algoritmo: %dns\n", tempoTotal);

    return 0;
}

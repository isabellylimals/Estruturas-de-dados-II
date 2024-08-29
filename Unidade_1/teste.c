#include <stdio.h>

void funcao_recursiva(int profundidade) {
    printf("Profundidade: %d\n", profundidade);
    if (profundidade > 0) {
        funcao_recursiva(profundidade - 1);
    }
}

int main() {
    printf("Iniciando a recursão...\n");
    funcao_recursiva(10);
    printf("Recursão concluída.\n");
    return 0;
}

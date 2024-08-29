#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Info {
    char nome[100];
    int mat;
    int turma;
    float nota;
};

struct Node {
    struct Node* esq;
    struct Node* direita;
    struct Info info;
};


struct Node* criarNo(struct Info info) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->info = info;
    novoNo->esq = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

struct Node* inserir(struct Node* raiz, struct Info info) {
    if (raiz == NULL) {
        return criarNo(info);
    }
   
    if (info.mat < raiz->info.mat) {
        raiz->esq = inserir(raiz->esq, info);
    } else {
        raiz->direita = inserir(raiz->direita, info);
    }
    return raiz;
}

// Função para imprimir a árvore (em ordem)
void imprimirEmOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esq);
        printf("Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n",
               raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
        imprimirEmOrdem(raiz->direita);
    }
}

int main() {
    struct Node* raiz = NULL;
    
    // Cria alguns dados de exemplo
    struct Info info1 = {"Maria_Isabelly_Lima", 3, 1, (float)(rand() % 10)};
    struct Info info2 = {"Joao_Silva", 1, 2, (float)(rand() % 10)};
    struct Info info3 = {"Ana_Pereira", 5, 1, (float)(rand() % 10)};
    
    // Insere os dados na árvore
    raiz = inserir(raiz, info1);
    raiz = inserir(raiz, info2);
    raiz = inserir(raiz, info3);
    
    // Imprime a árvore
    imprimirEmOrdem(raiz);
    
    return 0;
}

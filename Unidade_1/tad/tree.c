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
    struct Info info;
    struct Node* esq;
    struct Node* direita;
};

struct Node* criarNo(char* nome, int mat, int turma, float nota) {
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
    if (novo == NULL) {
        perror("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }
    strcpy(novo->info.nome, nome);
    novo->info.mat = mat;
    novo->info.turma = turma;
    novo->info.nota = nota;
    novo->esq = NULL;
    novo->direita = NULL;
    return novo;
}

struct Node* inserir(struct Node* raiz, struct Info info) {
    if (raiz == NULL) {
        return criarNo(info.nome, info.mat, info.turma, info.nota);
    }

    if (info.mat < raiz->info.mat) {
        raiz->esq = inserir(raiz->esq, info);
    } else {
        raiz->direita = inserir(raiz->direita, info);
    }

    return raiz;
}

struct Node* lerArquivoEInserir(struct Node* raiz) {
    FILE* arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        printf("Certifique-se de que o arquivo 'dados.txt' está no diretório correto.\n");
        return NULL;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        struct Info aluno;
        linha[strcspn(linha, "\n")] = 0;

        printf(" %s\n", linha);

        if (sscanf(linha, "%d,%99[^,],%d,%f", &aluno.mat, aluno.nome, &aluno.turma, &aluno.nota) == 4) {
            raiz = inserir(raiz, aluno);
        } 
    }

    fclose(arquivo);
    return raiz;
}

void imprimirPreOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        printf("Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->direita);
    }
}

void imprimirEmOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esq);
        printf("Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
        imprimirEmOrdem(raiz->direita);
    }
}

void imprimirPosOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        imprimirPosOrdem(raiz->esq);
        imprimirPosOrdem(raiz->direita);
        printf("Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
    }
}

void imprimirFilhoEspecifico(struct Node* raiz, int mat, int turma) {
    if (raiz == NULL) {
        printf("Árvore vazia.\n");
        return;
    }

    struct Node* pai = NULL;
    struct Node* filho = NULL;
    struct Node* atual = raiz;

    while (atual != NULL) {
        if (mat == atual->info.mat && turma == atual->info.turma) {
            filho = atual;
            break;
        }

        pai = atual;
        if (mat < atual->info.mat) {
            atual = atual->esq;
        } else {
            atual = atual->direita;
        }
    }

    if (filho != NULL) {
        if (pai != NULL) {
            printf("No Filho: Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", filho->info.nome, filho->info.mat, filho->info.turma, filho->info.nota);
            printf("Pai: Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", pai->info.nome, pai->info.mat, pai->info.turma, pai->info.nota);
        } else {
            printf("No Filho: Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", filho->info.nome, filho->info.mat, filho->info.turma, filho->info.nota);
            printf("Pai: Nenhum (é a raiz)\n");
        }

        if (filho->esq != NULL) {
            printf("Filho Esquerdo: Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", filho->esq->info.nome, filho->esq->info.mat, filho->esq->info.turma, filho->esq->info.nota);
        } else {
            printf("Filho Esquerdo: Nenhum\n");
        }

        if (filho->direita != NULL) {
            printf("Filho Direito: Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", filho->direita->info.nome, filho->direita->info.mat, filho->direita->info.turma, filho->direita->info.nota);
        } else {
            printf("Filho Direito: Nenhum\n");
        }
    } else {
        printf("No com matrícula %d e turma %d não encontrado.\n", mat, turma);
    }
}

void liberarArvore(struct Node* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    struct Node* raiz = NULL;

    raiz = lerArquivoEInserir(raiz);

    printf("Impressao em Pre-Ordem:\n");
    imprimirPreOrdem(raiz);

    printf("\nImpressao em Ordem:\n");
    imprimirEmOrdem(raiz);

    printf("\nImpressao em Pos-Ordem:\n");
    imprimirPosOrdem(raiz);

    int matriculaFilho = 31;  
    int turmaFilho = 3;  
    imprimirFilhoEspecifico(raiz, matriculaFilho, turmaFilho);

    liberarArvore(raiz);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Info{
    char nome[100];
    int mat;
    int turma;
    float nota;

    
};
 struct Node{
    struct Node*esq;
    struct Node*direita;
    struct Info info;
    

};
int main(){
struct Node*raiz=(struct Node*)malloc (sizeof(struct Node));

strcpy(raiz->info.nome,"Maria_Isabelly_Lima");
raiz->info.mat= 3;
raiz->info.turma= 1;
raiz->info.nota= rand()%10;


raiz->direita=0;
raiz->esq=0;
return 0;}
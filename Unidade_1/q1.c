#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[100];
    int matricula;
    int turma;
    float nota;  
} Aluno;


typedef struct Node {
    Aluno aluno;
    struct Node* left;
    struct Node* right;
} Node;


struct Node* criarno(Aluno aluno)
{
    struct Node* raiz = (struct Node*)malloc(sizeof(struct Node));
    
    strcpy(raiz->aluno.nome, aluno.nome);
    raiz->aluno.matricula = aluno.matricula;
    raiz->aluno.turma = aluno.turma;
    raiz->aluno.nota = aluno.nota;
    raiz->left = NULL;
    raiz->right = NULL;
    
    return raiz;
}

int main() {
    Node* rootTurma1 = NULL;
    Node* rootTurma2 = NULL;
    Node* rootTurma3 = NULL;

    Aluno turma1[] = {
        {"ALEX BRUNO DUARTE", 1, "01"}, {"AMANDA DE QUEIROZ SANTIAGO", 2, "01"},
        {"ANAILTON ARTUR FERNANDES", 3, "01"}, {"ANTHONY MATHEUS NASCIMENTO FREITAS", 4, "01"},
        {"DIEGO NASCIMENTO DE OLIVEIRA", 5, "01"}, {"FABRICIO ANDREY LEANDRO DAMIAO", 6, "01"},
        {"FERNANDO UMBILINO ALVES", 7, "01"}, {"FRANCISCO RYAM FEITOSA DINIZ", 8, "01"},
        {"GUILHERME DE FRANCA VASCONCELOS", 9, "01"}, {"HARLEY LUCAS DE SOUZA BATISTA", 10, "01"},
        {"JOSE FERREIRA SOUSA NETO", 11, "01"}, {"JOSE VERISSIMO DE OLIVEIRA QUEIROZ", 12, "01"},
        {"LUIS IZAÍAS VALENTIM DE AQUINO", 13, "01"}, {"MEL CAMILY MONTENEGRO CARDOSO", 14, "01"},
        {"PABLO GERALDO LINHARES DO NASCIMENTO LEITE", 15, "01"}, {"STHEFFANY DA C MARA GUILHERMINO", 16, "01"},
        {"THALLYS ARAUJO DE MORAIS", 17, "01"}, {"TÚLIO GOMES DE ARAÚJO FEITOSA", 18, "01"},
        {"VICENTE BENTO DA SILVA NETO", 19, "01"}
    };
    insertStudentData(&rootTurma1, turma1, sizeof(turma1)/sizeof(turma1[0]));

    // Dados dos alunos para a Turma 02
    Aluno turma2[] = {
        {"ANTONIO ERICK DA SILVEIRA FARIAS OLIVEIRA", 1, "02"}, {"ANTONIO NOGUEIRA DA SILVA NETO", 2, "02"},
        {"DANIEL NERES VIEIRA", 3, "02"}, {"EDUARDO PEREIRA ABRANTES", 4, "02"}, {"EVERSON ALISSON QUEIROZ SILVA", 5, "02"},
        {"GUSTAVO KESLEY DE FONTES NUNES", 6, "02"}, {"JEAN RICHARDSON GONCALVES MARCOS", 7, "02"},
        {"JOAO GUSTAVO SOUZA LIMA", 8, "02"}, {"JOSE MATHEUS GOMES SILVA", 9, "02"}, {"LEANDRO CARLOS MARTINS DE CARVALHO", 10, "02"},
        {"NATTAN FERREIRA LOPES", 11, "02"}, {"PEDRO LUCAS DE SOUSA FERREIRA", 12, "02"}, {"RUBENS ALEXANDRE DE SOUSA FERREIRA", 13, "02"},
        {"SAMUEL DE ALMEIDA SATURNO", 14, "02"}, {"WESLLEY EMANOEL SILVA SOARES", 15, "02"}
    };
    insertStudentData(&rootTurma2, turma2, sizeof(turma2)/sizeof(turma2[0]));

    // Dados dos alunos para a Turma 03
    Aluno turma3[] = {
        {"ALLAN GABRIEL SILVA DE FREITAS", 1, "03"}, {"ALLYSON DA SILVA FELIX", 2, "03"}, {"ANA BEATRIZ ALMEIDA DA SILVA", 3, "03"},
        {"ANTONIO JOAQUIM DE LIRA NETO", 4, "03"}, {"ANTONIO VINICIUS OLIVEIRA LIMA", 5, "03"}, {"ARTUR CARVALHO GAMA", 6, "03"},
        {"CARLOS HENRIQUE DUARTE ABRANTES", 7, "03"}, {"DINARTE RODRIGUES DE OLIVEIRA FILHO", 8, "03"}, {"ERIK THADEU SALES PRAXEDES", 9, "03"},
        {"EVELYN CRISTINA DE OLIVEIRA GOMES", 10, "03"}, {"FABIO QUEIROZ VIEIRA", 11, "03"}, {"FRANCIER EDUARDO DA SILVA LUZ", 12, "03"},
        {"FRANCISCO ADRIAN VINICIUS CHAVES SAMPAIO", 13, "03"}, {"FRANCISCO LAILSON DE ALMEIDA", 14, "03"}, {"GUSTAVO RODRIGUES DOS REIS", 15, "03"},
        {"HILLARY DINIZ SALDANHA", 16, "03"}, {"JOSE KAYQUE LIMA LOPES", 17, "03"}, {"JUANNY THAYSSA GUEDES DE FREITAS", 18, "03"},
        {"KAUE VALENTIM DE CARVALHO", 19, "03"}, {"LEONARDO AUGUSTO SILVA DE SOUSA", 20, "03"}, {"LETICIA MARIA GONCALVES DE MORAIS", 21, "03"},
        {"LETICIA VIEIRA GONCALVES", 22, "03"}, {"LEVITICO RIMON PEREZ ANDRADE ALVES", 23, "03"}, {"LUIZ EDUARDO DE ALMEIDA RODRIGUES", 24, "03"},
        {"MARCELO AUGUSTO DA SILVA FERNANDES", 25, "03"}, {"MARCELO HENRIQUE MESSIAS CAVALCANTE", 26, "03"}, {"MARIA CLARA SARAIVA LEAL", 27, "03"},
        {"MARIA EDUARDA DA SILVA SOUZA", 28, "03"}, {"MARIA EDUARDA RODRIGUES BEZERRA", 29, "03"}, {"MARIA ISABELLY LIMA DE SOUSA", 30, "03"},
        {"PEDRO HENRIQUE ANDRADE DA CONCEICAO", 31, "03"}, {"SAMUEL IAGO DE FARIAS CABRAL", 32, "03"}, {"SHAMYRA DE FATIMA SARAIVA CARVALHO", 33, "03"},
        {"THYAGO FABRICIO MELO COSTA", 34, "03"}, {"TOBIAS FERNANDES FIGUEIREDO", 35, "03"}
    };
    insertStudentData(&rootTurma3, turma3, sizeof(turma3)/sizeof(turma3[0]));}

    void preOrder(Node* root) {
    if (root != NULL) {
        printf("Nome: %s, Matrícula: %d, Turma: %s, Nota: %.2f\n", root->aluno.nome, root->aluno.matricula, root->aluno.turma, root->aluno.nota);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("Nome: %s, Matrícula: %d, Turma: %s, Nota: %.2f\n", root->aluno.nome, root->aluno.matricula, root->aluno.turma, root->aluno.nota);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("Nome: %s, Matrícula: %d, Turma: %s, Nota: %.2f\n", root->aluno.nome, root->aluno.matricula, root->aluno.turma, root->aluno.nota);
    }
}

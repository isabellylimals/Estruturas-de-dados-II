#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da árvore binária
typedef struct Node {
    char name[50];
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo nó na árvore binária
Node* insertNode(Node* root, const char* name) {
    if (root == NULL) {
        return createNode(name);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name);
    } else {
        root->right = insertNode(root->right, name);
    }
    return root;
}

// Função para imprimir a árvore em ordem (in-order traversal)
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s ", root->name);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, "Michael");
    insertNode(root, "Sarah");
    insertNode(root, "John");
    insertNode(root, "Anna");
    insertNode(root, "David");

    printf("Árvore Binária (em ordem): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}

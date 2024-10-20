#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000  
#define NAME_SIZE 100   

typedef struct {
    int id;
    char name[NAME_SIZE];
} Node;

typedef struct {
    int neighbors[MAX_NODES];
    int count;
} AdjacencyList;

int read_nodes(const char* filenode, Node* nodes) {
    FILE* file = fopen(filenode, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo de nós: %s\n", filenode);
        return 0;
    }

    char line[256];
    int node_count = 0;
    fgets(line, sizeof(line), file);  // Ignora o cabeçalho

    while (fgets(line, sizeof(line), file)) {
        int id, new_id;
        char name[NAME_SIZE];

        if (sscanf(line, "%d,\"%[^\"]\",%d", &id, name, &new_id) == 3) {
            nodes[new_id].id = id;
            strcpy(nodes[new_id].name, name);
            node_count++;
        } else {
            printf("Aviso: Linha inválida ignorada: %s\n", line);
        }
    }

    fclose(file);
    return node_count;
}

void read_edges(const char* fileedge, AdjacencyList* adj) {
    FILE* file = fopen(fileedge, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo de arestas: %s\n", fileedge);
        return;
    }

    int u, v;
    while (fscanf(file, "%d,%d", &u, &v) == 2) {
        adj[u].neighbors[adj[u].count++] = v;
        adj[v].neighbors[adj[v].count++] = u;
    }

    fclose(file);
}

int bfs(AdjacencyList* adj, int start, int end) {
    int queue[MAX_NODES], dist[MAX_NODES];
    bool visited[MAX_NODES] = {false};
    int front = 0, back = 0;

    queue[back++] = start;
    visited[start] = true;
    dist[start] = 0;

    while (front < back) {
        int node = queue[front++];
        if (node == end) {
            return dist[node];
        }
int i;
        for (i = 0; i < adj[node].count; i++) {
            int neighbor = adj[node].neighbors[i];
            if (!visited[neighbor]) {
                queue[back++] = neighbor;
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
            }
        }
    }

    return -1;
}

int find_node_by_name(Node* nodes, int node_count, const char* name) {
    int i;
    for (i = 0; i < node_count; i++) {
        if (strcasecmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Node nodes[MAX_NODES] = {0};
    AdjacencyList adj[MAX_NODES] = {0};

    // Carregue o arquivo de nós e o de arestas passando os nomes dos arquivos
    int node_count = read_nodes("filenodes", nodes);
    read_edges("fileedges", adj);

    int zlatan_id = find_node_by_name(nodes, node_count, "Zlatan Ibrahimovic");
    int federer_id = find_node_by_name(nodes, node_count, "Roger Federer");

    if (zlatan_id == -1 || federer_id == -1) {
        printf("Um ou ambos os jogadores não foram encontrados.\n");
        return 1;
    }

    int steps = bfs(adj, zlatan_id, federer_id);
    if (steps != -1) {
        printf("Zlatan Ibrahimovic e Roger Federer estão separados por %d graus.\n", steps);
    } else {
        printf("Não há caminho entre Zlatan Ibrahimovic e Roger Federer.\n");
    }

    int start = 423;
    int end = 424;

    if (nodes[start].id == 0 || nodes[end].id == 0) {
        printf("Erro: Um ou ambos os nós (%d, %d) não foram encontrados.\n", start, end);
        return 1;
    }

    steps = bfs(adj, start, end);
    if (steps != -1) {
        printf("Nome do famoso (nó origem - %d): %s\n", start, nodes[start].name);
        printf("Nome do famoso (nó de destino - %d): %s\n", end, nodes[end].name);
        printf("Quantidade de passos (arestas) que os separam: %d\n", steps);
    } else {
        printf("Não há caminho entre os nós especificados.\n");
    }

    return 0;
}

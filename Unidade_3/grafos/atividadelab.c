#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_NAME_LENGTH 100

typedef struct {
    long long id;
    char name[MAX_NAME_LENGTH];
    int new_id;
} Node;

typedef struct {
    int *adjacency_list;
    int size;
    int capacity;
} Graph;

Node nodes[MAX_NODES];
int node_count = 0;

void add_node(long long id, const char *name, int new_id) {
    nodes[node_count].id = id;
    strncpy(nodes[node_count].name, name, MAX_NAME_LENGTH);
    nodes[node_count].new_id = new_id;
    node_count++;
}

void read_nodes(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo de nós");
        return;
    }

    char line[256];
    fgets(line, sizeof(line), file); // Ignora o cabeçalho

    while (fgets(line, sizeof(line), file)) {
        long long id;
        int new_id;
        char name[MAX_NAME_LENGTH];

        sscanf(line, "%lld %s %d", &id, name, &new_id);
        add_node(id, name, new_id);
    }

    fclose(file);
}

Graph create_graph() {
    Graph graph;
    graph.adjacency_list = (int *)malloc(MAX_NODES * sizeof(int));
    graph.size = 0;
    graph.capacity = MAX_NODES;
    return graph;
}

void add_edge(Graph *graph, int u, int v) {
    if (graph->size >= graph->capacity) {
        graph->capacity *= 2;
        graph->adjacency_list = realloc(graph->adjacency_list, graph->capacity * sizeof(int));
    }
    graph->adjacency_list[graph->size++] = u;
    graph->adjacency_list[graph->size++] = v;
}

void read_edges(Graph *graph, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo de arestas");
        return;
    }

    while (1) {
        int u, v;
        if (fscanf(file, "%d,%d", &u, &v) != 2) {
            break;
        }
        add_edge(graph, u, v);
    }

    fclose(file);
}

int bfs(Graph *graph, int start, int end) {
    int queue[MAX_NODES];
    int visited[MAX_NODES] = {0};
    int front = 0, rear = 0;
    int distance = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int size = rear - front;
        distance++;
        int i;
        for ( i = 0; i < size; i++) {
            int node = queue[front++];
            int j;
            for ( j = 0; j < graph->size; j++) {
                if (graph->adjacency_list[j] == node) {
                    int neighbor = graph->adjacency_list[j + 1];
                    if (neighbor == end) {
                        return distance;
                    }
                    if (!visited[neighbor]) {
                        visited[neighbor] = 1;
                        queue[rear++] = neighbor;
                    }
                }
            }
        }
    }
    return -1;
}

int find_node_by_name(const char *name) {
    int i;
    for (i = 0; i < node_count; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return nodes[i].new_id;
        }
    }
    return -1;
}

int main() {
    read_nodes("fb_famosos.nodes.txt");

    Graph graph = create_graph();
    read_edges(&graph, "fb_famosos.edges.txt");

    int zlatan_id = find_node_by_name("Zlatan Ibrahimovic");
    int federer_id = find_node_by_name("Roger Federer");

    if (zlatan_id == -1 || federer_id == -1) {
        printf("Um ou ambos os jogadores não foram encontrados.\n");
        return 1;
    }

    int steps = bfs(&graph, zlatan_id, federer_id);

    if (steps != -1) {
        printf("Zlatan Ibrahimovic e Roger Federer estão separados por %d graus.\n", steps);
    } else {
        printf("Não há caminho entre Zlatan Ibrahimovic e Roger Federer.\n");
    }

    free(graph.adjacency_list);
    return 0;
}

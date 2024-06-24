#include <stdio.h>
#include <limits.h>

#define V_MAX 100 

int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int n, int graph[V_MAX][V_MAX], int V) {
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}


void primMST(int graph[][V_MAX], int V) {
    int parent[V_MAX]; 
    int key[V_MAX]; 
    int mstSet[V_MAX]; 

    
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1; 
    
    for (int count = 0; count < V - 1; count++) {
   
        int u = minKey(key, mstSet, V);

        mstSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

   
    printMST(parent, V, graph, V);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);


    int graph[V_MAX][V_MAX];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0; 
        }
    }

   
    printf("Enter the source vertex, destination vertex, and weight for each edge:\n");
    for (int i = 0; i < E; i++) {
        int source, dest, weight;
        scanf("%d %d %d", &source, &dest, &weight);
        graph[source][dest] = weight;
        graph[dest][source] = weight; 
    }

    primMST(graph, V);

    return 0;
}


      
    Graph* createGraph(int V, int E) {  
        Graph* graph = (Graph*) malloc(sizeof(Graph));  
        graph->V = V;  
        graph->E = E;  
        return graph;  
    }  
      
    int find(Subset subsets[], int i) {  
        if (subsets[i].parent != i) {  
            subsets[i].parent = find(subsets, subsets[i].parent);  
        }  
        return subsets[i].parent;  
    }  
      
    void Union(Subset subsets[], int x, int y) {  
        int xroot = find(subsets, x);  
        int yroot = find(subsets, y);  
      
        if (subsets[xroot].rank < subsets[yroot].rank) {  
            subsets[xroot].parent = yroot;  
        } else if (subsets[xroot].rank > subsets[yroot].rank) {  
            subsets[yroot].parent = xroot;  
        } else {  
            subsets[yroot].parent = xroot;  
            subsets[xroot].rank++;  
        }  
    }  
      
    int compare(const void* a, const void* b) {  
        Edge* a_edge = (Edge*) a;  
        Edge* b_edge = (Edge*) b;  
        return a_edge->weight - b_edge->weight;  
    }  
      
    void kruskalMST(Graph* graph) {  
        Edge mst[graph->V];  
        int e = 0, i = 0;  
      
        qsort(graph->edges, graph->E, sizeof(Edge), compare);  
      
        Subset* subsets = (Subset*) malloc(graph->V * sizeof(Subset));  
        for (int v = 0; v < graph->V; ++v) {  
            subsets[v].parent = v;  
            subsets[v].rank = 0;  
        }  
      
        while (e < graph->V - 1 && i < graph->E) {  
            Edge next_edge = graph->edges[i++];  
      
            int x = find(subsets, next_edge.src);  
            int y = find(subsets, next_edge.dest);  
      
            if (x != y) {  
                mst[e++] = next_edge;  
                Union(subsets, x, y);  
            }  
        }  
      
        printf("Minimum Spanning Tree:\n");  
        for (i = 0; i < e; ++i) {  
            printf("(%d, %d) -> %d\n", mst[i].src, mst[i].dest, mst[i].weight);  
        }  
    }  
      
    int main() {  
        int V, E;  
        printf("Enter number of vertices and edges: ");  
        scanf("%d %d", &V, &E);  
      
        Graph* graph = createGraph(V, E);  
      
        printf("Enter edges and their weights:\n");  
        for (int i = 0; i < E; ++i) {  
            scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);  
        }  
      
        kruskalMST(graph);  
      
        return 0;  
    }  

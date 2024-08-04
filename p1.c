#include<stdio.h>
#include<limits.h>
#define V_MAX 100
int i,j,v,count;
int minkey(int key[],int mstSet[],int V){
int min=INT_MAX,min_index;
for(v=0;v<V;v++)
if(mstSet[v]==0 && key[v],min)
min=key[v],min_index=v;
return min_index;
}
void printMST(int parent[],int n,int graph[V_MAX][V_MAX],int V){
printf("Edge Weight\n");
for(i=1;i<V;i++)
printf("%d %d %d\n",parent[i],i,graph[i][parent[i]]);
}
void primMST(int graph[][V_MAX],int V){
int parent[V_MAX];
int key[V_MAX];
int mstSet[V_MAX];
for(i=0;i<V;i++)
key[i]=INT_MAX,mstSet[i]=0;
key[0]=0;
parent[0]=-1;
for(count=0;count<V-1;count++){
int u=minkey(key,mstSet,V);
mstSet[u]=1;
for(v=0;v<V;v++)
if(graph[u][v]&&mstSet[v]==0&&graph[u][v]<key[v])
parent[v]=u,key[v]=graph[u][v];
}
printMST(parent,V,graph,V);
}
int main(){
int V,E;
printf("enter the number of vertices and edges:");
scanf("%d %d",&V,&E);
int graph[V_MAX][V_MAX];
for(i=0;i<V;i++){
for(j=0;j<V;j++){
graph[i][j]=0;
}
}
printf("enter the source vertex,destination vertx and weight for each edge:\n");
for(i=0;i<E;i++){
int source,dest,weight;
scanf("%d %d %d",&source,&dest,&weight);
graph[source][dest]=weight;
graph[dest][source]=weight;
}
primMST(graph,V);
return 0;
}

YESHWANTH KALSIRO CODE ...............
#include <stdio.h>
#define INF 999
#define MAX 100
int p[MAX], c[MAX][MAX], t[MAX][2];
int find(int v) {
    while (p[v]) {
        v = p[v];   }
    return v;}

void union1(int i, int j) {
    p[j] = i;}

void kruskal(int n) {
    int i, j, k, u, v, min, res1, res2, sum = 0;
 for (k = 1; k < n; k++) {
        min = INF;
        for (i = 1; i <= n - 1; i++) {
            for (j = 1; j <= n; j++) {
                if (i == j) continue;
                if (c[i][j] < min) {
                    u = find(i);
                    v = find(j);
                    if (u != v) {
                        res1 = i;
                        res2 = j;
                        min = c[i][j];        }    }      }}
        union1(find(res1), find(res2));
        t[k][1] = res1;
        t[k][2] = res2;
        sum += min; }
    printf("\nCost of spanning tree is=%d", sum);
    printf("\nEdges of spanning tree are:\n");
    for (i = 1; i < n; i++) {
        printf("%d -> %d\n", t[i][1], t[i][2]);    }}

int main() {
    int i, j, n;
 printf("\nEnter the n value: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        p[i] = 0; }
  printf("\nEnter the graph data:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);       }    }
 kruskal(n);
    return 0;
}

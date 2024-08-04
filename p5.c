#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
typedef struct{
int V;
int**adjMatrix;
}Graph;
Graph*createGraph(int V){
Graph*graph=(Graph*)malloc(sizeof(Graph));
graph->V=V;
graph->adjMatrix=(int**)calloc(V,sizeof(int*));
int i;
for(i=0;i<V;i++)
graph->adjMatrix[i]=(int*)calloc(V,sizeof(int));
return graph;
}
void addEdge(Graph*graph,int src,int dest){
graph->adjMatrix[src][dest]=1;
}
void topologicalSort(Graph*graph){
int V=graph->V,inDegree[MAX_VERTICES]={0},queue[MAX_VERTICES],front=0,rear=-1;
int i,j;
for(i=0;i<V;i++)
for(j=0;j<V;j++)
if(graph->adjMatrix[i][j]==1)
inDegree[j]++;
for(i=0;i<V;i++)
if(inDegree[i]==0)
queue[++rear]=i;
printf("Topological ordering of vertices:");
while(front<=rear){
int vertex=queue[front++];
printf("%d",vertex);
for(i=0;i<V;i++)
if(graph->adjMatrix[vertex][i]==1&&--inDegree[i]==0)queue[++rear]=i;
}
printf("\n");
}
int main(int src,int dest){
int V,E,i;
printf("Enter the number of vertices:");
scanf("%d",&V);
Graph*graph=createGraph(V);
printf("enter the number of edges:");
scanf("%d",&E);
printf("enter the edges(souce vertex,destination vaertex):\n");
for(i=0,src,dest;i<E;i++){
scanf("%d%d",&src,&dest);
addEdge(graph,src,dest);
}
topologicalSort(graph);
return 0;
}

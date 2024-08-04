#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define MAX_VERTICES 10
#define INF INT_MAX
int minDistance(int dist[],bool sptSet[],int V)
{
int min=INF,min_index,v;
for(v=0;v<V;v++)
if(sptSet[v]==false&&dist[v]<=min)
min=dist[v],min_index=v;
return min_index;
}
void printSolution(int dist[],int V){
int i;
printf("Vertex\t\t Distance from source\n");
for(i=0;i<V;i++)
printf("%d\t\t%d\n",i,dist[i]);
}
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES],int src,int V){
int dist[MAX_VERTICES];
int i;
bool sptSet[MAX_VERTICES];
for(i=0;i<V;i++)
dist[i]=INF,sptSet[i]=false;
dist[src]=0;
int count;
for(count=0;count<V-1;count++){
int u=minDistance(dist,sptSet,V);
sptSet[u]=true;
int v;
for(v=0;v<V;v++)
if(!sptSet[v]&&graph[u][v]&&dist[u]!=INF&&dist[u]+graph[u][v]<dist[v])
dist[v]=dist[u]+graph[u][v];
}
printSolution(dist,V);
}
int main(){
int V,E,i;
printf("Enter the number of vertices:");
scanf("%d",&V);
printf("Enter the number of edges:");
scanf("%d",&E);
int graph[MAX_VERTICES][MAX_VERTICES]={{0}};
printf("enter the source vertex,destination vertex,and weight for each edge:\n");
for(i=0;i<E;i++){
int source,dest,weight;
scanf("%d%d%d",&source,&dest,&weight);
graph[source][dest]=weight;
graph[dest][source]=weight;
}
dijkstra(graph,0,V);
return 0;
}

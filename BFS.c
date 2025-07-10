#include<stdio.h>
#define MAX 10
void bfs(int adj[][MAX],int visited[],int start)
{
int queue[MAX],rear=-1,front=-1,i;
queue[++rear]=start;
visited[start]=1;
while(rear!=front)
{
start=queue[++front];
if(start==4)
printf("5\t");
else
printf("%c \t",start+65);
for(i=0;i<MAX;i++)
{
if(adj[start][i]==1 && visited[i]==0)
{
queue[++rear]=i;
visited[i]=1;
}
}
}
}
void main()
{
int n;
int visited[MAX]={0};
int adj[MAX][MAX],i,j;
printf("Enter the vertices:\n");
scanf("%d",&n);
printf("Enter the adjacent matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&adj[i][j]);
}
}
bfs(adj,visited,0);
}

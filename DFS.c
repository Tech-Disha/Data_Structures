#include<stdio.h>
#define MAX 10
void dfs(int adj[][MAX],int visited[],int start)
{
int stack[MAX];
int top=-1,i;
printf("%c \t",start+65);
visited[start]=1;
stack[++top]=start;
while(top!=-1)
{
start=stack[top];
for(i=0;i<MAX;i++)
{
if(adj[start][i]==1 && visited[i]==0)
{
stack[++top]=i;
printf("%c \t",i+65);
visited[i]=1;
break;
}
}
if(i==MAX)
top--;
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
dfs(adj,visited,0);
}

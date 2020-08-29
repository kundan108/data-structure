#include<stdio.h>
#include<stdlib.h>
void bfs(int [][4],int);

int status[4];
struct queue
{
    int rear;
    int arr[20];
    int front;
};
void insert(struct queue*,int);
int rem(struct queue *);
int main()
{
    int adj[4][4];
    int i,j,src;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("Is there a direct path from v[%d] to v[%d] (1 -> Yes, 0 -> No) ? : ",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter source vertex :");
    scanf("%d",&src);
    bfs(adj,src);  
}

void bfs(int adj[][4],int v)
{
    struct queue q;
    int i;
    q.rear=-1;
    q.front=0;
    insert(&q,v);
    while(q.rear >= q.front)
    {
        v=rem(&q);
        if(status[v]==0)
        {
            printf("%d\n",v);
            status[v]=1;
        }
        for(i=3;i>=0;i--)
        {
          if(adj[v][i]==1 && status[i]==0)
          {
            insert(&q,i);
          }
        }
    }
}
void insert(struct queue *p,int x)
{
    if(p->rear==20)
    {
        printf("Queue  is overflow!");
        return;
    }
    p->rear=p->rear+1;
    p->arr[p->rear]=x;
}
int rem(struct queue *p)
{
    int x;
    if(p->front > p->rear)
    {
        printf("Queue is underflow!");
        return -1;
    }
    x=p->arr[p->front];
    p->front=p->front-1;
    return x;
}
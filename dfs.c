#include<stdio.h>
#include<stdlib.h>
void dfs(int [][4],int);

int status[4];
struct stack
{
    int arr[20];
    int tos;
};
void push(struct stack*,int);
int pop(struct stack *);
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
    dfs(adj,src);  
}

void dfs(int adj[][4],int v)
{
    struct stack s;
    int i;
    s.tos=-1;
    push(&s,v);
    while(s.tos>=0)
    {
        v=pop(&s);
        if(status[v]==0)
        {
            printf("%d\n",v);
            status[v]=1;
        }
        for(i=3;i>=0;i--)
        {
          if(adj[v][i]==1 && status[i]==0)
          {
            push(&s,i);
          }
        }
    }
}
void push(struct stack *p,int x)
{
    if(p->tos==20)
    {
        printf("Stack is overflow!");
        return;
    }
    p->tos=p->tos+1;
    p->arr[p->tos]=x;
}
int pop(struct stack *p)
{
    int x;
    if(p->tos== -1)
    {
        printf("Stack is empty!");
        return -1;
    }
    x=p->arr[p->tos];
    p->tos=p->tos-1;
    return x;
}
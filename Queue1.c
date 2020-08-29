#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int arr[5];
    int front,rear;
};

void insert(struct Queue *,int);
int removes(struct Queue *);
int main()
{
    struct Queue Q;
    int i,x;
    Q.rear=-1;
    Q.front=0;
    for(i=1;i<=5;i++)
    {
        printf("\nEnter element :\n");
        scanf("%d",&x);
        insert(&Q,x);
    }
    for(i=1;i<=5;i++)
    {
        x=removes(&Q);
        if(x!=-1)
        {
            printf("\nRemove element = %d",x);
        }
    }
    return 0;
}
void insert(struct Queue *Q,int x)
{
    if(Q->rear==5)
    {
        printf("Queue is over flow\n");
        return ;
    }    
    
    
    Q->rear=Q->rear+1;
    Q->arr[Q->rear]=x;
    printf("\nInsert element : %d",x);
    
    
}
int removes(struct Queue *Q)
{
    int x;
    if(Q->front > Q->rear)
    {
        printf("Queue is underflow\n");
        return -1;
    }    
    x=Q->arr[Q->front];
    Q->front=Q->front+1; 
    return x;
}
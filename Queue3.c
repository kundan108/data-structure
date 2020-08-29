#include<stdio.h>
#include<stdlib.h>
struct cQueue
{
    int arr[5];
    int front,rear;
};

void insert(struct cQueue *,int);
int rem(struct cQueue *);

int main()
{
    struct cQueue Q;
    Q.front=-1;
    Q.rear=-1;
    int choice,x;
    do
    {
        printf("Select an option\n");
        printf("1.Insert\n2.Remove\n3.Quit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter no to Insert\n");
            scanf("%d",&x);
            insert(&Q,x);
            break;
            case 2:
            x=rem(&Q);
            if(x!=-1)
                printf("Remove element is : %d\n",x);
            break;
            case 3:
            exit(0);
            break;
            default :
            printf("Wrong choice ! Try again...");
        }
    } while (1);
    return 0;
    
}

void insert(struct cQueue *p,int x)
{
    if((p->rear==4 && p->front==0)||(p->rear+1==p->front))
    {
        printf("Queue is overflow\n");
        return ;
    }
    if(p->rear==4)
    p->rear=0;
    else
    p->rear=p->rear+1;
    p->arr[p->rear]=x;
    printf("Insert element is : %d\n",x);
    if(p->front==-1)
    p->front=0;
}

int rem(struct cQueue *p)
{
    int x;
    if(p->front==-1)
    {
        printf("Queue is underflow\n");
        return -1;
    }
    x=p->arr[p->front];
    if(p->front==p->rear)
    p->front=p->rear=-1;
    else if(p->front==4)
    p->front=0;
    else
    p->front=p->front+1;
    return x;
}

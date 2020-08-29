#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int arr[5];
    int front,rear;
};

void insert(struct Queue *,int);
int rem(struct Queue *);

int main()
{
    struct Queue Q;
    Q.front=0;
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

void insert(struct Queue *p,int x)
{
    if(p->rear==5)
    {
        printf("Queue is overflow\n");
        return ;
    }
    p->rear=p->rear+1;
    p->arr[p->rear]=x;
    printf("Insert element is : %d\n",x);
}

int rem(struct Queue *p)
{
    int x;
    if(p->front > p->rear)
    {
        printf("Queue is underflow\n");
        return -1;
    }
    x=p->arr[p->front];
    p->front=p->front+1;
    return x;
}

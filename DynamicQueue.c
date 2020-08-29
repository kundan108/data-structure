#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int data;
    struct Queue *next;
};
void Enqueue(struct Queue **,struct Queue **,int);
int rem(struct Queue **,struct Queue **);
int main()
{
    int x;
    struct Queue *rear,*front;
    rear=front=NULL;
    Enqueue(&rear,&front,10);
    Enqueue(&rear,&front,20);
    Enqueue(&rear,&front,30);
    Enqueue(&rear,&front,40);
    Enqueue(&rear,&front,50);
    Enqueue(&rear,&front,60);
    Enqueue(&rear,&front,70);
    
    x=rem(&rear,&front);
    if(x != 0)
        printf("Remove element is %d\n",x);
    x=rem(&rear,&front);
    if(x != 0)
        printf("Remove element is %d\n",x);
    x=rem(&rear,&front);
    if(x != 0)
        printf("Remove element is %d\n",x);
    x=rem(&rear,&front);
    if(x != 0)
        printf("Remove element is %d\n",x);
    x=rem(&rear,&front);
    if(x != 0)
        printf("Remove element is %d\n",x);
    x=rem(&rear,&front);
    if(x != 0)
        printf("Remove element is %d\n",x);
    x=rem(&rear,&front);
    if(x != 0)
        printf("Remove element is %d\n",x);
    x=rem(&rear,&front);
    if(x != 0)
        printf("Remove element is %d\n",x);
    return 0;
}
void Enqueue(struct Queue **pr,struct Queue **pf,int x)
{
    struct Queue *p,*temp;
    p=(struct Queue *)malloc(sizeof(struct Queue));
    p->data=x;
    p->next=NULL;
    if(*pr == NULL)
    {
        *pf=p;
    }
    else
    {
        (*pr)->next=p; 
    }
    *pr=p;
}
int rem(struct Queue **pr,struct Queue **pf)
{
    int x;
    if(*pr == NULL)
    {
        printf("Queue if empty\n");
        return 0;
    }
    x=(*pf)->data;
    if(*pf == *pr)
    {
        free(*pr);
        *pr=*pf=NULL;
        return x;
    }
    *pf=(*pf)->next;
    return x;
}
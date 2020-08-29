#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};
void push(struct Stack **,int);
int pop(struct Stack **);
int main()
{
    struct Stack *tos=NULL;
    push(&tos,10);
    push(&tos,20);
    push(&tos,30);
    push(&tos,40);
    push(&tos,50);

    printf("%d\n",pop(&tos));
    return 0;
}
void push(struct Stack **ptos,int x)
{
    struct Stack *p;
    p=(struct Stack *)malloc(sizeof(struct Stack));
    if(p==NULL)
    {
        printf("Stack Overflow");
        return ;
    }
    p->data=x;
    p->next=*ptos;
    *ptos=p;
}
int pop(struct Stack **ptos)
{
    if(*ptos == NULL)
    {
        printf("Stack is underflow\n");
        return 0;
    }
    int  x;
    struct Stack *temp;
    temp=*ptos;
    x=temp->data;
    *ptos=temp->next;
    free(temp);
    return x;
}

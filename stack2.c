#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int arr[5];
    int tos;
};

void push(struct Stack *, int);
int pop(struct Stack *);

int main()
{
    int choice,x;
    struct Stack s;
    s.tos= -1;
    do
    {
        printf("Select an option\n");
        printf("1.Push\n2.Pop\n3.Quit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter no to push :\n");
                scanf("%d",&x);
                push(&s,x);
                break;
            case 2:
                x=pop(&s);
                if(x!= -1)
                    printf("Popped ele = %d\n",x);
                break;
            case 3:
                exit(0);
            default:
                printf("Wrong choice ! Try again!\n");    
        }
    } while (1);
    
    return 0;
}
void push(struct Stack *p, int x)
{
    if(p->tos == 4)
    {
        printf("Stack overflow\n");
        return ;
    }
    p->tos = p->tos+1;
    p->arr[p->tos] = x;
}
int pop(struct Stack *p)
{
    if(p->tos == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    int x;
    x = p->arr[p->tos];
    p->tos=p->tos-1;
    return x;
}
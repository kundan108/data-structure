#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    char arr[10];
    int tos;
};
void push(struct Stack *,char);
char pop(struct Stack *);
int isoperand(char);
int isempty(struct Stack);
int precendance(char,char);
void convert(char[],char[]);

int main()
{
    char infix[20], postfix[20];
    printf("Enter a valid infix :\n");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("Postfix = %s\n",postfix);
    return 0;
}

void convert(char infix[], char postfix[])
{
    struct Stack s;
    int i,j=0;
    char ch;
    int ans;
    s.tos=-1;
    for(int i=0; infix[i]!='\0';i++)
    {
        ch=infix[i];
        if(isoperand(ch)==1)
        {
            postfix[j]=ch;
            j++;
        }
        else
        {
            while(isempty(s)==0)
            {
                ans=precendance(ch,s.arr[s.tos]);
                if(ans==1)
                break;
                else
                {
                    postfix[j]=pop(&s);
                    j++;
                }
            }
            push(&s,ch);
        }
        
    }
    while(isempty(s)==0)
    {
        postfix[j]=pop(&s);
        j++;
    }
    postfix[j]='\0';
}

int isempty(struct Stack p)
{
    if(p.tos==-1)
    return 1;
    else
    return 0;
}

int isoperand(char ch)
{
    return ((ch>=48 && ch<=57) || (ch>=65 && ch<=90) || (ch>=97 && ch<=122));
}

int precendance(char ch1, char ch2)
{
    if(ch2=='$')
    return 0;
    else if(ch1=='$')
    return 1;
    else if(ch2=='*' || ch2=='/' || ch2=='%')
    return 0;
    else if(ch1=='*' || ch1 == '/' || ch1 == '%')
    return 1;
    else 
    return 0;
}

void push(struct Stack *p,char ch)
{
    p->tos=p->tos+1;
    p->arr[p->tos]=ch;
}

char pop(struct Stack *p)
{
    char ch;
    ch=p->arr[p->tos];
    p->tos=p->tos-1;
    return ch;
}

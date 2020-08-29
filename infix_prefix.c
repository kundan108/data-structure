#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void reverse(char str[]);

int main()
{
    char infix[20], prefix[20];
    printf("Enter a valid infix :\n");
    scanf("%s",infix);
    convert(infix,prefix);
    reverse(prefix);
    printf("Prefix = %s\n",prefix);
    return 0;
}
void reverse(char str[])
{
    char temp[20];
    int len,i=0,j=0;
    len=strlen(str);
    j=len-1;
    while(j>=0)
    {
        temp[i]=str[j];
        i++,j--;
    }
    temp[i]='\0';
    strcpy(str,temp);

}

void convert(char infix[], char prefix[])
{
    struct Stack s;
    int i,j=0;
    char ch;
    int ans;
    s.tos=-1;
    for(int i=strlen(infix)-1; i>=0;i--)
    {
        ch=infix[i];
        if(isoperand(ch)==1)
        {
            prefix[j]=ch;
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
                    prefix[j]=pop(&s);
                    j++;
                }
            }
            push(&s,ch);
        }
        
    }
    while(isempty(s)==0)
    {
        prefix[j]=pop(&s);
        j++;
    }
    prefix[j]='\0';
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
    if(ch1=='$')
    return 1;
    else if(ch2=='$')
    return 0;
    else if(ch1=='*' || ch1=='/' || ch1=='%')
    return 1;
    else if(ch2=='*' || ch2 == '/' || ch2 == '%')
    return 0;
    else if(ch1=='+' || ch1=='-')
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


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Stack
{
    float arr[20];
    int tos;
};

void push(struct Stack *,float);
float pop(struct Stack *);
int isoperand(char);
float evaluate(float,float,char);
float solve(char[]);


 int main()
 {
     char postfix[20];
     float ans;
     printf("Enter a valid postfix expression\n");
     scanf("%s",postfix);
     ans=solve(postfix);
     printf("Reault is %f\n",ans);
     return 0;
 }

 float solve(char postfix[20])
 {
     struct Stack s;
     char ch;
     int i;
     float op1,op2,result;
     for(int i=0;postfix[i]!='\0';i++)
     {
         ch=postfix[i];
         if(isoperand(ch)==1)
         {
             push(&s,(float)(ch-48));
         }
         else
         {
             op2=pop(&s);
             op1=pop(&s);
             result=evaluate(op1, op2, ch);
             push(&s,result);
         }
         
     }
     result =pop(&s);
     return result;
 }

 int isoperand(char ch)
 {
     return (ch>=48 && ch<=57);
 }
 float evaluate(float a, float b, char ch)
 {
     int c;
     switch(ch)
     {
         case '+':
             c=a+b;
             break;
        case '-':
            c=a-b;
            break;
        case '*':
            c=a*b;
            break;
        case '/':
            c=a/b;
            break;
         case '%':
             c=fmod(a,b);
             break;
        case '$':
            c=pow(a,b);
        default:
            printf("Invalid Input\n");         
     }
     return c;
 }
 void push(struct Stack *p, float x)
 {
     p->tos=p->tos+1;
     p->arr[p->tos]=x;
 }
 float pop(struct Stack *p)
{
    int x;
    x = p->arr[p->tos];
    p->tos=p->tos-1;
    return x;
}
#include<stdio.h>
#include<stdlib.h>
struct Stake
{
    int arr[100];
    int tos;
};
int iscomma(char ch);
void push(struct Stake *,int);
int pop(struct Stake *);


int main()
{
    char ch[100];
    scanf("%s",ch);
    struct Stake s;
    int ans,i,a[100],count=0;
    for(i=0;i!='\0';i++)
    {
        if(iscomma(ch[i])==1)
        {
            ans = ans*10 + int(ch[i]-48);
        }
        else
        {
        push(&s,ans);
        count++;
        ans=0;
        }
    }
    for(i=0;i<count;i++)
    {
        printf("%d",pop(&s));
    }
    return 0;
}

void push(struct Stake *p, int x)
 {
     p->tos=p->tos+1;
     p->arr[p->tos]=x;
 }
 int pop(struct Stake *p)
{
    int x;
    x = p->arr[p->tos];
    p->tos=p->tos-1;
    return x;
}
int iscomma(char ch)
{
    return (ch>=48 && ch<=57);
}
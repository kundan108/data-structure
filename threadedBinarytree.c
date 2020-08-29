#include<stdio.h>
#include<stdlib.h>
struct thbt
{
    struct thbt *left;
    int data;
    struct thbt *right;
    int x;
};
void append(struct thbt** ,int);
int main()
{
    
}
void append(struct thbt **pr,int x)
{
    struct thbt *p,*temp,*prev;
    p=(struct thbt*)malloc(sizeof(struct thbt));
    p->data=x;
    if(*pr==NULL)
    {
        *pr=p;
    }
    temp=*pr;
    while(temp!=NULL)
    {
        prev=temp;
        if(temp->data>x)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if(prev->data>x)
    {
        prev->left=p;
    }
    else
    {
        prev->right=p;
    }
    
}
#include<stdio.h>
#include<stdlib.h>

struct cnode
{
    int data;
    struct cnode *next;
};
void append(struct cnode **,int);
void display(struct cnode *);
void del_first(struct cnode **);
void del_last(struct cnode **);
void del_node(struct cnode **,int);
int main()
{
    struct cnode *start = NULL;
    append(&start,10);
    append(&start,20);
    append(&start,30);
    append(&start,40);
    append(&start,50);
    display(start);
    // del_first(&start);
    // printf("After delete first node\n");
    // del_last(&start);
    // display(start);

    printf("\nEnter the data you want to delete\n");
    int n;
    scnaf("%d",&n);
    del_node(&start,n);
}

void append(struct cnode **ps,int x)
{
    struct cnode *p,*temp;
    p=(struct cnode*)malloc(sizeof(struct cnode));
    p->data = x;
    if(*ps == NULL)
    {
        *ps = p;
        p->next=p;
        return;
    }
    p->next = *ps;
    temp = *ps;
    while(temp->next != *ps)
    {
        temp=temp->next;
    }
    temp->next = p;
}

void display(struct cnode *ps)
{
    struct cnode *temp;
    if(ps == NULL)
    {
        printf("List is empty\n");
        return ;
    }
    temp = ps;
    do{
        printf("%d\n",temp->data);
        temp=temp->next;
    }while(temp != ps);
}

void del_first(struct cnode **ps)
{
    struct cnode *temp;
    if(*ps == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next == *ps)
    {
        free(*ps);
        *ps = NULL;
        return;
    }
    temp = *ps;
    while(temp->next != *ps)
    {
        temp = temp->next;
    }
    temp->next = (*ps)->next;
    free(*ps);
    *ps = temp->next;
}

void del_last(struct cnode **ps)
{
    struct cnode *temp,*p;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    if((*ps)->next == *ps)
    {
        free(*ps);
        *ps = NULL;
        return;
    }
    temp = *ps;
    p = *ps;
    while(temp->next != *ps)
    {
        p=temp;
        temp=temp->next;
    }
    free(temp);
    p->next = *ps;
}

void del_node(struct cnode **ps,int x)
{
    struct cnode *temp,*prev;
    if(*ps == NULL)
    {
        printf("List is empty\n");
        return ;
    }
    temp = *ps;
    if(temp->data == x && temp->next == temp)
    {
        free(temp);
        *ps=NULL;
        printf("there is only one node and deleted!\n");
        return;
    }
    if(temp->data == x)
    {
        while(temp->next != temp)
        {
            temp = temp->next;
        }
        temp->next = (*ps)->next;
        free(*ps);
        *ps = temp->next;
        printf("Node found at 1st position\n");
        return ;
    }
    temp = *ps;
    while(temp->data != x || temp->next !=*ps)
    {
        prev = temp;
        temp= temp->next;
    }
    if(temp->data == x)
    {
        if(temp->next = *ps)
        {
            free(temp);
            prev->next=*ps;
            printf("Last node deleted\n");
        }
        else
        {
            prev->next=temp->next;
            free(temp);
            printf("Node is deleted!\n");
        }
    }
    printf("Data is not found\n");
}

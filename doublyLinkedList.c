#include<stdio.h>
#include<stdlib.h>
struct doubly
{
    struct doubly *prev;
    int data;
    struct doubly *next;
};
void append(struct doubly **,int);
void display(struct doubly*);
void del_first(struct doubly **);
void del_last(struct doubly **);
void del_node(struct doubly **,int);

int main()
{
    struct doubly *start=NULL;
    append(&start,10);
    append(&start,20);
    append(&start,30);
    append(&start,40);
    append(&start,50);
    append(&start,60);
    append(&start,70);
    append(&start,80);
    append(&start,90);
    
    display(start);
   // del_first(&start);
    // printf("After first del called\n");
    // display(start);
    // printf("After Calling last del\n");
    // del_last(&start);
    // display(start);
    int x;
    printf("Enter data you want to delete : ");
    scanf("%d",&x);
    del_node(&start,x);
    display(start);

}

void append(struct doubly **ps,int x)
{
    struct doubly *p,*temp;
    p=(struct doubly*)malloc(sizeof(struct doubly));
    p->data=x;
    p->next=NULL;
    if(*ps == NULL)
    {
        *ps=p;;
        p->prev=NULL;
        return;
    }
    temp=*ps;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=p;
    p->prev=temp;
}

void display(struct doubly *ps)
{
    struct doubly *temp;
    if(ps == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=ps;
    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void del_first(struct doubly **ps)
{
    struct doubly *temp;
    if(*ps == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=*ps;
    if(temp->next == NULL)
    {
        free(temp);
        *ps=NULL;
        return;
    }
    *ps=temp->next;
    free(temp);
    (*ps)->prev=NULL;
}

void del_last(struct doubly **ps )
{
    struct doubly *temp;
    if(*ps == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next == NULL)
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
   temp->prev->next=NULL;
    free(temp);
}
void del_node(struct doubly **ps,int x)
{
    struct doubly *temp;
    if(*ps == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    temp=*ps;
    if(temp->next == NULL)
    {
        free(temp);
        *ps=NULL;
        printf("Node is deleted at 1st position and only one node is present\n");
        return ;
    }
    while( temp->data !=x && temp->next != NULL)
    {
        temp=temp->next;
    }
    if(temp->next == NULL && temp->data != x)
    {
    printf("Data not found\n");
    return;
    }
    if(temp->prev == NULL)
    {
        temp->next->prev=NULL;
        *ps=temp->next;
        free(temp);
        printf("Node is deleted! At 1st position \n");
        return;
    }
    temp->prev->next=temp->next;
    free(temp);
    printf("Node is deleted\n");
    return;
}
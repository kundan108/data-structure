#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void append(struct node **,int);
void display(struct node *);
int count_node(struct node*);
int search_node(struct node*,int);

int main()
{
    int x;
    struct node* start =NULL;
    append(&start,10);
    append(&start,20);
    append(&start,30);
    append(&start,40);
    append(&start,50);
    display(start);
    printf("Total number of node : %d\n",count_node(start));
    printf("Enter the number for searching : \n");
    scanf("%d",&x);
    int k = search_node(start,x);
    if(k ==1 ){
        printf("Search element is found\n");
    } else {
        printf("search element is not found\n");
    }
    return 0;
}
void append(struct node** ps,int x)
{
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if(*ps==NULL){
        *ps=p;
        return;
    }
    temp = *ps;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;
}

void display(struct node * p)
{
    if(p==NULL){
        printf("List is Empty\n");
        return ;
    }
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}
int count_node(struct node* p)
{
    int count=0;
    while(p != NULL){
        count++;
        p=p->next;
    }
    return count;
}

int search_node(struct node* p, int x)
{
    if(p ==  NULL){
        printf("List is Empty\n");
        return 0;
    }
    while( p != NULL )
    {
        if(p->data == x){
            return 1;
        }
        p=p->next;
    }
    return -1;
}

void del_first(struct node ** ps)
{
    struct node * temp;
    if(*ps == NULL){
        printf("List is Empty\n");
        return;
    }
    temp = *ps;
    *ps = temp->next;
    free(temp);
    printf("Node is deleted\n");
}
void del_last(struct node **ps)
{
    struct node* temp, *p;
    if(*ps == NULL )
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next == NULL){
        free(*ps);
        *ps = NULL;
    }
    else{
    temp = *ps;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    p = temp;
    temp = NULL;
    free(p);
    }
    printf("Last node deleted\n");
}
void del_node(struct node **ps,int x)
{
    struct node *temp,*prev;
    if((*ps)==NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *ps;
    if((*ps)->next == x)
    {
        *ps = temp->next;
        free(temp);
        printf("Node found at 1st position and deleted");
        return;
    }
    while(temp != NULL  && temp ->data != x)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Node not found\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted");
    }
}

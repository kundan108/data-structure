#include<stdio.h>
#include<stdlib.h>
struct edge
{
    char data;
    struct edge *next;
};
struct node
{
    struct node*next;
    char data;
    struct edge *enext;
};
void insertvertex(struct node**,char);
void insertedge(struct node*,char,char);
struct node* findvertex(struct node*,char);
void display(struct node*);
void remove_vertex(struct node**,char);
void remove_edge(struct node*,char,char);

int main()
{
    struct node *start=NULL;
    char src,dest,vert;
    int choice;
    do
    {
        printf("\nSelect an option:");
        printf("\n1. Add vertex:");
        printf("\n2. Insert edge:");
        printf("\n3. Display:");
        printf("\n4. Quit:");
        printf("\nEnter choice:");
        scanf("%d",&choice);
    } while (1);

    switch(choice)
    {
        case 1:
            printf("Enter vertex : ");
            fflush(stdin);
            scanf("%c",&vert);
            insertvertex(&start,vert);
            break;
        case 2:
            printf("Enter source & target Vertex:");
            fflush(stdin);
            scanf("%c %c",&src,&dest);
            insertedge(start,src,dest);
            break;
        case 3:
            display(start);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice! Try again"); 
    }
    return 0;
}
void insertvertex(struct node **ps,char ch)
{
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=ch;
    p->next=NULL;
    p->enext=NULL;
    if(*ps==NULL)
    {
        *ps=p;
        printf("Node created");
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
    printf("Node created");
    return;
}
struct node* findvertex(struct node *p,char ch)
{
    while(p!=NULL)
    {
        if(p->data==ch)
            break;
        p=p->next;
    }
    return p;
}
void insertedge(struct node *p,char src,char dest)
{
    struct node *temp;
    struct edge *e,*t;
    if(p==NULL)
    {
        printf("Cannot insert edge in an empty graph");
        return;
    }
    temp=findvertex(p,src);
    if(temp==NULL)
    {
        printf("%c is not present in the graph",src);
        return;
    }
    if(findvertex(p,dest))
    {
        printf("%c is not present in the graph",dest);
        return;
    }
    e=(struct edge*)malloc(sizeof(struct edge));
    e->data=dest;
    e->next=NULL;
    if(temp->enext==NULL)
    {
        temp->enext=e;
        return;
    }
    t=temp->enext;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=e;
}
void display(struct node* p)
{
    struct edge *e;
    if(p==NULL)
    {
        printf("Graph is empty");
        return;
    }
    while(p!=NULL)
    {
        printf("\n%c ",p->data);
        printf("-->");
        e=p->enext;
        while(e!=NULL)
        {
            printf("\t%c",e->data);
            e=e->next;
        }
        p=p->next;
    }
}
void remove_vertex(struct node **ps,char ch)
{
    if(*ps==NULL)
    {
        printf("Graph is empty");
        return;
    }
    
}
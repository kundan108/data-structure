#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void append(struct node** ,int);

int main()
{
    int ch,data;
    struct node * start=NULL;
    do{
            printf("Single list operation: \n");
            printf("1.Append\n");
            printf("2.Addatbegin\n");
            printf("3.Addatafter\n");
            printf("4.Length\n");
            printf("5.Display\n");
            printf("6.Delete\n");
            printf("7.Quit\n");
            printf("\n\nEnter your choice: ");
            scanf("%d",&ch);
    }   while(1);
    return 0;

    switch (ch)
    {
    case 1 : printf("Enter the data : ");
             scanf("%d",&data);
             append(&start,data);
             break;
    case 2 : addAtbegin();
            break;
    case 3 : addatafter();
             break;
    case 4 : length();
            break;;
    case 5 : display();
            break;
    case 6 : delete();
             break;
    case 7 : exit(1);
    default:
            printf("Invalid choice\nPlease chose another option\n");
        break;
    } 
}

void append(struct node **ps , int x)
{
    struct node *p, *temp;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->next==NULL;
    if(*ps==NULL)
    {
        *ps=p;
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
}
#include<stdio.h>
#include<stdlib.h>

struct bst
{
    struct bst *left;
    int data;
    struct bst *right;
    int x;
};
struct stack
{
    struct bst *arr[100];
    int tos;
};
void append(struct bst**, int);
void preorder(struct bst*);
void inorder(struct bst*);
void postorder(struct bst*);
void del_node(struct bst**, int);
int node_search(struct bst*, struct bst**, struct bst**,int);

int main()
{
    int x;
    struct bst *root=NULL;
    append(&root,10);
    append(&root,5);
    append(&root,8);
    append(&root,15);
    append(&root,2);
    append(&root,20);
    append(&root,25);
    printf("All the value is inserted\n");
    //preorder(root);
    //inorder(root);
   // postorder(root);

    // printf("Enter data you want to delete!\n");
    // scanf("%d",&x);
    // del_node(&root,x);
    // inorder(root);

    return 0;
}

void append(struct bst **pr,int x)
{
    struct bst *p,*temp,*prev;
    p=(struct bst*)malloc(sizeof(struct bst));
    p->data=x;
    
    p->left=p->right=NULL;
    if(*pr == NULL)
    {
        p->x=1;
        *pr=p;
        return;
    }
    temp=*pr;
    while(temp != NULL)
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
        p->x=1;

    }
    else
    {
        prev->right=p;
        p->x=-1;
    }
}
void push(struct stack *p, struct bst *x)
{
    if(x==NULL)
        return;
    
    p->tos = p->tos+1;
    p->arr[p->tos] = x;
}
struct bst* pop(struct stack *p)
{
    if(p->tos==-1)
        return NULL;
    struct bst *x;
    x = p->arr[p->tos];
    p->tos=p->tos-1;
    return x;
}

void preorder(struct bst *p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("Tree is empty");
        return;
    }
    s.tos=-1;
    push(&s,p);
    while(s.tos != -1)
    {
        p=pop(&s);
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            if(p->right != NULL)
                push(&s,p->right);
            p=p->left;
        }
    }
}

// void inorder(struct bst *p)
// {
//     struct stack s;
//     if(p==NULL)
//     {
//         printf("Tree is empty\n");
//         return;
//     }
//     s.tos=-1;
//     push_nodes:
//         while(p!=NULL)
//         {
//             push(&s,p);
//             p=p->left;
//         }
//         p=pop(&s);
//         while(p!=NULL)
//         {
//             printf("%d\n",p->data);
//             if(p->right!=NULL)
//             {
//                 p=p->right;
//                 goto push_nodes;
//             }
//             p=pop(&s);
//         }
//}

void inorder(struct bst *p)
{
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    struct stack s;
    s.tos=-1;
    push(&s,p);
    while(s.tos != -1)
    {
        p=pop(&s);
        while(p->left!=NULL)
        {
            push(&s,p);
            p=p->left;
        }
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            if(p->right != NULL)
            {
                push(&s,p->right);
                break;
            }
            p=pop(&s);
        }
    }
}

void postorder(struct bst *p)
{
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    struct stack s;
    s.tos=-1;
    push(&s,p);
    while(s.tos != -1)
    {
        p=pop(&s);
        while( p != NULL)
        {
            push(&s,p);
            if(p->right != NULL)
                push(&s,p->right);
            p=p->left;
        }
        p=pop(&s);
        while(p!=NULL)
        {
            if(p->x == 1)
            printf("%d\n",p->data);
            else 
            {
                p->x=1;
                push(&s,p);
                break;
            } 
            p=pop(&s);
        }
    }
}

int node_search(struct bst *p,struct bst **ppar,struct bst **pchild,int x)
{
    struct bst *q=NULL;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            *ppar=q;
            *pchild=p;
            return 1;
        }
        q=p;
        if(p->data>x)
            p=p->left;
        else
            p=p->right;
    }
    return 0;
}
void del_node(struct bst **pr, int x)
{
    struct bst *par,*child;
    struct bst *q;
    int result;
    if(*pr==NULL)
    {
        printf("Empty tree\n");
        return ;
    }
    result=node_search(*pr,&par,&child,x);
    if(result == 0)
    {
        printf("Node is not found!\n");
        return;
    }
    if(child->left != NULL && child->right != NULL)
    {
        q=child->right;
        par=child;
        while(q->left != NULL)
        {
            par=q;
            q=q->left;
        }
        child->data=q->data;
        child=q;
    }
    if(child->left == NULL && child->right == NULL)
    {
        if(par==NULL)
        {
            *pr=NULL;
        }
        else if(par->left == child)
            par->left=NULL;
        else
            par->right=NULL;
        free(child);
    }
    else if (child->left != NULL && child->right == NULL)
    {
        if(par==NULL)
        {
            *pr=child->left;
        }
        else if(par->right == child)
            par->right=child->left;
        else
            par->left=child->left;
        free(child);
    }
    else if(child->left==NULL && child->right != NULL)
    {
        if(par==NULL)
        {
            *pr=child->right;
        }
        else if(par->right == child)
            par->right=child->right;
        else
            par->left=child->right;
        free(child);
    }  
}
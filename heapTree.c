#include<stdio.h>
void ins_heap(int[],int,int);
int main()
{
    int arr[11];
    int i,x;
    for(i=0;i<10;i++)
    {
        printf("Enter element:\n");
        scanf("%d",&x);
        ins_heap(arr,i,x);
    }
    printf("Following is the heap\n");
    for(i=1;i<=10;i++)
    {
        printf("%d\n",arr[i]);
    }
}
void ins_heap(int arr[],int count,int x)
{
    int ptr,par;
    count++;
    ptr=count;
    while(ptr>1)
    {
        par=ptr/2;
        if(arr[par]>=x)
        {
            arr[ptr]=x;
            return;
        }
        arr[ptr]=arr[par];
        ptr=par;
    }
    arr[1]=x;
}
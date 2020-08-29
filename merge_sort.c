#include<stdio.h>
void merge_sort(int [],int ,int);
void merge(int [],int,int);
int main()
{
    int arr[]={9,8,7,6,5,4,3,2,1};
    merge_sort(arr,0,8);
    for(int i=0;i<9;i++)
    {
        printf("%d ",arr[i]);
    }
}
void merge_sort(int arr[],int first,int last)
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        merge_sort(arr,first,mid);
        merge_sort(arr,mid+1,last);
        merge(arr,first,last);
    }
}
void merge(int arr[],int first,int last)
{
    int temp[10];
    int mid,i,i1,i2,i3;
    mid=(first+last)/2;
    i1=0;
    i2=first;
    i3=mid+1;
    while(i2<=mid && i3<=last)
    {
        if(arr[i2]<arr[i3])
        {
            temp[i1]=arr[i2];
            i2=i2+1;
        }
        else
        {
            temp[i1]=arr[i3];
            i3=i3+1;
        }
        i1=i1+1;
        
    }
    if(i2<=mid)
    {
        while(i2<=mid)
        {
            temp[i1]=arr[i2];
            i2=i2+1;
            i1=i1+1;
        }
    }
    else
    {
        while(i3<=last)
        {
            temp[i1]=arr[i3];
            i1=i1+1;
            i3=i3+1;
        }
    }
    for(i=0;i<i1;i++)
    {
        arr[first+i]=temp[i];
    } 
}
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
    int mid,i,j,k;
    mid=(first+last)/2;
    i=first;
    j=mid+1;
    k=first;
   while(i<=mid && j<=last)
   {
       if(arr[i]<=arr[j])
       {
           temp[k]=arr[i];
           i++;
       }
       else
       {
           temp[k]=arr[j];
           j++;
       }
       k++;
   }
   if(i<=mid)
   {
       while(i<=mid)
       {
           temp[k]=arr[i];
           i++;
           k++;
       } 
   }
   else
   {
       while(j<=last)
       {
           temp[k]=arr[j];
           j++;
           k++;
       }
   }
   for(k=first;k<=last;k++)
   {
       arr[k]=temp[k];
   }
}

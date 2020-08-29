#include<stdio.h>
int bin_search(int arr[],int n,int x)
{
    int l=0,h=n-1,m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(arr[m]==x)
            return m;
        if(x>arr[m])
            l=m+1;
        else
            h=m-1;
    }
    return -1;
}
int main()
{
    int n,i;
    int arr[]={1,4,6,8,10,13,16,19,21,24,26};
    printf("Enter number to find its index: ");
    scanf("%d",&n);
    i=bin_search(arr,11,n);
    if(i==-1)
        printf("Number is not fond is given arr:\n");
    else
        printf("%d is the index of enter number!",i);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int choice;
    do{
        printf("\n\n*****MAIN MENU*****");
        printf("\n1: Create a list");
        printf("\n2: Display the list");
        printf("\n3: Add a node at the beginning");
        printf("\n4: Add a node at the end");
        printf("\n5: Add a node before the a given node");
        printf("\n6: Add a node after a given node");
        printf("\n7: Delete from the begininning");
        printf("\n8: Delete from the end");
        printf("\n9: Delete a given node");
        printf("\n10: Delete after a given node");
        printf("\n11: Delete the entire list");
        printf("\n12: Sort the list");
        printf("\n13: Exit");
        printf("\n**************************************");
        printf("\n\n Enter your option: ");
        scanf("%d",&choice);
    } while(1);
    return 0;
}
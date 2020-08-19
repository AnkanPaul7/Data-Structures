/*
   This program shows the implementation of the Singly Linked List data structure in C
   Author - Rajarshi Sengupta
   Github - https://github.com/rajarshisg
   Date - 19/08/2020 (dd/mm/yyyy)
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
int main()
{
    printf("Enter the number of nodes you want :\n");
    int num;
    scanf("%d",&num);
     Node *head=NULL;
     Node *n=NULL;
     Node *m=NULL;
    printf("Enter the elements :\n");
    for(int i=0;i<num;i++)
    {
        if(head==NULL){
            n=(int *)malloc(sizeof( Node));
            scanf("%d",&n->data);
            n->next=NULL;
            head=n;
        }
        else
        {
           m=(int *)malloc(sizeof(Node));
           scanf("%d",&m->data);
           m->next=NULL;
           n->next=m;
           n=n->next;
        } 
    }
    printf("The Linked List is :\n");
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    return 0;
}
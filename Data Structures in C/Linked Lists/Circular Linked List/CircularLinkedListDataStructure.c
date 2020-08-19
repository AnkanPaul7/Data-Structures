/*
   This program shows the implementation of the Circular Linked List data structure in C
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
    int num;
    printf("Enter the number of nodes :\n");
    scanf("%d",&num);
    Node *head=NULL;
    Node *n=NULL;
    Node *m=NULL;
    printf("Enter the elements :\n");
    for(int i=1;i<=num;i++)
    {
        if(head==NULL)
        {
            n=(Node *)malloc(sizeof(Node));
            scanf("%d",&n->data);
            n->next=NULL;
            head=n;
        }
        else
        {
            m=(Node *)malloc(sizeof(Node));
            scanf("%d",&m->data);
            m->next=NULL;
            n->next=m;
            n=m;
        }
        if(i==num)
        n->next=head;
    }
    printf("The Linked List is :\n");
    Node *curr=head;
    do
    {
        printf("%d ",curr->data);
        curr=curr->next;
    } while(curr!=head);
    return 0;
}
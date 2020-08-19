/*
   This program shows how to delete a node at the begining and at the end of a Circular Linked List using C
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
Node *deleteBegining(Node *head)
{
    if(head==NULL)
    return NULL;
     Node *tail=head;
    while(tail->next!=head)
    {
       tail=tail->next;
    }
    Node *n=head;
    tail->next=n->next;
    head=n->next;
    free(n);
   return head;
}
Node *deleteEnd(Node *head)
{
    if(head==NULL)
    return NULL;
    Node *curr=head;
    Node *tail=head;
    while(curr->next->next!=head)
    {
       curr=curr->next;
       tail=curr->next;
    }
    curr->next=head;
    free(tail);
    return head;
}
void traverse(Node *head)
{
     Node *curr=head;
    do
    {
        printf("%d ",curr->data);
        curr=curr->next;
    } while(curr!=head);
    printf("\n");
}
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
    traverse(head);
    printf("Deleteing node at first position...\n");
    head=deleteBegining(head);
    traverse(head);
    printf("Deleteing node at last position...\n");
    head=deleteEnd(head);
    traverse(head);
    return 0;
}
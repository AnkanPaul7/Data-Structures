/*
   This program shows how to insert a node at the begining and at the end of a Circular Linked List using C
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
Node *insertBegining(Node *head,int data)
{
    Node *n=(Node *)malloc(sizeof(Node));
    n->data=data;
    n->next=n;
    if(head==NULL)
    return n;
     Node *tail=head;
    while(tail->next!=head)
    {
       tail=tail->next;
    }
     n->next=head;
     tail->next=n;
     head=n; 
   return head;
}
Node *insertEnd(Node *head,int d)
{
    Node *n=(Node *)malloc(sizeof(Node));
    n->data=d;
    n->next=n;
    if(head==NULL)
    return n;
     Node *curr=head;
    while(curr->next!=head)
    {
       curr=curr->next;
    }
    curr->next=n;
    n->next=head;
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
    printf("Enter the data you want to insert at begining :\n");
    int data;
    scanf("%d",&data);
    head=insertBegining(head,data);
    traverse(head);
    printf("Enter the data you want to insert at end :\n");
    int d;
    scanf("%d",&d);
    head=insertEnd(head,d);
    traverse(head);
    return 0;
}
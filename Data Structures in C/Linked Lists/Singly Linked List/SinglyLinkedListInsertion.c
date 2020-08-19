/*
   This program shows how to insert a node at any position in a Singly Linked List data structure in C
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
Node *insert(Node *head,int data,int pos)
{
    Node *h=head;
    Node *n=(Node *)malloc(sizeof(Node));
    n->data=data;
    if(pos==1 || head==NULL)
    {
        n->next=head;
        head=n;
    }
    else
    {
         int k=1;
         while(k!=pos-1 && h->next!=NULL)
         {
             h=h->next;
             k++;
         }
         n->next=h->next;
         h->next=n;
         h=h->next;
    }
    return head;
}
void traverse(Node *head)
{
     while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
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
           n=n->next;
        } 
    }
    printf("The Linked List is :\n");
    traverse(head);
    printf("Enter the data you want to enter and it's position :\n");
    int d,pos;
    scanf("%d%d",&d,&pos);
    head=insert(head,d,pos);
    printf("After insertion new Linked List is :\n");
    traverse(head);
    return 0;
}
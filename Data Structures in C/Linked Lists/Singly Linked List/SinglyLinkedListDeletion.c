/*
   This program shows how to delete any node of a Singly Linked List data structure in C
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
Node *delete(Node *head,int pos)
{
    if(head==NULL)
    return NULL;
    Node *n,*p;
    n=head;
    if(pos==1)
    {
      
        head=head->next;
        free(n);
    }
    else
    {
        int k=1;
        while(n!=NULL && k<pos-1)
        {
            n=n->next;
            k++;
        }
        if(n==NULL)
        return head;
        p=n->next;
        n->next=p->next;
        free(p);
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
    printf("Enter position you want to delete :\n");
    int pos;
    scanf("%d",&pos);
    head=delete(head,pos);
    printf("After deletion new Linked List is :\n");
    traverse(head);
    return 0;
}
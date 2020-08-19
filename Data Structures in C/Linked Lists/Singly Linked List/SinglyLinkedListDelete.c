/*
   This program shows how to delete a Singly Linked List  in C
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
Node *deleteLL(Node *head)
{
    Node *p,*n;
    p=head;
    while(p!=NULL)
    {
        n=p->next;
        free(p);
        p=n;
    }
    head=NULL;
    return head;
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
    head=deleteLL(head);
    if(head==NULL)
    printf("Deletion successfull");
    else
    printf("Unsuccessfull deletion");
    
    return 0;
}
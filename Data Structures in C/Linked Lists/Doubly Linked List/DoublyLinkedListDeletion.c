#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node* delete(Node *head,int pos)
{
    if(head==NULL)
    return NULL;
    Node *h=head;
    Node *n=NULL;
    if(pos==1)
    {
       n=h;
       h=h->next;
       h->prev=NULL;
       free(n);
       head=h;
    }
    else
    {
        int k=1;
        while(h!=NULL && k<=pos-1){
            h=h->next;
            k++;
        }
        if(h==NULL)
        return head;
        else{
        n=h;
        h->prev->next=h->next;
        if(h->next!=NULL)
        h->next->prev=h->prev;
        free(n);
        }
    }
    return head;
}
void traverse(Node *head)
{
    Node *p;
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
        if(head!=NULL)
        p=head;
    }
    printf("\nThe elements in reverse order :\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->prev;
    }
    printf("\n");
}
int main()
{
    printf("Enter the number of elements you want to enter :\n");
    int num;
    scanf("%d",&num);
    Node *head=NULL;
    Node *p=NULL;
    Node *n=NULL;
    printf("Enter the elements :\n");
    for(int i=0;i<num;i++)
    {
        if(head==NULL)
        {
            p=(Node *)malloc(sizeof(Node));
            scanf("%d",&p->data);
            p->prev=NULL;
            p->next=NULL;
            head=p;
        }
        else
        {
            n=(Node *)malloc(sizeof(Node));
            scanf("%d",&n->data);
            n->next=NULL;
            n->prev=p;
            p->next=n;
            p=n;
        }
        
    }
    printf("The elements are :\n");
    traverse(head);
    printf("Enter the position of the element you want to delete :\n");
    int pos;
    scanf("%d",&pos);
    head=delete(head,pos);
    printf("After insertion new Linked List is :\n");
    traverse(head);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node* insert(Node *head,int data,int pos)
{
    Node *n=(Node *)malloc(sizeof(Node));
    n->data=data;
    n->next=NULL;
    n->prev=NULL;
    Node *h=head;
    if(pos==1 || head==NULL)
    {
        n->next=h;
        if(head!=NULL)
        h->prev=n;
        head=n;
    }
    else
    {
        int k=1;
        while(h->next!=NULL && k!=pos-1){
            h=h->next;
            k++;
        }
        if(h->next==NULL)
        {
            h->next=n;
            n->prev=h;
        }
        else{
        n->next=h->next;
        h->next->prev=n;
        h->next=n;
        n->prev=h;
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
    printf("Enter the data you want to enter and it's position :\n");
    int d,pos;
    scanf("%d%d",&d,&pos);
    head=insert(head,d,pos);
    printf("After insertion new Linked List is :\n");
    traverse(head);
    return 0;
}
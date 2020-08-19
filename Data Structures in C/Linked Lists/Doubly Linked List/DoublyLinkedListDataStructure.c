#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
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
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\nThe elements in reverse order :\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->prev;
    }
    return;
}
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node *createList(){
  printf("Enter the number of nodes you want :\n");
  int num;
  scanf("%d",&num);
  Node *head=NULL,*n=NULL,*m=NULL;
  printf("Enter the elements of the linked list :\n");
  for(int i=1;i<=num;i++){
      if(head==NULL){
          n=(Node *)malloc(sizeof(Node));
          scanf("%d",&n->data);
          n->next=NULL;
          head=n;
      }
      else{
          m=(Node *)malloc(sizeof(Node));
          scanf("%d",&m->data);
          m->next=NULL;
          n->next=m;
          n=m;
      }
    }
    return head;
}
void traverse(Node *head){
    printf("The linked list is :\n");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void swap(Node **head,int x,int y){
    if(x==y)
    return;
    Node *currX=*head,*currY=*head,*prevY=NULL,*prevX=NULL,*n=*head;
    while(currX!=NULL && currX->data!=x){
        prevX=currX;
        currX=currX->next;
    }
    while(currY!=NULL && currY->data!=y){
        prevY=currY;
        currY=currY->next;
    }
    if(currX==NULL || currY==NULL)
    return;
    if(currX==*head){
        n=currY;
    }else{
        prevX->next=currY;
    }
    if(currY==*head){
        n=currX;
    }else{
        prevY->next=currX;
    }
    Node *tmp=currX->next;
    currX->next=currY->next;
    currY->next=tmp;
    *head=n;
}
int main(){
    Node *head=createList();
    printf("Enter the value of the nodes you want to swap :\n");
    int x,y;
    scanf("%d%d",&x,&y);
    swap(&head,x,y);
    traverse(head);
}

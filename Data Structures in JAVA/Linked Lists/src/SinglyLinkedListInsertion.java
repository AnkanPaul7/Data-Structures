/*
   This program inserts a node at any given position in a Singly Linked List in JAVA
   Author - Rajarshi Sengupta
   Github - https://github.com/rajarshisg
   Date - 20/08/2020 (dd/mm/yyyy)
*/
import java.util.Scanner;
public class SinglyLinkedListInsertion {
    void traverse(Node<Integer> head) {
    	while(head!=null)
    	{
           System.out.print(head.data+" ");
           head=head.next;
    	}
    	System.out.println();
    }
    Node<Integer> insert(Node<Integer> head,int data,int pos)
    {
    	Node<Integer> n=new Node<Integer>(data);
    	if(pos==1 || head==null)
    	{
    		n.next=head;
    		head=n;
    	}
    	else
    	{
    		int k=1;
    		Node<Integer> h=head;
    		while(k!=pos-1 && h.next!=null) {
    			h=h.next;
    			k++;
    		}
    		n.next=h.next;
    		h.next=n;
    	}
    	return head;
    }
    public static void main(String args[]) {
       Scanner sc=new Scanner(System.in);
 	   Node<Integer> head=null,n=null,m=null;
 	   System.out.println("Enter the number of nodes :");
 	   int num=sc.nextInt();
 	   System.out.println("Enter the elements :");
 	   for(int i=1;i<=num;i++)
 	   {
 		   if(head==null)
 		   {
 			   n=new Node(sc.nextInt());
 			   head=n;
 		   }
 		   else
 		   {
 			   m=new Node(sc.nextInt());
 			   n.next=m;
 			   n=n.next;
 		   }
 	   }
 	   System.out.println("The Linked List is :");
 	   SinglyLinkedListInsertion obj=new SinglyLinkedListInsertion();
 	   obj.traverse(head);
 	   System.out.println("Enter the data and the position you want to insert it at :");
 	   int data=sc.nextInt();
 	   int pos=sc.nextInt();
 	   head=obj.insert(head,data,pos);
 	   System.out.println("The Linked List is :");
	   obj.traverse(head);
    }
}

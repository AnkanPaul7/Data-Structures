/*
   This program shows how insert a node at the begining and end in a Circular Linked List in JAVA
   Author - Rajarshi Sengupta
   Github - https://github.com/rajarshisg
   Date - 20/08/2020 (dd/mm/yyyy)
   
   
   Node class definition :
   public class Node<T> {
   T data;
   Node next;
   Node(T data){
	   this.data=data;
	   this.next=null;
   }
   
}

*/
import java.util.Scanner;
public class CircularLinkedListInsertion {
	Node insertBegining(Node<Integer> head,int data) {
		Node<Integer> n=new Node<Integer>(data);
		Node<Integer> tail=head;
	    while(tail.next!=head)
	    	tail=tail.next;
		n.next=head;
		tail.next=n;
		head=n;
		return head;
	}
	Node insertEnd(Node<Integer> head,int data) {
		Node<Integer> n=new Node<Integer>(data);
		Node<Integer> tail=head;
	    while(tail.next!=head)
	    	tail=tail.next;
		n.next=head;
		tail.next=n;
		return head;
	}
	void traverse(Node<Integer> head) {
		 System.out.println("The Linked List is :");
		   Node curr=head;
		   do
		   {
			   System.out.print(curr.data+" ");
			   curr=curr.next;
		   }while(curr!=head);
		   System.out.println();
	}
   public static void main(String args[])
   {
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
	   n.next=head; //last node points to first
	   CircularLinkedListInsertion obj=new CircularLinkedListInsertion();
	   obj.traverse(head);
	   System.out.println("Enter the node you want to insert at begining :");
	   int data=sc.nextInt();
	   head=obj.insertBegining(head,data);
	   obj.traverse(head);
	   System.out.println("Enter the node you want to insert at end :");
	   data=sc.nextInt();
	   head=obj.insertEnd(head,data);
	   obj.traverse(head);
   }
}

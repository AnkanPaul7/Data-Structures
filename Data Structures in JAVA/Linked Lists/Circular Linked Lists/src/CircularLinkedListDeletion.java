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
public class CircularLinkedListDeletion {
	Node deleteBegining(Node<Integer> head) {
		Node<Integer> tail=head;
	    while(tail.next!=head)
	    	tail=tail.next;
		tail.next=head.next;
		Node<Integer> n=head;
		n=null;
		head=tail.next;
		return head;
	}
	Node deleteEnd(Node<Integer> head) {
		Node<Integer> tail=head;
	    while(tail.next.next!=head)
	    	tail=tail.next;
	    Node<Integer> n=tail.next;
		tail.next=head;
		n=null;
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
	   CircularLinkedListDeletion obj=new CircularLinkedListDeletion();
	   obj.traverse(head);
	   System.out.println("Deleting the first node...");
	   head=obj.deleteBegining(head);
	   obj.traverse(head);
	   System.out.println("Deleting the last node...");
	   head=obj.deleteEnd(head);
	   obj.traverse(head);
   }
}

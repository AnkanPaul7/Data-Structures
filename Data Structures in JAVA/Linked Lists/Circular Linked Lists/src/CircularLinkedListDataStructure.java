/*
   This program shows how to create and display a Circular Linked List in JAVA
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
public class CircularLinkedListDataStructure {
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
	   n.next=head;
	   System.out.println("The Linked List is :");
	   Node curr=head;
	   do
	   {
		   System.out.print(curr.data+" ");
		   curr=curr.next;
	   }while(curr!=head);
   }
}

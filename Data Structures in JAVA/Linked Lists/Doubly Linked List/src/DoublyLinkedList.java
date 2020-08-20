/*This program shows the implementation of a Doubly Linked List Data Structure in JAVA
 * Author - Rajarshi Sengupta
   Github - https://github.com/rajarshisg
   Date - 20/08/2020 (dd/mm/yyyy)
   
   
   Node class definition :
   public class Node<T> {
     T data;
     Node prev;
     Node next;
     Node(T data)
     {
    	 this.data=data;
    	 this.prev=null;
    	 this.next=null;
     }
}

 */
import java.util.Scanner;
public class DoublyLinkedList {
   public static void main(String args[]) {
	   Scanner sc=new Scanner(System.in);
	   System.out.println("Enter the number of nodes you want :");
	   int num=sc.nextInt();
	   Node<Integer> head=null,n=null,m=null;
	   System.out.println("Enter the elements :");
	   for(int i=1;i<=num;i++)
	   {
		   if(head==null) {
			   n=new Node<Integer>(sc.nextInt());
			   head=n;
		   }
		   else
		   {
			   m=new Node<Integer>(sc.nextInt());
			   n.next=m;
			   m.prev=n;
			   n=m;
		   }
	   }
	   System.out.println("The Doubly Linked List :");
	   Node h=null;
	   while(head!=null)
	   {
		   h=head;
		   System.out.print(head.data+" ");
		   head=head.next;
	   }
	   System.out.println();
	   System.out.println("The Doubly Linked List in reverse order :");
	   while(h!=null) {
		   System.out.print(h.data+" ");
		   h=h.prev;
	   }
	   System.out.println();
   }
}

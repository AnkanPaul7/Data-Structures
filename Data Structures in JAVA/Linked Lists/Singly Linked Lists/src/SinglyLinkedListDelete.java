/*
   This program deletes a Singly Linked List in JAVA
   Author - Rajarshi Sengupta
   Github - https://github.com/rajarshisg
   Date - 20/08/2020 (dd/mm/yyyy)
*/
import java.util.Scanner;
public class SinglyLinkedListDelete {
	void traverse(Node<Integer> head) {
    	while(head!=null)
    	{
           System.out.print(head.data+" ");
           head=head.next;
    	}
    	System.out.println();
    }
    Node<Integer> deleteLL(Node<Integer> head)
    {
    	Node n=head;
    	while(head!=null) {
    		head=head.next;
    		n=null;
    		n=head;
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
 	   SinglyLinkedListDelete obj=new SinglyLinkedListDelete();
 	   obj.traverse(head);
 	   head=obj.deleteLL(head);
 	   if(head==null)
 		   System.out.println("Deletion successfull");
 	   else
 		  System.out.println("Deletion unsuccessfull");
    }
}

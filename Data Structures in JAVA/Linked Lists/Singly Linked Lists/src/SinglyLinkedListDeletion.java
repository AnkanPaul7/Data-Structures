/*
   This program deletes a node at any given position in a Singly Linked List in JAVA
   Author - Rajarshi Sengupta
   Github - https://github.com/rajarshisg
   Date - 20/08/2020 (dd/mm/yyyy)
*/
import java.util.Scanner;
public class SinglyLinkedListDeletion {
	void traverse(Node<Integer> head) {
    	while(head!=null)
    	{
           System.out.print(head.data+" ");
           head=head.next;
    	}
    	System.out.println();
    }
    Node<Integer> delete(Node<Integer> head,int pos)
    {
    	if(head==null)
    		return null;
    	if(pos==1)
    	{
    		Node n=head;
    		head=head.next;
    		n=null;
    	}
    	else
    	{
    		int k=1;
    		Node<Integer> h=head;
    		while(k!=pos-1 && h.next!=null) {
    			h=h.next;
    			k++;
    		}
    		if(h.next!=null) {
    		Node n=h.next;
    		h.next=n.next;
    		n=null;
    		}
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
 	   SinglyLinkedListDeletion obj=new SinglyLinkedListDeletion();
 	   obj.traverse(head);
 	   System.out.println("Enter position you want to delete :");
 	   int pos=sc.nextInt();
 	   head=obj.delete(head,pos);
 	   System.out.println("The Linked List is :");
	   obj.traverse(head);
    }
}

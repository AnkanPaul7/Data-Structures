/*
   This program inserts a node at any given position in a Doubly Linked List in JAVA
   Author - Rajarshi Sengupta
   Github - https://github.com/rajarshisg
   Date - 20/08/2020 (dd/mm/yyyy)
*/
import java.util.Scanner;
public class DoublyLinkedListInsertion {
    Node insert(Node head,int data,int pos)
    {
    	Node n=new Node(data);
    	Node h=head;
    	if(pos==1 || head==null)
    	{
    		n.next=head;
    		n.prev=null;
    		head.prev=n;
    		head=n;
    		
    	}
    	else
    	{
    		int k=1;
    		while(k!=pos-1 && h.next!=null) {
    			h=h.next;
    			k++;
    		}
    		
    		n.next=h.next;
    		if(h.next!=null)
    		h.next.prev=n;
    		h.next=n;
    		n.prev=h;
    	}
    	return head;
 }
    void traverse(Node head) {
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
        else{
    	    m=new Node<Integer>(sc.nextInt());
    	    n.next=m;
    	    m.prev=n;
    	    n=m;
    	 }
      }
     DoublyLinkedListInsertion ob=new DoublyLinkedListInsertion();
     ob.traverse(head);  
     System.out.println("Enter the data and the position you want to enter it at :");
     int data=sc.nextInt();
     int pos=sc.nextInt();
     head=ob.insert(head,data,pos);
     ob.traverse(head);
    }

}

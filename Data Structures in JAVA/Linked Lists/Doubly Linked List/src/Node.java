/*
   This code represents a single node of the Doubly Linked List data structure in JAVA
   Author - Rajarshi Sengupta
   Github - https://github.com/rajarshisg
   Date - 20/08/2020 (dd/mm/yyyy)
*/
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

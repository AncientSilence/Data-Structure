/*Implement a Linked List in Java*/
public class SinglyLinkedList<E>{

	public static class Node<E>{ 
		//Why static node ? "Instances of static nested classes have no reference to an instance of the nesting class"
		//"Non-static nested classsed however require an instance of the nesting class to be created and instances are bound to that instance and have access to it's fields."
		//Source: https://stackoverflow.com/questions/41438392/why-class-node-in-linkedlist-defined-as-static-but-not-normal-class
		E item;
		Node<E> next;
		
		public Node(E item){
			this.item = item;
			this.next = null;
		}
	}
	
	private Node<E> head;
	private int size;
	
	//Constructor
	public SinglyLinkedList(){
		this.head = null;
		this.size = 0;
	}
	
	public E get(int index){
		return null;
	}
	
	public void set(int index){
		
	}
	public Node get_node(int index){
		return null;
	}
	public int get_size(){
		return this.size;
	}
	
	public int exists(){
		return -1;
	}
	public void add(E item){
		
	}
	
	public void add(int index, E item){
		
	}
	
	public E remove(int index){
		return null;
	}
	
	public E remove(){
		return null;
	}
	
	public String to_string(){
		return "";
	}
	

	public static void main(String [] args){
		
	}
}
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
	
	public Node<E> get_head(){
		return this.head;
	}
	
	public Node<E> get_node(int index){
		Node<E> temp = this.head;
		for(int i = 0; i < index; i++){
			temp = temp.next;
		}
		return temp;
	}
	
	public E get(int index){
		if(index < 0 || index > this.size){
			throw new IndexOutOfBoundsException("Invalid index");
		}
		return this.get_node(index).item;
	}
	
	public void set(int index, E item){
		if(index < 0 || index > this.size){
			throw new IndexOutOfBoundsException("Invalid index");
		}
		this.get_node(index).item = item;
	}
	
	public int get_size(){
		return this.size;
	}
	
	public int exists(E item){
		Node<E> temp = this.head;
		int index = 0;
		while(temp != null){
			if(temp.item.equals(item)){
				return index;
			}
			++index;
			temp = temp.next;
		}
		
		return -1;
	}
	
	public void add(int index, E item){
		if(index < 0 || index > this.size){
			throw new IndexOutOfBoundsException("Index is out of bound");
		}
		Node<E> holder = new Node<>(item);
		if(this.size == 0){
			holder.next = this.head;
			this.head = holder;
		}else{
			Node<E> before = this.get_node(index - 1);
			holder.next = before.next;
			before.next = holder;
		}
		this.size++;
	}
	
	public void add(E item){
		this.add(this.size, item);
	}
	
	
	public E remove(int index){
		if(index < 0 || this.size == 0 || index > this.size){
			throw new IndexOutOfBoundsException("Index is out of bound or list is empty");
		}
		E to_return = this.get(index);
		
		if(index == 0){
			head = head.next;
		}else{
			Node<E> before = this.get_node(index - 1);
			before.next = before.next.next;
		}
		
		this.size--;
		return to_return;
	}
	public E remove(E item){
		int index = this.exists(item);
		if(index != -1){
			E to_return = this.get(index);
			this.remove(index);
			return to_return;
		}else{
			return null;
		}
		
	}
	public E remove(){
		return this.remove(this.size - 1);
	}
	
	public String to_string(){
		StringBuilder sb = new StringBuilder();
		Node<E> temp = this.head;
		while(temp != null){
			sb.append(temp.item).append("-->");;
			temp = temp.next;
		}
	    sb.append("Null");
		return sb.toString();
	}
	

	public static void main(String [] args){
		Node<Integer> node = new Node<>(1);
		SinglyLinkedList<Integer> foo = new SinglyLinkedList<>();
		foo.add(1);
		foo.add(3);
		foo.add(4);
		foo.remove();
		
		
		System.out.println(foo.to_string());
		
	}
}
public class DoublyLinkedList<E>{
	
	public static class Node<E>{
		E data;
		Node<E> next;
		Node<E> prev;
		public Node(E data){
			this.data = data;
			this.next = null;
			this.prev = null;
		}
	}
	//Properties of Doubly Linked List
	Node<E> head;
	Node<E> tail;
	int size;
	
	public DoublyLinkedList(){
		this.head = this.tail = null;
		this.size = 0;
	}
	
	public int get_size(){
		return this.size;
	}
	public Node<E> get_head(){
		return this.head;		
	}
	
	public Node<E> get_tail(){
		return this.tail;
	}
	
	public Node<E> get_node(int index){
		if(index < 0 || index >= this.size){
			throw new IndexOutOfBoundsException("Invalid Index");
		}
		Node<E> current = this.head;
		for(int i = 0 ; i < index && current != null; i++){
			current = current.next;
		}
		return current;
	}
	
	public void add(int index, E item){
		//Case 1 : Invalid index
		//Case 2: Add to an empty list
		//Case 3: Add to the head
		//Case 4: Add to the tail
		//Case 5: Add to any position in the list
		if(index < 0 || index > this.size){
			throw new IndexOutOfBoundsException("Invalid Index");
		}
		Node<E> holder = new Node<>(item);
		if(this.size == 0){
			this.head = holder;
			this.tail = holder;
			
		}else if(index == 0){
			holder.next = this.head;
			this.tail.prev = holder;
			this.head = holder;
		}else if(index == this.size - 1){
			this.tail.next = holder;
			holder.prev = tail;
		    this.tail = holder;
		}else{
			Node<E> before = this.get_node(index - 1);
			holder.next = before.next;
			before.next.prev = holder;
			holder.prev = before;
			before.next = holder;
			
		}
		this.size++;
	}
	
	public void append_to_head(E item){
		
	}
	
	public void append_to_tail(E item){
	}
	
	public int search(E item){
		return -1;
	}
	
	public E remove(int index){
		if(index < 0 || index >= this.size){
			throw new IndexOutOfBoundsException("Invalid Index");
		}
		return null;
	}
	
	public E remove(E item){
		return null;
	}
	
	public String to_string(){
		StringBuilder sb = new StringBuilder();
		Node<E> current = this.head;
		while(current != null){
			sb.append(current.data).append("<-->");
			current = current.next;
		}
		sb.append("NULL");
		return sb.toString();
	}
	
	public static void main(String [] args){
		System.out.println("Doubly Linked List Compiled");
		DoublyLinkedList<Character> dl = new DoublyLinkedList<>();
		dl.add(0, 'a');
		dl.add(0, 'b');
		dl.add(1, 's');
		dl.add(2, 'd');
		dl.add(2, 'e');
		dl.add(2, 'r');
		System.out.println(dl.to_string());
	}
}
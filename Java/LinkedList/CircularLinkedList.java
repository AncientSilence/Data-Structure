public class CircularLinkedList<E>{
	
	static class CNode<E> {
		private CNode<E> next;
		private E data;
		
		public CNode(E data){
			this.next = null;
			this.data = data;
		}
		public String to_string(){
			StringBuilder sb = new StringBuilder();
			sb.append("Data: ").append(this.data).append("\n").append("Next Node Address: ").append(this.next).append("\n");
			return sb.toString();
		}
		
	}
	//properties of Circular Linked List
	private CNode<E> head;
	private CNode<E> tail;
	private int size;
	
	//Constructor
	public CircularLinkedList(){
		this.head = null;
		this.tail = null;
		this.size = 0;
	}
	public int get_size(){
		return this.size;
	}
	public CNode<E> get_node(int index){
		if(index < 0 || index >= this.size){
			throw new IndexOutOfBoundsException("Invalid Index");
		}
		CNode<E> current = this.head;
		if(index == 0){
			return current;
		}else if(index == this.size - 1){
			return this.tail;
		}else{
			for(int i = 0 ; i < index; i++){
				current = current.next;
			}
		}
		return current;
		
	}
	public boolean is_empty(){
		return this.size == 0;
	}
	public int index_of(E item){ //assume E item implemented equals methods
		for(int i  = 0; i < this.size; i++){
			if(this.get_node(i).data.equals(item)){
				return i;
			}
		}
		return -1;
	}
	public void add(int index, E item){
		//Case 1: Invalid index
		//Case 2: Add to an empty list
		//Case 3: Add to the head of the list
		//Case 4: Add to the tail of the list
		//Case 5: Add to any place between the head and tail
		if(index < 0 || index > this.size){
			throw new IndexOutOfBoundsException("Invalid Index");
		}
		CNode<E> holder = new CNode<>(item);
		if(this.size == 0){
			this.head = this.tail = holder;
		}else if(index == 0){
			holder.next = this.head;
			this.tail.next = holder;
			this.head = holder;
		}else if(index == size){
			holder.next = head;
			this.tail.next = holder;
			this.tail = holder;
		}else{
			CNode<E> before = this.get_node(index - 1);
			holder.next = before.next;
			before.next = holder;
		}
		
		this.size++;
	}
	
	public void add(E item){
		this.add(this.size, item);
	}
	
	public E remove(int index){
		//Case 1: Invalid index
		//Case 2: Remove the last item in this list
		//Case 3: Remove the head
		//Case 4: Remove the tail
		//Case 5: Remove any item between the head and tail
		if(index < 0 || index >= this.size){
			throw new IndexOutOfBoundsException("Invalid Index");
		}
		E item = this.get_node(index).data;
		if(this.size == 1){
			this.head = this.tail = null;
		}else if(index == 0){
			this.head = this.head.next;
			this.tail.next = head;
		}else if(index == this.size - 1){
			CNode<E> before_tail = this.get_node(this.size - 2);
			before_tail.next = this.head;
			this.tail = before_tail;	
		}else{
			CNode<E> before = this.get_node(index - 1);
			before = before.next;
		}
		this.size--;
		return item;
	}
	
	public E remove(E item){
		int index_to_remove = this.index_of(item);
		if( index_to_remove!= -1){
			return this.remove(index_to_remove);
		}else if(index_to_remove == -1){
			throw new IndexOutOfBoundsException("Item not found!");
		}
		return null;
	
	}
	
	public E pop(){
		return this.remove(this.size - 1);
	}
	
	public String to_string(){
		CNode<E> current = this.head;
		StringBuilder sb = new StringBuilder();
		while(current.next != this.head){
			sb.append(current.data).append("-->");
			current = current.next;
		}
		sb.append(this.tail.data).append("-->");
		sb.append(this.head.data);
		return sb.toString();
	}
	
	public static void main(String [] args){
		CircularLinkedList<String> clist = new CircularLinkedList<>();
		clist.add("a");
		clist.add("b");
		clist.add("c");
		clist.add("c");
		clist.add("d");
		clist.add("f");
		System.out.println(clist.to_string());
		clist.remove(clist.get_size() - 1); //remove tail
		clist.remove(0); //remove head
		clist.remove("c"); //search remove
		System.out.println(clist.to_string());
		
	}
}
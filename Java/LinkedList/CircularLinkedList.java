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
	public Node<E> get_node(int index){
		if(index < 0 || index >= this.size){
			throw new IndexOutOfBoundsException("Invalid Index");
		}
		
		
	}
	public void add(int index, E item){
		
	}
	
	public String to_string(){
		CNode<E> current = this.head;
		StringBuilder sb = new StringBuilder();
		while(current.next != this.head){
			sb.append(current.data).append("-->");
			current = current.next;
		}
		sb.append(this.head.data);
		return sb.toString();
	}
}
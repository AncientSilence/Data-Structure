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
template<class T>struct DNode{
	T data;
	struct DNode * next;
	struct DNode * prev;
	public:
		DNode(T item){
			this->data = item;
			this->next = nullptr;
			this->prev = nullptr;
		}
	    ~DNode(){
			delete next;
			delete prev;
		}
	
};

template<class T> struct DoublyLinkedList{
	
	private:
		DNode<T> * head;
		DNode<T> * tail;
		int size;
	
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		DNode<T> * get_head();
		DNode<T> * get_tail();
		T get(int index);
		int get_size();
		DNode<T> * get_node(int index);
		void add(int index, T item);
		void add(T item);
		int search(T item);
		T remove(int index);
		T remove(T item);
		T remove();
		void append_to_head(T item);
		void remove_at_head();
		void print();
	
	
};
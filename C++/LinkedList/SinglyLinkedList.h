template<class T>struct Node{
	T data;
	struct Node * next;
	
	public:
		Node(T item){
			this->data = item;
			this->next = nullptr;
		}
		~Node(){
			delete next;
		};
	
};

template<class T>struct SinglyLinkedList{
	private:
		int size;
		Node<T> * head;
		
	public:
	    SinglyLinkedList();
		~SinglyLinkedList();
		void set(int index, T item);
		T get(int index);
		int get_size();
		void add(int index, T item);
		void add(T item);
		int exists(T item);
		T remove(int index);
		void remove(T item);
		void remove();
		void print();	
		
};
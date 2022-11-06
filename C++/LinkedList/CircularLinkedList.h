template<class T> struct CNode{

	T data;
	struct CNode<T> * next;
	
	public: 
		CNode(T data){
			this->data = data;
			this->next = nullptr;
		}
		
		~CNode(){
			delete this->next;
		}
		
};

template<class T> struct CircularLinkedList{
	
	private:
		CNode<T> * head;
		CNode<T> * tail;
		int size;
		
	public:
		CircularLinkedList();
		~CircularLinkedList();
		CNode<T> * get_head();
		CNode<T> * get_tail();
		CNode<T> * get_node(int index);
		T get(int index);
		int get_size();
		void add(int index, T item);
		void add(T item);
		int index_of(T item);
		T remove(int index);
		T remove_item(T item);
		T remove_last();
		void append_to_head(T item);
		void append_to_tail(T item);
		void print();
		
	
	
};
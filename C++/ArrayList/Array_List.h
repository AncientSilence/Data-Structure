#include <iostream>

using namespace std;

template<class T> struct Array_List{
	private:
		int size;
		int capacity;
		T * array_list;
	public:
	    Array_List();
		Array_List(int capacity);
	    T get(int index);
		void set(int index, T item);
		bool search(T item);
		int index_of(T item);
		void reallocate();
		void add(int index, T item);
		void add(T item);
		T remove(int index);
		
		//Theory: overload the [] allows Array_List to directly access its array contents
		T& operator[](int index)
		{
		  return array_list[index];
		};
		
};
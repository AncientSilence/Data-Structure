#include "Array_List.h"
#define INITIAL_CAPACITY 10;

using namespace std;

template<class T> Array_List<T>::Array_List(){
	size = 0;
	capacity = INITIAL_CAPACITY;
	array_list = new T[capacity];
}

template<class T> Array_List<T>::Array_List(int _capacity){
	size = 0;
	capacity = _capacity;
	array_list = new T[capacity];
}

template<class T> 
T Array_List<T>::get(int index){
	return array_list[index];
}

template<class T> 
void Array_List<T>::set(int index, T item){
	//TODO: check if index is valid or not
	array_list[index] = item;
}

template<class T>
void add(unsigned int index, T item){
	
}
template<class T>
void add(T item){
	
}

template<class T>
bool search(T item){
	return false;
}

template<class T>
int index_of(){
	return -1;
}
template<class T>
void reallocate(){
	
}

template<class T>
T remove(int index){
	return nullptr;
}


int main(){
	cout << "Compiled" << endl;
	Array_List<char> arr;
	arr.set(0, 'd');
	cout <<  arr.get(0) << endl;
	return 0;
}
#include "Array_List.h"
#include <stdexcept>
#include <sstream>
#include <string>
#define INITIAL_CAPACITY 10;

using namespace std;

template<class T> Array_List<T>::Array_List(){
	Array_List<T>::size = 0;
	Array_List<T>::capacity = INITIAL_CAPACITY;
	Array_List<T>::array_list = new T[capacity];
}

template<class T> Array_List<T>::Array_List(int _capacity){
	Array_List<T>::size = 0;
	Array_List<T>::capacity = _capacity;
	Array_List<T>::array_list = new T[capacity];
}

template<class T> 
T Array_List<T>::get(int index){
	if(index < Array_List<T>::get_size()){
		throw std::invalid_argument("Index out of bound");
	}
	return array_list[index];
}
template<class T>
int Array_List<T>::get_size(){
	return Array_List<T>::size;
	
}

template<class T>
int Array_List<T>::get_capacity(){
	return Array_List<T>::capacity;
}

template<class T> 
void Array_List<T>::set(int index, T item){
	//TODO: check if index is valid or not
	if(index < Array_List<T>::get_size()){
		throw std::invalid_argument("Index out of bound");
	}
	array_list[index] = item;
}

template<class T>
void add(int index, T item){
	if(index < Array_List<T>::get_size() || index > Array_List<T>::get_size()){
		throw std::invalid_argument("Index out of bound");
	}
	
	Array_List<T>::size++;
}
template<class T>
void Array_List<T>::add(T item){
	
}

template<class T>
bool Array_List<T>::search(T item){
	return false;
}

template<class T>
int Array_List<T>::index_of(T item){
	return -1;
}
template<class T>
void Array_List<T>::reallocate(){
	
}

template<class T>
T remove(int index){
	return nullptr;
}

template<class T>
void Array_List<T>::print(){
	for (int i = 0 ; i < 10; ++i){
		cout << array_list[i] << endl;;
	}
}

int main(){
	cout << "Compiled" << endl;
	Array_List<char> arr;
	arr.set(0, 'd');
	arr.print();
	return 0;
}
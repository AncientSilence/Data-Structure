#include "Array_List.h"
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
template<class T>Array_List<T>::~Array_List(){
	Array_List<T>::size = 0;
	Array_List<T>::capacity = 0;
	delete Array_List<T>::array_list;
}

template<class T> 
T Array_List<T>::get(int index){

	return array_list[index];
}
template<class T>
int Array_List<T>::get_size(){
	return -1;
	
}

template<class T>
int Array_List<T>::get_capacity(){
	return -1;
}

template<class T> 
void Array_List<T>::set(int index, T item){
	//TODO: check if index is valid or not
	array_list[index] = item;
}

template<class T>
void Array_List<T>::add(int index, T item){
	
}
template<class T>
void  Array_List<T>::add(T item){
	
}



template<class T>
int Array_List<T>::search(T item){
	return -1;
}
template<class T>
void Array_List<T>::reallocate(){
	
}

template<class T>
T Array_List<T>::remove(int index){
	return nullptr;
}

template<class T>
void Array_List<T>::print(){

}

int main(){


	return 0;
}
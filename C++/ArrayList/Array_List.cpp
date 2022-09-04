#include "Array_List.h"
#include <stdexcept>


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
	if(index >= Array_List<T>::get_size() || index < 0 ){
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
	if(index < 0 || index >= Array_List<T>::get_size() ){
		throw std::invalid_argument("Index out of bound");
	}
	array_list[index] = item;
}

template<class T>
void Array_List<T>::add(int index, T item){
	if(index < 0 || index > Array_List<T>::get_size()){
		throw std::invalid_argument("Index out of bound");
	}
	
	if(Array_List<T>::get_size() + 1 == Array_List::get_capacity()){
		//reallocate more memory
		Array_List<T>::reallocate();
	}
	
	for(int i = Array_List<T>::get_size() - 1; i >= index; i--){
		Array_List<T>::array_list[i+1] = Array_List<T>::array_list[i];
	}
	Array_List<T>::array_list[index] = item;
	++Array_List<T>::size;
	
}
template<class T>
void Array_List<T>::add(T item){
	Array_List<T>::add(Array_List<T>::get_size(),item);
}

template<class T>
int Array_List<T>::search(T item){
	for(int i = 0 ; i < Array_List<T>::get_size(); i++){
		if(Array_List<T>::get(i) == item){
			return i;
		}
	}
	return -1;
}

template<class T>
void Array_List<T>::reallocate(){
	//create a new tempory array with the same size as original array
	T * temporary = new T[Array_List::get_size()];
	//copy each items in the old array into the new array
	int original_size = Array_List::get_size();
	for(int i =  0 ; i < original_size;i++ ){
		temporary[i] = Array_List<T>::array_list[i];
	}
	//take out the original pointer before assign a new one a.k.a cleaning garbage
	delete [] Array_List<T>::array_list;
	//create a new array from the original array with tripled the original capacity
	Array_List<T>::capacity = Array_List::get_capacity() * 3;
	Array_List<T>::array_list = new T[Array_List::get_capacity()];
	//copy the all the items in the original array from the temporary array
	for(int i = 0 ; i < original_size; i++){
		Array_List<T>::array_list[i] = temporary[i];
	}
	//delete the temporary array
	delete [] temporary;
	temporary = NULL;
}

template<class T>
T Array_List<T>::remove(int index){
	if(index < 0 || index >= Array_List<T>::get_size()){
		throw std::invalid_argument("Index out of bound");
	}
	
	T to_return = Array_List<T>::get(index);
	for(int i = index+1; i < Array_List<T>::get_size(); i++){
		Array_List<T>::array_list[i-1] = Array_List<T>::array_list[i];
	}
	--Array_List<T>::size;
	return to_return;
}

template<class T>
void Array_List<T>::print(){
	for (int i = 0 ; i < Array_List<T>::get_size(); ++i){
		cout << Array_List<T>::array_list[i] << endl;
	}
}

int main(){
	Array_List<int> arr_int;
	Array_List<char> arr_char;
	int current_capacity = arr_int.get_capacity();
	
    //Add the amount of items to the array_list to check if reallocate and add work correctly
	for(int i = 0 ; i < current_capacity * 2; i++){
		arr_int.add(i);
	}
	arr_int.print(); 
	arr_int.remove(0);
	arr_int.print(); //0 will be removed from the list
	arr_int.remove(arr_int.get_size() - 1);
	arr_int.print(); //19 will be remove
	
	
	
	for(int i = 0 ; i < current_capacity * 2 + 6; i++){
		char x = 97 + i ; //genrating character a to z
		arr_char.add(x);
	}
	arr_char.print();
	//Remove item at certain index
	arr_char.remove(0);
	arr_char.print(); //'a' will be removed from the list
	arr_char.remove(arr_char.get_size() - 1);
	arr_char.print(); //'z' will be remove
	
	return 0;
}
#include <iostream>
#include <stdexcept>

#include "CircularLinkedList.h"

template<class T> 
CircularLinkedList<T>::CircularLinkedList(){
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template<class T>
CircularLinkedList<T>::~CircularLinkedList(){
	CNode<T> * current = nullptr;
	while(this->head->next != this->head){
		current = this->head;
		this->head = this->head->next;
		delete current;
	}
	//delete the remaining tail
	delete this->tail;
}

template<class T>
CNode<T> * CircularLinkedList<T>::get_head(){
	return this->head;
}

template<class T>
CNode<T> * CircularLinkedList<T>::get_tail(){
	return this->tail;
}

template<class T>
CNode<T> * CircularLinkedList<T>::get_node(int index){
	if(index < 0 || index >= this->size){
		throw std::invalid_argument("Invalid Index");
	}
	CNode<T> * current = this->head;
	if(index == 0){
		return this->head;
	}else if(index == this->size - 1){
		return this->tail;
	}else{
		for(int i = 0; i < index ;i++){
			current = current->next;
		}
	}
	return current;
}

template<class T>
T CircularLinkedList<T>::get(int index){
	return this->get_node(index)->data;
}

template<class T>
int CircularLinkedList<T>::get_size(){
	return this->size;
}

template<class T>
void CircularLinkedList<T>::add(int index, T item){
	//Case 1: Invalid Index
	//Case 2: Adding to an empty list
	//Case 3: Adding to the head
	//Case 4: Adding to the tail
	//Case 5: Adding to anywhere between the head and tail
	if(index < 0 || index > this->size){
		throw std::invalid_argument("Invalid index when added");
	}
	CNode<T> * holder = new CNode<T>(item);
	if(this->size == 0){
		this->head = this->tail = holder;
	}else if(index == 0){
		holder->next = this->head;
		this->head = holder;
	}else if(index == this->size){
		holder->next = this->head;
		this->tail->next = holder;
		this->tail = holder;
	}else{
		CNode<T> * before = this->get_node(index - 1);
		holder->next = before->next;
		before->next = holder;
	}
	
	this->size++;
	
}

template<class T>
void CircularLinkedList<T>::add(T item){
	this->add(size, item);
	
}

template<class T>
int CircularLinkedList<T>::index_of(T item){
	
	if(this->head->data == item){
		return 0;
	}else if(this->tail->data == item){
		return this->size - 1;
	}
	for(int i = 0 ; i < this->size; i++){
		if(this->get(i) == item){
			return i;
		}
	}
	return -1;
}

template<class T>
T CircularLinkedList<T>::remove(int index){
	//Case 1: Invalid index
	//Case 2: Remove the last item in the circular list
	//Case 3: Remove the head of the circular list
	//Case 4: Remove the tail of the circular list
	//Case 5: Remove any item between the head and tail of the list
	
	if(index < 0 || index >= this->size){
		throw std::invalid_argument("Invalid index when removed");
	}
	T to_return = this->get(index);
	if(this->size == 1){
		this->head = this->tail = nullptr;
	}else if(index == 0 ){
		this->tail->next = this->head->next;
		this->head = this->head->next;
	}else if(index == this->size - 1){
		CNode<T> * before_tail = this->get_node(this->size - 2);
		before_tail->next = this->tail->next;
		this->tail = before_tail;	
	}else{
		CNode<T> * before = this->get_node(index - 1);
		before->next = before->next->next;
	}
	this->size--;
	return to_return;
}

template<class T>
T CircularLinkedList<T>::remove_item(T item){
	return this->remove(this->index_of(item));
}

template<class T>
T CircularLinkedList<T>::remove_last(){
	return this->remove(this->size - 1);
}

template<class T>
void CircularLinkedList<T>::append_to_head(T item){
	this->add(0, item);
}

template<class T>
void CircularLinkedList<T>::append_to_tail(T item){
	this->add(this->size, item);
	
}

template<class T>
void CircularLinkedList<T>::print(){
	
	std::cout << std::endl;
	for(int i = 0; i < this->size; i++){
		std::cout << this->get(i) << " <-> ";
	}
	std::cout << this->head->data;
	
}
int main(){
	std::cout << "Initial Compiled!"<< std::endl;
	CircularLinkedList<int> cl_int;
	cl_int.add(1);
	cl_int.add(22);
	cl_int.add(12);
	cl_int.add(32);
	cl_int.add(43);
	cl_int.add(26);
	cl_int.print();
	//1 <-> 22 <-> 12 <-> 32 <-> 43 <-> 26 <-> 1
	cl_int.remove(0);
	///22 <-> 12 <-> 32 <-> 43 <-> 26 <-> 22
	cl_int.print();
	cl_int.remove_item(43);
	//22 <-> 12 <-> 32 <-> 26 <-> 22
	cl_int.print();
	cl_int.remove_last();
	//22 <-> 12 <-> 32 <-> 22
	cl_int.print();
	cl_int.append_to_head(66);
	cl_int.append_to_head(10);
	cl_int.append_to_head(34);
	//34 <-> 10 <-> 66 <-> 22 <-> 12 <-> 32 <-> 34
	cl_int.print();
	cl_int.append_to_tail(11);
	cl_int.append_to_tail(12);
	cl_int.append_to_tail(13);
	cl_int.append_to_tail(14);
	//34 <-> 10 <-> 66 <-> 22 <-> 12 <-> 32 <-> 11 <-> 12 <-> 13 <-> 14 <-> 34
	cl_int.print();
	
	return 0;
}
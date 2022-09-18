#include <iostream>
#include <stdexcept>
#include "DoublyLinkedList.h"

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
	DNode<T> * current = nullptr;
	while(this->head != nullptr){
		current = this->head;
		this->head = this->head->next;
		delete current;
	}
	this->size = 0;

}

template<class T>
DNode<T> * DoublyLinkedList<T>::get_head(){
	return this->head;
}

template<class T>
DNode<T> * DoublyLinkedList<T>::get_tail(){
	return this->tail;
}

template<class T>
DNode<T> * DoublyLinkedList<T>::get_node(int index){
	if(index < 0 || index >= this->size){
		throw std::invalid_argument("Invalid Arguments");
	}
	int count = 0;
	DNode<T> * current = this->head;
	while(count < index){
		current = current->next;
		count++;
	}
	return current;
}

template<class T>
T DoublyLinkedList<T>::get(int index){
	return this->get_node(index)->data;
}

template<class T>
int DoublyLinkedList<T>::get_size(){
	return this->size;
}

template<class T>
void DoublyLinkedList<T>::add(int index, T item){
	//Case 1: Invalid Index 
	//Case 2: Adding to an empty list
	//Case 3: Adding to the head
	//Case 4: Adding to the tail
	//Case 5: Adding any where between the head and tail
	if(index < 0 || index > this->size){
		throw std::invalid_argument("Invalid index");
	}
	DNode<T> * holder = new DNode<T>(item);
	
	if(this->size == 0){
		this->head = this->tail = holder;
	}
	else if(index  == 0 ){
		holder->next = this->head;
		this->head->prev = holder;
		this->head = holder;
	}else if(index == this->size){
		holder->prev = this->tail;
		this->tail->next = holder;
		this->tail = holder;
	}else{
		DNode<T> * before = this->get_node(index - 1);
		holder->next = before->next;
		holder->next->prev = holder;
		holder->prev = before;
		before->next = holder;
		
	}
	
	this->size++;
	
}

template<class T>
void DoublyLinkedList<T>::add(T item){
	this->add(this->size, item);
}

template<class T>
int DoublyLinkedList<T>::search(T item){
	int count = 0;
	DNode<T> * current = this->head;
	while(current != nullptr){
		if(current->data == item){
			return count;
		}
		count++;
		current = current->next;
	}
	return -1;
}

template<class T>
T DoublyLinkedList<T>::remove(int index){
	//1. Invalid Index
	//2. Remove the last item in the list
	//3. Remove the head
	//4. Remove the tail
	//5. Remove any position between head and tail
	if(index < 0 || index >= this->size){
		throw std::invalid_argument("Invald arguments");
	}
	T to_return = this->get(index);
	if(this->size == 1){
		this->head = this->tail = nullptr;
	}
	else if(index == 0){
		this->head = this->head->next;
		this->head->prev = nullptr;
	}else if(index == this->size - 1){
		this->tail = this->tail->prev;
		this->tail->next = nullptr;
	}else{
		DNode<T> * before = this->get_node(index - 1);
		before->next = before->next->next;
		before->next->prev = before;
	}
	this->size--;
	return to_return;
}

template<class T>
T DoublyLinkedList<T>::remove(T item){
	int search_index = this->search(item);
	if(search != -1){
		return this->remove(search_index);
	}
	return nullptr;
}

template<class T>
T DoublyLinkedList<T>::remove(){
	return this->remove(this->size - 1);
	
}

template<class T>
void DoublyLinkedList<T>::append_to_head(T item){
	this->add(0, item);
}

template<class T>
void DoublyLinkedList<T>::remove_at_head(){
	this->remove(0);
}

template<class T>
void DoublyLinkedList<T>::print(){
	DNode<T> * current = this->head;
	while(current != nullptr){
		std::cout << current->data << " <--> ";
		current = current ->next;
	}
	std::cout << "NULL" << std::endl;
	
}

int main(){
	DoublyLinkedList<char> dlm;
	dlm.add(0, 'c');
	dlm.add('v');
	dlm.append_to_head('a');
	dlm.add(1, 'g');
	dlm.print();
	dlm.remove(1);
	dlm.print();
	dlm.remove_at_head();
	dlm.print();
	std::cout << dlm.search('g')<< std::endl;
	return 0;
}
/*Implement a linked list in C++*/
#include <iostream>
#include <stdexcept>
#include "SinglyLinkedList.h"

using namespace std;

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(){
	this->size = 0;
	this->head = nullptr;
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList(){
	Node<T> * current = nullptr;
	while(current){
		current = this->head;
		this->head = this->head->next;
		delete current;
	}
	this->size = 0;
}

template<class T>
Node<T> * SinglyLinkedList<T>::get_head(){
	return this->head;
}

template<class T>
Node<T> * SinglyLinkedList<T>::get_node(int index){
	
	Node<T> * temp = this->head;
	for(int i = 0; i < index; i++){
		temp = temp->next;
	}
	return temp;
}

template<class T>
int SinglyLinkedList<T>::get_size(){
		return this->size;
}

template<class T>
void SinglyLinkedList<T>::set(int index, T item){
	if(index < 0 || index >= this->size){
		throw std::invalid_argument("Index out of bound");
	}
	this->get_node(index)->data = item;
}

template<class T>
T SinglyLinkedList<T>::get(int index){
	if(index < 0 || index >= this->size){
		throw std::invalid_argument("Index out of bound");
	}
	return this->get_node(index)->data;
}

template<class T>
int SinglyLinkedList<T>::exists(T item){
	Node<T> * temp = this->head;
	int count = 0;
	while(temp != nullptr){
		if(temp->data == item){
			return count;
		}
		++count;
		temp = temp->next;
	}
	return -1;
}


template<class T>
void SinglyLinkedList<T>::add(int index, T item){
	//several cases to consider
	//1. What if the index is invalid
	//2. Adding to an empty list
	//3. Adding to the beginning of the list 
	//4. Adding to anywhere in the list
	
	if(index < 0 || index > this->size){
		throw std::invalid_argument("Index out of bound");
	}
	
	Node<T> * temp_node = new Node<T>(item);
	
	if(this->size == 0){
		std::cout << "Adding first item to the head"<< std::endl;
		this->head = temp_node;
	}
	else if(index == 0){
		temp_node->next = head;
		this->head = temp_node;
	}else{
		Node<T> * before = this->get_node(index - 1);
		temp_node->next =  before->next;
		before->next = temp_node;
	}
	this->size++;
	std:cout << "Total Number of Items: " << this->size << std::endl;
	
	
}

template<class T>
void SinglyLinkedList<T>::add(T item){
	this->add(this->size, item);
}


template<class T>
T SinglyLinkedList<T>::remove(int index){
	//several cases to consider
	//1.What if the index is invalid?
	//2.What if the list is empty
	//3.What if the list only has one item
	//4.Remove the head of the list
	//5.Remove any item from the list
	
	if(index < 0 || this->size == 0 || index >= this->size){
		throw std::invalid_argument("Index out of bound or list is empty");
	}
	T to_return = this->get(index);
	if(index == 0){
		Node<T> * current = this->head;
		this->head = head->next;
		current->next = nullptr;
		current = nullptr;		
	}else{
		Node<T> * before = this->get_node(index - 1);
		Node<T> * free_node = before->next;
		before->next = before->next->next;
		free_node->next = nullptr;
		free_node = nullptr;
	}
	this->size--;
	return to_return;
}

template<class T>
void SinglyLinkedList<T>::remove(T item){
	int search = this->exists(item);
	if(search != -1){
		this->remove(search);
	}
		
}

template<class T>
void SinglyLinkedList<T>::remove(){
	this->remove(this->size - 1);
}

template<class T>
void SinglyLinkedList<T>::print(){
	Node<T> * iterator = this->head;
	while(iterator != nullptr){
		std::cout << iterator->data << "-->";
		iterator = iterator->next;
	}
	
	std::cout << "NULL" << std::endl;
}




int main(){
	cout << "Compiled" << endl;
	//initialize a node
	Node<int> * a = new Node<int>(100);
	SinglyLinkedList<char> list;
	//cout << "Size: " << list.get_size() << endl;
	list.add(0, 's');
	list.add(0, 'c');
	list.add('d');
	list.add('w');
    list.print();
	list.set(0, 'a');
	char c = list.get(1);
	list.remove(0);
	//list.remove(1);
	list.remove('w');
	list.remove();
	list.print();
	cout << list.exists('a') << endl;
	return 0;
}
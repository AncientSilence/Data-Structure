/*Implement a linked list in C++*/
#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(){
	this->size = 0;
	this->head = nullptr;
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList(){
	delete this->head;
	this->size = 0;
}

template<class T>
Node<T> * SinglyLinkedList<T>::get_node(int index){
	
	Node<T> * temp = this->head;
	return temp;
}

template<class T>
int SinglyLinkedList<T>::get_size(){
		return this->size;
}

template<class T>
void SinglyLinkedList<T>::set(int index, T item){
}

template<class T>
T SinglyLinkedList<T>::get(int index){
	return NULL;
}

template<class T>
int SinglyLinkedList<T>::exists(T item){
	return -1;
}


template<class T>
void SinglyLinkedList<T>::add(int index, T item){
	
}

template<class T>
T SinglyLinkedList<T>::remove(int index){
	return NULL;
}

template<class T>
void SinglyLinkedList<T>::remove(T item){
	
}

template<class T>
void SinglyLinkedList<T>::remove(){
}

template<class T>
void SinglyLinkedList<T>::print(){
}




int main(){
	cout << "Compiled" << endl;
	//initialize a node
	Node<int> * a = new Node<int>(100);
	SinglyLinkedList<char> list;
	cout << "Size: " << list.get_size() << endl;
	return 0;
}
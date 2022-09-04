import java.lang.StringBuilder;


public class Array_List<E>{
	
	private int size;
	private int capacity;
	private E[] array_list;
	
	//Constructor
	public Array_List(){
		this.size = 0;
		this.capacity = 10;
		this.array_list = (E[]) new Object[this.capacity];
	}
	
	//Constructor with specified initial capacity
	public Array_List(int capacity){
		this.size = 0;
		this.capacity = capacity;
		this.array_list = (E[]) new Object[this.capacity];
	}
	public int get_size(){
		return this.size;
	}
	
	public int get_capacity(){
		return this.capacity;
	}
	//Set the item at certain index to hold that item
	public E set(int index, E item){
		//check index out of bound
		if(index < 0 || index >= this.size){
			throw new IndexOutOfBoundsException("Index " + index + " is out of bounds!");
		}
		E current_item = this.array_list[index];
		this.array_list[index] = item;
		return current_item;
	}
	//Return the item at specified index
	public E get(int index){
		//TODO: check index out of bound
		if(index < 0 || index >= this.size){
			throw new IndexOutOfBoundsException("Index " + index + " is out of bounds!");
		}
		return this.array_list[index];
	}
	
	//Given an item, checj if it exists in the array list
	//For example 1 -> [0, 3, 4, 5, 1] would return true
	//            0 - > [2, 3, 1, 4, 5] would return false
	public boolean existed(E item){ //assume if Object implements equals interface
		for(int i = 0 ; i < this.size; i++){
			if(this.array_list[i].equals(item)){
				return true;
			}
		}
		return false;
	}
	
	//Given an item, if the item exists in the array, return the index of that item
	public int index(E item){
		for(int i = 0 ; i < this.size; i++){
			if(this.array_list[i].equals(item)){
				return i;
			}
		}
		return -1;
	}
	
	//When the array is full, copy all the items from the original array to a new array with tripled the original capacity
	public void reallocate(){
		E [] arr = (E[]) new Object[this.capacity * 3];
		for(int i = 0; i < this.size; i++){
			arr[i] = this.array_list[i];
		}
		this.array_list = arr;
		
	}
	
	//Add an item to a certain index, if the cell already contains an item, shift all the items to the right
	public void add(int index, E item){
		if(this.size + 1 == this.capacity){
			reallocate();
		}
		if(index < 0 || index > this.size){
			throw new IndexOutOfBoundsException("Index " + index + " is out of bounds from add method");
		}
		for(int i = this.size - 1; i>= index; i--){
			this.array_list[i+1] = this.array_list[i];
			
		}
		this.array_list[index] = item;
		++this.size;
		
	}
	
	//Add an item to the end of the list
	public void add(E item){
		this.add(this.size, item);
	}
	
	public E remove(int index){
		if(index < 0 || index >= this.size){
			throw new IndexOutOfBoundsException("Index " + index + " is out of bounds from remove method");
		}
		E to_return = this.array_list[index];
		for(int i = index + 1; i < this.size; i++){
			this.array_list[i - 1] = this.array_list[i];
		}
		--this.size;
		return to_return;
	}
	
	public E remove(E item){
		return this.remove(this.index(item));
	}
	
	public boolean remove(){
		return this.remove(this.size - 1) == null ? false : true;
	}
	
	//remove all the "empty" space in the array after reallocating "too much" spaces
	//Given after reallocate() call and the array is [1,2 3, 4, 5, null, null, null], return [1,2,3,4,5]
	public void chop(){
		//count how many item in the current array that is not null
		int counter = 0;
		for(int i = 0 ; i < this.size; i++){
			if(this.array_list[i] != null){
				++counter;
			}
		}
		if(counter == 0 ){
			return;
		}
		//create a new array with the length of items that is not null
		E[] array = (E[]) new Object[counter];
		for(int i = 0 ; i < counter ; i++){
			array[i] = this.array_list[i];
		}
		//point the array_list to the new array and let Java handles the garbage collection
		this.array_list = array;
		this.size = this.capacity = array.length;
		
	}
	
	@Override
	public String toString(){
		StringBuilder sb = new StringBuilder();
		for(int i =  0; i < this.size; i++){
			sb.append(this.array_list[i]).append(" ");
		}
		return sb.toString();
	}
	
	public static void main(String [] args){
		System.out.println("ArrayList");
		Array_List<Integer> al = new Array_List<>();		
		//add up to double to capacity to check if add and reallocate function work as intended
		int current_capacity = al.get_capacity();
		for(int i = 0 ; i < current_capacity * 2; i++){
			al.add(i * 2);
		}
		//remove the last item and a specified item
		Integer to_remove = new Integer(10);
		al.remove(to_remove);
		al.remove();
		//check if the array is reduced down to the number of item
		al.chop();
		System.out.println(al.existed(null));
		System.out.println(al.toString());
	}
}
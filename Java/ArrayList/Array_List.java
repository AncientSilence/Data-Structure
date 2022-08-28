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
	
	//Set the item at certain index to hold that item
	public E set(int index, E item){
		//TODO: check index out of bound
		this.array_list[index] = item;
		return null;
	}
	//Return the item at specified index
	public E get(int index){
		//TODO: check index out of bound
		return this.array_list[index];
	}
	
	//Given an item, checj if it exists in the array list
	//For example 1 -> [0, 3, 4, 5, 1] would return true
	//            0 - > [2, 3, 1, 4, 5] would return false
	public boolean existed(E item){ //assume if Object implements equals interface
		
		return false;
	}
	
	//Given an item, if the item exists in the array, return the index of that item
	public int index(E item){
		return -1;
	}
	
	//When the array is full, copy all the items from the original array to a new array with tripled the original capacity
	public void reallocate(){
		
	}
	//remove all the "empty" space in the array after reallocating "too much" spaces
	//Given after reallocate() call and the array is [1,2 3, 4, 5, null, null, null], return [1,2,3,4,5]
	public void chop(){
	}
	
	//Add an item to a certain index, if the cell already contains an item, shift all the items to the right
	public void add(int index, E item){
		
	}
	
	//Add an item to the end of the list
	public void add(E item){
		
	}
	
	public E remove(int index){
		return null;
	}
	
	public E remove(E item){
		return null;
	}
	
	public boolean remove(){
		return false;
	}
	
	@Override
	public String toString(){
		return "";
	}
	
	public static void main(String [] args){
		System.out.println("ArrayList");
	}
}
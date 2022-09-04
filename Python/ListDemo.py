#In Python, there is no native array or "built-in support for Arrays" (https://www.w3schools.com/python/python_arrays.asp)
#Instead, we have List, which is similar to std::vector<T> in C++ and ArrayList<E> in Java. In this program, we can demo how a List data structure works
 
array_list = [i ** 2 for i in range(10)]
print(array_list) #list is [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

#Similar to add to the end of the list. 
array_list.append(10) #list is [1, 4, 9, 16, 25, 36, 49, 64, 81, 10]
print(array_list)
#Add item to the list at an index, moving the  original items to the right 
array_list.insert(0, 31) #list is [31, 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 10]
print(array_list)

#Search the array for the item, if the item existed, remove it and move all the item to the left 
array_list.remove(31)
print(array_list) #list is now [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 10]

array_list.pop() #list is now [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
print(array_list)


#More functions of list data structure can be found at https://docs.python.org/3/tutorial/datastructures.html
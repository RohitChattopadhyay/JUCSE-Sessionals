package linkedList;

import java.io.*;
import java.util.*; 

public class LinkedList<T> { 

	Node<T> head; 
	static class Node<T> { 

		T data; 
		Node<T> next; 

		// Constructor 
		Node(T d) 
		{ 
			data = d; 
			next = null; 
		} 
	}  
	public static <T> T insert(LinkedList list, T data) 
	{  
		Node new_node = new Node(data); 
		new_node.next = null; 

		if (list.head == null) { 
			list.head = new_node; 
		} 
		else { 
			Node last = list.head; 
			while (last.next != null) { 
				last = last.next; 
			} 
			last.next = new_node; 
		} 
		return data; 
	} 
	public static <T> LinkedList insertFront(LinkedList list, T data) 
	{  
		Node new_node = new Node(data); 
		new_node.next = list.head; 

		list.head = new_node; 
		return list; 
	} 

	@SuppressWarnings("unchecked")
	public static <T> List<T> allList(LinkedList list) 
	{ 
		Node currNode = list.head; 
		List<T> arr = new ArrayList<T>();

		while (currNode != null) { 
			arr.add((T) currNode.data); 
			currNode = currNode.next; 
		}
		return arr;
	} 

	@SuppressWarnings("rawtypes")
	public static LinkedList deleteAtPosition(LinkedList list, int index) 
	{ 
		Node currNode = list.head, prev = null; 
		if (index == 0 && currNode != null) { 
			list.head = currNode.next; // Changed head 
			return list; 
		} 
		int counter = 0; 
		while (currNode != null) { 

			if (counter == index) { 
				prev.next = currNode.next;  
				break; 
			} 
			else { 
				prev = currNode; 
				currNode = currNode.next; 
				counter++; 
			} 
		} 

		return list; 
	} 
} 
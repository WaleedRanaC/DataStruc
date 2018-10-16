/*  Student information for assignment:
 *
 *  On my honor, <NAME>, this programming assignment is my own work
 *  and I have not provided this code to any other student.
 *
 *  UTEID:
 *  email address:
 *  Grader name:
 *  Number of slip days I am using:
 */
import java.util.Iterator;

public class LinkedList<E> implements IList<E> {
    // CS314 student. Add you instance variables here.
    // You decide what instance variables to use.
    // Must adhere to assignment requirements. No ArrayLists or Java LinkedLists.
	DoubleListNode<E> head;
	DoubleListNode<E> end;
	E headData;
	E endData;
	
	int size;
	

    /**
     * add item to the front of the list.
     * <br>pre: item != null
     * <br>post: size() = old size() + 1, get(0) = item
     * @param item the data to add to the front of this list
     */
    public void addFirst(E item){

    //checking the precondition
	if(item == null){
		throw new IllegalArgumentException(" item cannot equal null ");
	}
	
	//creating a new front of the list
	DoubleListNode<E> firstNode = new DoubleListNode<E>(end.getPrev(), item, null);
	
	//setting the front of the list to the head
	firstNode.setNext(head);
	
	//setting the head to new first node
	head = firstNode;
	
	//setting the headData
	headData = head.getData();
	


    }



    /**
     * add item to the end of the list.
     * <br>pre: item != null
     * <br>post: size() = old size() + 1, get(size() -1) = item
     * @param item the data to add to the end of this list
     */
    public void addLast(E item){
    }


    /**
     * remove and return the first element of this list.
     * <br>pre: size() > 0
     * <br>post: size() = old size() - 1
     * @return the old first element of this list
     */
    public E removeFirst(){
        return null;
    }


    /**
     * remove and return the last element of this list.
     * <br>pre: size() > 0
     * <br>post: size() = old size() - 1
     * @return the old last element of this list
     */
    public E removeLast(){
        return null;
    }
    
    
    
    //IList implementation files
    //got to make same as implement
    public int size() {
    	 return 0;
    }
    
    public void add(E item){
    	
    }
    
   
    public E remove(int item) {
    	
    	return null;
    }
    
    public boolean remove(E item) {
    	
    	return true;
    }
    
    public IList<E> getSubList(int start, int stop){
    //int listSize = start - stop ;
     //IList<E> newList = new IList<E>();
     
    	return null;
    }
    
    public void makeEmpty() {
    	
    }
    
    public E get(int pos)
    {
    	return null;
    }
    
    public void insert(int pos, E item) {
    	
    }
    
    public int indexOf(E item){
    	
    	return 0;
    }
    
    public int indexOf(E item, int pos){
    	
    	 return 0;
    }
    
    public Iterator<E> iterator(){
    	
    	return null;
    }
    
    public void removeRange(int start, int stop) {
    	
    }
    
    public E set(int pos, E item) {
    	return null;
    }
 
    
    
 

}
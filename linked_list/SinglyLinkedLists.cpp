#include <stdio.h>
#include <iostream>
using namespace std;

class SinglyLinkedList
{

public:
    SinglyLinkedList( int value ): next( NULL ), data( value ) {}
    ~SinglyLinkedList() {};

    /* Getting the next element */
    SinglyLinkedList *getNext() const { return next; }
    /* Getting the value */
    int getValue() const { return data; }
    /* Setting the next element */
    void setNext( SinglyLinkedList *elem ) { next = elem; }
    /* Setting the value */
    void setValue( int value ) { data = value; }
    
    /* Finding the element by value */
    SinglyLinkedList* find(int value)
    {
    	SinglyLinkedList *currentElement = this;
    	while(currentElement)
    	{
    		if(currentElement->getValue() == value)
    			break;

    		currentElement = currentElement->getNext();
    	}
    	return currentElement;
    }
    /* Insert the value to the front of the list (head)
    *  return - false on failure
    */
	static bool insertInFront(SinglyLinkedList **head , int value)
    {
    	SinglyLinkedList *newElement = new SinglyLinkedList(value);

    	if(NULL == newElement)
    		return false;

    	newElement->data = value;
    	newElement->next = *head;
    	*head = newElement;
    	
    	return true;
    }
  private:
    SinglyLinkedList *next;
    int         data;

};

int main()
{	
	cout << "Testing class SinglyLinkedList" <<endl;
	SinglyLinkedList *list1 = new SinglyLinkedList(10);
	cout << "Data in the list1 is " << list1->getValue() <<endl;
	
	SinglyLinkedList *list2 = new SinglyLinkedList(30);
	cout << "Data in the list2 is " << list2->getValue() <<endl;

	SinglyLinkedList *list3 = new SinglyLinkedList(50);
	cout << "Data in the list3 is " << list3->getValue() <<endl;

	cout << "Making chain of list" <<endl;

	list1->setNext(list2);
	list2->setNext(list3);

	cout << "value list 1:  " << list1->getValue() <<endl ;
	cout << "value list 2:  " << list1->getNext()->getValue() <<endl ;
	cout << "value list 3:  " << list1->getNext()->getNext()->getValue() <<endl;
	cout << "==============" << endl;

	cout <<"Adding value in front of the list" <<endl;
	SinglyLinkedList::insertInFront(&list1 , 55);


	cout << "value list 1:  " << list1->getValue() <<endl ;
	cout << "value list 2:  " << list1->getNext()->getValue() <<endl ;
	cout << "value list 3:  " << list1->getNext()->getNext()->getValue() <<endl;
	cout << "value list 4:  " << list1->getNext()->getNext()->getNext()->getValue() <<endl;
	cout << "==============" << endl;

	SinglyLinkedList *foundElement = list1->find(50);
	cout << "found element , value is: "<<foundElement->getValue() <<endl;

}

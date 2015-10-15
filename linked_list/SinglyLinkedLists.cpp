#include <stdio.h>
#include <iostream>

using namespace std;
class SinglyLinkedList
{

public:
    SinglyLinkedList( int value ): next( NULL ), data( value ) {}
    ~SinglyLinkedList() {};

    SinglyLinkedList *getNext() const { return next; }
    int getValue() const { return data; }
    void setNext( SinglyLinkedList *elem ) { next = elem; }
    void setValue( int value ) { data = value; }
	static bool insertInFront(SinglyLinkedList **head , int value)
    {
    	SinglyLinkedList *newElement = new SinglyLinkedList(value);//

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



	

}

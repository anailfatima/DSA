#include "LinkedList.h"

class myLL :public LinkedList
{
	void insertAtTail(int);
	void insertAtHead(int);
public:
	void display();
	bool isEmpty();
	int deleteFromTail();
	int deleteFromHead();
	bool search(int);
	bool deleteValue(int);
	void insertSorted(int);
};

void myLL::insertSorted(int value)
{
	if (isEmpty())
	{
		Node*nn = nullptr;
		nn = new Node;
		nn->data = value;
		nn->next = nullptr;

		head = nn;
		tail = nn;
	}

	else if (value <= head->data)
		insertAtHead(value);

	else if (value >= tail->data)
		insertAtTail(value);

	else	// insert in between
	{
		Node*nn = nullptr;
		nn = new Node;
		nn->data = value;
		nn->next = nullptr;


		Node*temp = head;

		while(1)
		{
			if (temp->data<value && temp->next->data>=value)
				break;

			else
				temp = temp->next;
		}

		nn->next = temp->next;
		temp->next = nn;
	}

}

bool myLL::deleteValue(int value)
{
	if (isEmpty())
		return false;

	else if (head == tail) //single node
	{
		if (head->data == value)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}

		else
			return false;
	}

	else if (head->data == value)
	{
		deleteFromHead();
		return true;
	}

	else if (tail->data == value)
	{
		deleteFromTail();
		return true;
	}

	else
	{
		Node*temp = head;

		while(1)
		{
			if (temp->next->data == value)
				break;

			else
				temp = temp->next;

			if (temp == tail)
				return false;
		}

		Node*t2 = temp->next;
		temp->next = temp->next->next;
		delete t2;
		t2 = nullptr;

		return true;
	}

}

bool myLL::search(int value)
{
	if (isEmpty())
		return false;
	
	else
	{
		Node*temp = head;

		while(1)
		{
			if (temp->data == value)
				return true;

			temp = temp->next;

			if (temp == nullptr)
				return false;
		}
	}
}

int myLL::deleteFromHead()
{
	if (isEmpty())
		return NULL;

	if (head == tail) //single node case
	{
		int returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		Node*temp = head;
		int returningValue = head->data;

		head = head->next;
		delete temp;
		temp = nullptr;

		return returningValue;

	}
}


int myLL::deleteFromTail()
{
	if (isEmpty())
		return NULL;

	if (head == tail) //single node case
	{
		int returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		Node*temp = head;

		while(1)
		{
			if (temp->next == tail)
				break;

			else
				temp = temp->next;

		}
		int returningValue = tail->data;
		delete tail;
		tail = temp;
		temp->next = nullptr;
		return returningValue;

	}
}

bool myLL::isEmpty()
{
	return head == nullptr && tail == nullptr;
}

void myLL::display()
{
	if (head == nullptr && tail == nullptr)
		cout << "LL is empty" << endl;

	else
	{
		Node* temp = head;

		while (1)
		{
			cout << temp->data << endl;
			temp = temp->next;

			if (temp == nullptr)
				break;
		}
	}
}

void myLL::insertAtTail(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	if (head == nullptr && tail == nullptr) //empty LL
	{
		head = nn;
		tail = nn;
	}

	else //non-empty LL
	{
		tail->next = nn;
		tail = nn;
	}
}

void myLL::insertAtHead(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	if (head == nullptr && tail == nullptr) //empty LL
	{
		head = nn;
		tail = nn;
	}

	else //non-empty LL
	{
		nn->next = head;
		head = nn;
		
	}
}
#include "myLL.h"

int main()
{
	myLL obj;

	obj.insertAtTail(1);
	obj.insertAtTail(2);
	obj.insertAtTail(3);
	obj.insertAtTail(4);
	obj.insertAtTail(5);
	obj.insertAtTail(6);
	obj.insertAtTail(7);
	obj.insertAtTail(8);
	obj.insertAtTail(9);

	myLL obj2;
	int s=obj.totalNodes();
	
	for (int i = 0; i < s;i++)
	{
		obj2.insertAtTail(obj.deleteFromTail());
	}
	obj = obj2;

	cout << "Reversed linked list : " << endl;
	obj2.display();

	return 0;
}
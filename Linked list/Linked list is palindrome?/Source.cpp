#include "myLL.h"

int main()
{
	myLL obj;

	obj.insertAtTail(1);
	obj.insertAtTail(1);
	obj.insertAtTail(0);
	obj.insertAtTail(1);
	obj.insertAtTail(1);

	myLL obj1;
	obj1 = obj;

	myLL obj2;

	int s = obj.totalNodes();
	for (int i = 0; i < s;i++)
	{
		obj2.insertAtTail(obj1.deleteFromTail());
	}

	int o, o1;
	bool flag = true;
	for (int i = 0; i < s;i++)
	{
		o = obj.deleteFromHead();
		o1 = obj2.deleteFromHead();

		if(o!=o1)
		{
			cout << "List is not palindrome!" << endl;
			flag = false;
			break;
		}
	}

	if(flag==true)
	{
		cout << "List is palindrome." << endl;
	}
		return 0;
}
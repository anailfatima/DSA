#include "myLL.h"

int main()
{
	myLL obj;

	obj.insertSorted(15);
	obj.insertSorted(0);
	obj.insertSorted(999);
	obj.insertSorted(50);
	obj.insertSorted(10);
	obj.insertSorted(10);
	obj.insertSorted(50);
	obj.insertSorted(15);
	obj.insertSorted(49);
	obj.insertSorted(89);

	
	cout << "Display: " << endl;

	obj.display();

	return 0;
}
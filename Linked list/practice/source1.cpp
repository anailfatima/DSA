temp = tail->next;
tail->next = newNode;
tail = newNode;
newNode->next = temp;

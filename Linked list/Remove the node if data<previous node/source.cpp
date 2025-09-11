while(temp2!=nullptr)
{
    if(temp2->data<temp->data)
    {
        temp2 = temp2->next;
        delete temp->next;
        temp->next = temp2;
    }

    else
    {
        temp = temp->next;
        temp2 = temp2->next;
    }
}
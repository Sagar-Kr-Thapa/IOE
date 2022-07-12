#include <iostream>

using namespace std;

class List{
    struct node{
        int data;
        node * next = nullptr;
        node * prev = nullptr;
    };

    node * head;
    node * tail;

public:
    List(){head = nullptr; tail = nullptr;}
    bool isEmpty(){return (head == nullptr);}

    void insertBeg(int val)
    {
        if( isEmpty() )
        {
            head = new node;
            head->data = val;
            tail = head;
        }
        else
        {
            node * temp = new node;
            temp->data = val;
            temp->next = head;

            head->prev = temp;
            head = temp;
        }
    }

    void insertAfter(int refVal, int val)
    {
        node * temp = head;

        while(temp->data != refVal)
        {
            temp = temp->next;
            if(temp == nullptr)
            {
                throw "ERROR during <INSERTION>: Referenced element not found\n";
                break;
            }
        }

        if( temp != tail )
        {
            node * temp2 = new node;
            temp2->data = val;
            temp2->next = temp->next;
            temp->next->prev = temp2;
            temp2->prev = temp;
            temp->next = temp2;
        }
        else
        {
            insertEnd(val);
        }
    }

    void insertBefore(int refVal, int val)
    {
        node * temp = head;

        while(temp->data != refVal)
        {
            temp = temp->next;
            if(temp == nullptr)
            {
                throw "ERROR during <INSERTION>: Referenced element not found\n";
                break;
            }
        }

        if( temp != head )
        {
            node * temp2 = new node;
            temp2->data = val;
            temp2->prev = temp->prev;
            temp->prev->next = temp2;
            temp2->next = temp;
            temp->prev = temp2;
        }
        else
            insertBeg(val);
    }

    void insertEnd(int val)
    {
        if ( isEmpty() )
            insertBeg(val);
        else
        {
            node * temp2 = new node;
            temp2->data = val;
            temp2->prev = tail;
            tail->next = temp2;

            tail = temp2;
        }
    }

    int deleteBeg()
    {
        if( isEmpty() )
            throw "ERROR during <DELETION>: List is empty\n";

        int res = head->data;
        node * temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;

        return res;
    }

    int deleteAfter(int refVal)
    {
        if ( isEmpty() )
            throw "ERROR during <DELETION>: List is empty\n";

        node * temp = head;

        while (temp->data != refVal)
        {
            temp = temp->next;
            if(temp == nullptr)
            {
                throw "ERROR during <DELETION>: Referenced element not found\n";
                break;
            }
        }

        node * temp2 = temp->next;
        int res = temp2->data;

        if( temp2 != tail)
        {
            temp->next = temp2->next;
            temp2->next->prev = temp;
            delete temp2;
        }
        else
        {
            deleteEnd();
        }

        return res;
    }

    int deleteBefore(int refVal)
    {
        if ( isEmpty() )
            throw "ERROR during <DELETION>: List is empty\n";

        node * temp = head;

        while (temp->data != refVal)
        {
            temp = temp->next;
            if(temp == nullptr)
            {
                throw "ERROR during <DELETION>: Referenced element not found\n";
                break;
            }
        }

        node * temp2 = temp->prev;
        int res = temp2->data;

        if( temp2->prev != nullptr )
        {
            temp->prev = temp2->prev;
            temp2->prev->next = temp;

            delete temp2;
        }
        else
        {
            deleteBeg();
        }

        return res;
    }

    int deleteEnd()
    {
        if ( isEmpty() )
            throw "ERROR during <DELETION>: List is empty\n";

        node * temp = tail;

        int res = tail->data;
        tail = tail->prev;
        tail->next = nullptr;

        delete temp;

        return res;
    }

    void displayItems()
    {
        if( isEmpty() )
            throw "ERROR during <DISPLAY>: List is empty\n";

        node * temp = head;

        cout << "Items: " << endl;
        while(temp != tail)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

};
int main()
{
    List l1;

    try
    {
        l1.insertBeg(1);
        l1.insertEnd(5);
        l1.insertAfter(1,100);
        l1.insertAfter(100, 200);
        l1.insertBefore(100, -1);
        l1.insertAfter(200,5000);
        l1.insertBefore(5000,-2);
        l1.insertEnd(59);

        l1.displayItems();

        cout << endl;
        cout << "Deleted: " << l1.deleteBeg() << endl;
        cout << "Deleted: " << l1.deleteEnd() << endl;
        cout << "Deleted: " << l1.deleteAfter(100) << endl;
        cout << "Deleted: " << l1.deleteBefore(100) << endl;

        cout << endl;
        l1.displayItems();
    }
    catch( const char* msg)
    {
        cerr << msg << endl;
        return -1;
    }
    return 0;
}

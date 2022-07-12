#include <iostream>

using namespace std;

class List{
    struct node{
        int data;
        node * next = nullptr;
    };

    node * head;

public:
    List(){head = nullptr;}
    bool isEmpty(){return (head == nullptr);}

    void insertBeg(int val)
    {
        if( isEmpty() )
        {
            head = new node;
            head->data = val;
            head->next = nullptr;
        }
        else
        {
            node * temp = new node;
            temp->data = val;
            temp->next = head;
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

        node * temp2 = new node;
        temp2->data = val;

        //if the referenced element is the last element
        temp2->next = temp->next;
        temp->next = temp2;
    }

    void insertEnd(int val)
    {
        if ( isEmpty() )
            insertBeg(val);
        else
        {
            node * temp = head;

            while(temp->next != nullptr)
                temp = temp->next;

            node * temp2 = new node;
            temp2->data = val;
            temp2->next = nullptr;
            temp->next = temp2;
        }
    }

    int deleteBeg()
    {
        if( isEmpty() )
            throw "ERROR during <DELETION>: List is empty\n";

        int res = head->data;
        node * temp = head;
        head = head->next;
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

        temp->next = temp2->next;
        delete temp2;

        return res;
    }

    int deleteEnd()
    {
        if ( isEmpty() )
            throw "ERROR during <DELETION>: List is empty\n";

        node * temp = head;
        node * prev = nullptr;

        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;

        }

        int res = temp->data;
        prev->next = nullptr;

        delete temp;

        return res;
    }

    void displayItems()
    {
        if( isEmpty() )
            throw "ERROR during <DISPLAY>: List is empty\n";

        node * temp = head;

        cout << "Items: " << endl;
        while(temp->next != nullptr)
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
        l1.insertBeg(50);
        l1.insertEnd(5);
        l1.insertAfter(1,100);
        l1.insertAfter(100, 200);
        l1.insertAfter(200,5000);
        l1.insertAfter(100,2000);
        l1.insertEnd(59);

        l1.displayItems();

        cout << endl;
        cout << "Deleted: " << l1.deleteBeg() << endl;
        cout << "Deleted: " << l1.deleteEnd() << endl;
        cout << "Deleted: " << l1.deleteAfter(100) << endl;

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

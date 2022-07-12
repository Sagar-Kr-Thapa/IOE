#include <iostream>
#include <string>

using namespace std;

class polynomial
{
    struct node
    {
        int coeff;
        int exponent;
        node *next = nullptr;
    };

public:
    node *head = nullptr;
    node *tail = nullptr;

    bool isEmpty() {return head == nullptr; }

    void insertBeg( int c, int e )
    {
        if( isEmpty() )
        {
            head = new node;
            head->coeff = c;
            head->exponent = e;
            
            tail = head;
        }
        else
        {
            node *temp = new node;
            temp->coeff = c;
            temp->exponent = e;
            temp->next = head;
            head = temp;
        }
    }

	void insert( int c, int e ) //Insert at End
	{
        if( isEmpty() )
        {
            insertBeg( c, e );
        }
        else
        {
            node *newNode = new node;
            newNode->coeff = c;
            newNode->exponent = e;

            tail->next = newNode;
            tail = newNode;
        }
	}

    void insertAfter( node *pointer, int c, int e)
    {
        node *newNode = new node;
        newNode->exponent = e;
        newNode->coeff = c;

        newNode->next = pointer->next;
        pointer->next = newNode; 

        if( newNode->next == head )
            head = newNode;
    }

    void deleteAfter( node *pointer )
    {
        node *temp = pointer->next;
        pointer->next = temp->next;

        if( temp==head )
            head = temp->next;

        delete temp;
    }

    void add( polynomial& b )
    {
        node *pointer1 = head;
        node *pointer2 = b.head;

        node *p1follower = new node{0};
        p1follower->next = pointer1;

        while( pointer1 != nullptr && pointer2 != nullptr )
        {
            if( pointer1->exponent > pointer2->exponent )
            {
                p1follower = pointer1;
                pointer1 = pointer1->next;

            }
            else if( pointer1->exponent == pointer2->exponent )
            {
                pointer1->coeff += pointer2->coeff;
                if( pointer1->coeff == 0 )
                {
                    pointer1 = pointer1->next;
                    deleteAfter(p1follower);
                }
                else
                {
                    p1follower = pointer1;
                    pointer1 = pointer1->next;
                }
                pointer2 = pointer2->next;
            }
            else
            {
                int c = pointer2->coeff;
                int e = pointer2->exponent;

                insertAfter( p1follower, c, e);
                
                if( p1follower->next != pointer1 )
                    p1follower = p1follower->next;

                pointer2 = pointer2->next;
            }
        }

        while( pointer2 != nullptr )
        {
            int c = pointer2->coeff;
            int e = pointer2->exponent;
            insert( c, e);

            pointer2 = pointer2->next;
        }
    }

    void display()
    {
        cout << endl << "SUM: " << endl;
        node *pointer = head;
        while( pointer != tail->next )
        {
            cout << "+(" << pointer->coeff << ")x^" << pointer->exponent;
            pointer =  pointer->next;
        }
    }

};

int main()
{
    polynomial p1, p2;
    int n;

    cout << "Enter degree of polynomial p1: ";
    cin >> n;

    for( int i = 0; i<=n; ++i )
    {
        int c;
        cout << "Coefficient of " << n-i << "th term: ";
        cin >> c;

        if( i == 0 && c == 0 )
        {
            cerr << "Coefficient of " << n-i << "can't be zero." << endl;
            return -1;
        }

        if( c!=0 )
            p1.insert(c , n-i);
    }

    cout << endl << "Enter degree of polynomial p2: ";
    cin >> n;

    for( int i = 0; i<=n; ++i )
    {
        int c;
        cout << "Coefficient of " << n-i << "th term: ";
        cin >> c;

        if( i == 0 && c == 0 )
        {
            cerr << "Coefficient of " << n-i << "can't be zero." << endl;
            return -1;
        } 

        if( c!=0 )
            p2.insert(c , n-i);
    }

    p1.add( p2 );
    p1.display();

    return 0;
}

#include <iostream>
#define MAX 10

using namespace std;

struct node
{
	int info;
	int next;
};


class List
{
private:
	node nodes[MAX];
	int head;
	int avail;
public:
	List()
	{

		int i = 0;

		for(i = 0; i < MAX-1; i++)
		{
			nodes[i].next = i+1;
		}

		nodes[i].next = -1;
		avail = 0;
		head = -1;

	}

	void insertBeg(int item)
	{
		if(avail == -1)
		{
			throw "[ERROR] : List is Full.\n";
		}
		else
		{
			int temp = head;
			head = avail;
			nodes[head].info = item;
			avail = nodes[head].next;
			nodes[head].next = temp;

			cout << "Inserted element at Beg: " << item << endl;
		}

	}

	void insertEnd(int item)
	{
		if(avail == -1)
		{
			throw "[ERROR] : List is Full.\n";
		}
		else
		{
			int i = head;

			while(nodes[i].next != -1)
			{
				i = nodes[i].next;
			}

			int temp = avail;
			nodes[i].next = avail;

			nodes[avail].info = item;
			avail = nodes[avail].next;
			nodes[temp].next = -1;

			cout << "Inserted element at End: " << item << endl;

		}
	}

	void insertAfter(int item, int value)
	{
		if(avail == -1)
		{
			throw "[ERROR] : List is Full.\n";
		}
		else
		{
			int i = head;

			while(nodes[i].info != value && i != -1 )
			{
				i = nodes[i].next;
			}

			int temp = avail;
			nodes[avail].info = item;
			avail = nodes[avail].next;

			nodes[temp].next = nodes[i].next;
			nodes[i].next = temp;

			cout << "Inserted element after " << value << ": " << item << endl;
		}
	}

	int deleteBeg()
	{

		if(head == -1)
		{
			throw "[ERROR]: List is Empty.\n";
		}
		else
		{
			int result = nodes[head].info;

			int temp1 = nodes[avail].next;

			nodes[avail].next = head;

			int temp2 = head;
			head = nodes[head].next;

			nodes[temp2].next = temp1;

			return result;

		}


	}

	int deleteEnd()
	{
		if(head == -1)
		{
			throw "[ERROR]: List is Empty.\n";
		}
		else
		{
			int i = head;

			while(nodes[nodes[i].next].next!= -1)
			{
				i = nodes[i].next;
			}

            int index = nodes[i].next;
			int result = nodes[index].info;

			int temp1 = nodes[avail].next;
			nodes[avail].next = nodes[index].next;

			nodes[i].next = -1;

			return result;
		}
	}

	int deleteAfter(int value)
	{
		if(head == -1 )
		{
			throw "[ERROR]: List is Empty.\n";
		}
		else
        {
            int i = head;

            while(nodes[i].info != value && i != -1 )
            {
                i = nodes[i].next;
            }

            int index = nodes[i].next;
            nodes[i].next = nodes[index].next;
            int result = nodes[index].info;

            int temp = nodes[avail].next;
            nodes[avail].next = index;
            nodes[index].next = temp;

            return result;
        }

	}

    void show()
    {
        int i=head;
        while( i != -1 ) {
            cout << nodes[i].info << ' ';
            i = nodes[i].next;
        }
        cout << endl;

    }

};

int main()
{
	try
	{
        List s;
        s.insertBeg(2);
        s.insertBeg(3);
        s.show();
        s.insertEnd(4);
        s.show();
        s.insertAfter(6,2);
        s.show();
        cout << "Deleted element: " << s.deleteAfter(2) << endl;
        s.show();
        cout << "Deleted element: " << s.deleteEnd() << endl;
        s.show();
        cout << "Deleted element: " << s.deleteBeg() << endl;
        s.show();
	}
	catch(const char* msg)
	{
		cerr << msg;
		return 1;
	}

    return 0;
}
#include<iostream>
using namespace std;

template<class T>
class Linkedlist
{
private:
	struct Node
	{
		T data;
		struct Node* next;
	};
	struct Node *head= NULL;
public:
	Linkedlist(){};

	void insertAtBeginning(T value)
	{
		struct Node *newNode= new Node;
		struct Node *temp=head;
		if(head==NULL)
		{
			newNode->data=value;
			newNode->next=newNode;
			head=newNode;
		}
		else
		{
			newNode->data=value;
			newNode->next=head;
			
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=newNode;
			head=newNode;
			
		}
	}
	void inserAtEnd(T value)
	{
		if(head==NULL)
		{
			insertAtBeginning(value);
		}
		else
		{
			struct Node* newNode=new Node;
			newNode->data=value;
			
			struct Node* temp=head;
			while(temp->next!=head)
				temp=temp->next;
			temp->next=newNode;
			newNode->next=head;
		}
	}

	void insertPosition(int p,T value)
	{
		
		if(head==NULL)
		{
			insertAtBeginning(value);
		}
		else
		{
			struct Node* newNode= new Node;
			struct Node* temp=head;
			newNode->data=value;
			for (int i=0;i<p-1;i++)
			{
				temp=temp->next;
			}
			newNode->next=temp->next;
			temp->next=newNode;
		}
	}
	void deleteAtBeginning()
	{
		if(head==NULL)
		{
			cout<<"The list is empty"<<endl;
		}
		else
		{
			struct Node *temp=head;
			struct Node*temp1=head;
			if(temp->next==head)
			{
				head=NULL;
				delete temp;
			}
			else
			{
				//head=temp->next;
				while(temp1->next!=head)
				{
					temp1=temp1->next;
				}
				temp1->next=temp->next;
				head=temp->next;
				delete temp;
			}
		}
	}
	void deleteAtEnd()
	{
		if(head==NULL)
		{
			cout<<"The list is empty"<<endl;
		}
		else
		{
			struct Node *temp1=head;
			struct Node *temp2;
			if(temp1->next==head)
			{
				head=NULL;
				delete temp1;
			}
			else
			{
				while(temp1->next!=head)
				{
					temp2=temp1;
					temp1=temp1->next;
				}
				temp2->next=head;
				delete temp1;
			}
		}
	}
	void deletePosition(int p)
	{
		struct Node *temp1=head;
		struct Node *temp2;
		if (head==NULL)
		{
			cout<<"The list is empty"<<endl;
		}
		else
		{
			for(int i=0;i<p;i++)
			{
				temp2=temp1;
				temp1=temp1->next;
			}
			temp2->next=temp1->next;
			delete temp1;
		}
	}
	void displaylist()
	{
		cout<<head->data<<endl;
		struct Node* temp=head->next;
		while(temp!=head)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
};

int main()
{
	Linkedlist<int> list;
	list.insertAtBeginning(1);
	list.insertAtBeginning(2);
	list.insertAtBeginning(3);
	list.inserAtEnd(4);
	list.inserAtEnd(5);
	list.inserAtEnd(6);
	list.insertPosition(1,1);
	list.insertPosition(2,2);
	list.insertPosition(3,3);
	list.insertPosition(4,4);
	list.insertPosition(5,5);
	list.insertPosition(6,6);
	cout<<"The list is"<<endl;
	list.displaylist();

	

	list.deleteAtEnd();
	list.deleteAtBeginning();
	list.deletePosition(3);

	cout<<endl<<"The list is"<<endl;
	list.displaylist();


	return 0;

}

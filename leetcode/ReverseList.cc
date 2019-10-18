


#include<iostream>
using namespace std;
struct Node
{
    int iValue;
    Node *next;
};
class Solutation
{
    public :
	static Node * fun_1(Node *head)
	{

	    Node *pre = head;
	    Node* pNext = head->next;
	    Node *temp = pNext->next;

	    pNext->next =pre;
	    pre->next=NULL;
	    while(temp != NULL)
	    {
		pre = pNext;
		pNext = temp;
		temp = pNext->next;
		pNext->next=pre;
	    }
	    head =pNext;
	    return head;
	
	
	
	}
	static void OutList(Node *head)
	{
	    Node *p=head;
	    while( p != NULL)
	    {
		cout<<p->iValue<<endl;
		p=p->next;
	    }
	}
};
int main(char*argv[],int argc)
{

    int num =0;
    Node *head = new Node;
    head->iValue =num;
    head->next=NULL;
    Node *temp = head;
    num++;
    while(num<6)
    {
	Node *p = new Node;
	p->iValue =num;
	p->next=NULL;
	temp->next = p;
	temp =temp->next;
	num++;
    }
    Solutation::OutList(head);
    head =Solutation::fun_1(head);
    Solutation::OutList(head);


return 0;
}

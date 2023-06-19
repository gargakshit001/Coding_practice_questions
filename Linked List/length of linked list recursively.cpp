#include<iostream>
using namespace std;

class Node
{
public:

    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        Node* next  = NULL;
    }
};


Node* takeInput()
{
    int data;
    cin>>data;

    Node* head = NULL;
    Node* tail = NULL;

    while(data!= -1)
    {
        Node* newNode = new Node(data);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

void print(Node* head)
{
    Node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

int length(Node* head)
{
    Node* temp = head;
    if(head == NULL)
    {
        return 0;
    }
    return 1 + length(temp->next);
}

int main()
{
    cout<<"enter data "<<endl;
    Node* head = takeInput();
    print(head);
    int l = length(head);

    cout<<endl<<"length of linked list is: "<<l;
    return 0;
}

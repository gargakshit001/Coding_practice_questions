#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node*next;

    Node(int data)
    {
        this->data = data;
        Node* next = NULL;
    }
};

Node* takeInput()
{
    int data;
    cin>>data;

    Node* head = NULL;
    Node* tail = NULL;

    while(data != -1)
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

Node* deleteNode_recursively(Node* head, int position)
{
    if(position == 0)
    {
        head = head->next;
        return head;
    }
    head->next = deleteNode_recursively(head->next, position - 1);
    return head;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    cout<<"enter elements "<<endl;
    Node* head = takeInput();
    print(head);

    cout<<endl<<"enter position to be deleted "<<endl;
    int p;
    cin>>p;

    head = deleteNode_recursively(head, p);
    print(head);

    return 0;
}

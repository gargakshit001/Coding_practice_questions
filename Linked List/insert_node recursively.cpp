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
        Node* next = NULL;
    }
};

Node*takeInput()
{
    int data;
    cin>>data;

    Node* head = NULL;
    Node* tail = NULL;
    while(data!=-1)
    {
        Node*newNode = new Node(data);
        if(head==NULL)
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

void print(Node*head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* insertNode_recursively(Node*head, int number, int position)
{
    Node*newNode = new Node(number);

    if(head == NULL || position == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    head->next = insertNode_recursively(head->next, number, position-1);
    return head;
}

int main()
{
    cout<<"enter data "<<endl;
    Node* head = takeInput();
    print(head);

    cout<<endl<<"enter data to be inserted "<<endl;
    int n;
    cin>>n;
    cout<<"enter position at which number is to be inserted "<<endl;
    int p;
    cin>>p;
    head = insertNode_recursively(head, n, p);
    print(head);

    return 0;
}

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
        Node*next = NULL;
    }
};

Node*takeinput()
{
    int data;
    cin>>data;

    Node*head = NULL;
    Node*tail = NULL;

    while(data != -1)
    {
        Node*newNode = new Node(data);

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

Node*deleteNode(Node*head, int position)
{
    Node* temp = head;

    int count = 0;

    if(position == 0)
    {
        head= head->next;
        return head;
    }

    while(temp != NULL && count<position-1)
    {
        temp = temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        temp->next = temp->next->next;
        delete temp->next;
    }
    return head;
}

void print(Node* head)
{
    Node* temp = head;

    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    cout<<"enter data "<<endl;
    Node*head = takeinput();
    print(head);
    cout<<endl<<"enter position to be deleted "<<endl;
    int n;
    cin>>n;
    head = deleteNode(head, n);
    print(head);

    return 0;
}

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
        Node*next = NULL;
    }
};


Node*takeinput()
{
    int data;
    cin>>data;

    Node*head= NULL;
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


Node*insertNode(Node*head, int number, int position)
{
    int count = 0;
    Node*newNode= new Node(number);

    Node* temp = head;

    if(position == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(temp != NULL && count < position-1)
    {
        temp = temp->next;
        count++;
    }

    if(temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;

}

void print(Node*head)
{
    Node*temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main()
{
    cout<<"enter elements "<<endl;
    Node*head = takeinput();
    print(head);
    cout<<endl<<"enter the number "<<endl;
    int n;
    cin>>n;
    cout<<"enter the position "<<endl;
    int p;
    cin>>p;

    head = insertNode(head ,n , p );
    print(head);
    return 0;
}

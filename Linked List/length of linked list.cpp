
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

Node* takeinput_better()
{
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data!=-1)
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
    Node*temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int length_ll(Node* head)
{
    int count = 0;
    Node* temp = head;

    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    cout<<"enter the numbers "<<endl;
    Node*head = takeinput_better();
    print(head);

    cout<<endl<<"length of linked list "<<endl;

    int length;
    length = length_ll(head);
    cout<<length<<endl;
    return 0;
}

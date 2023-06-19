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

Node* mergell(Node* head1, Node* head2)
{
    Node* finalhead = NULL;
    Node* finaltail = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(finalhead == NULL)
        {
            if(head1->data<=head2->data)
            {
                finalhead = new Node(head1->data);  //assign nhii krte pointers mein value..new node bnaate hai instead
                finaltail = finalhead;
                head1 = head1->next;
            }
            else
            {
                cout<<"YES ";
                finalhead = new Node(head2->data);
                finaltail = finalhead;
                head2 = head2->next;
            }
            continue;
        }
        if(head1->data<=head2->data)
        {
            finaltail->next = new Node(head1->data);
            finaltail = finaltail->next;
            head1 = head1->next;
        }
        else
        {
            finaltail->next = new Node(head2->data);
            finaltail = finaltail->next;
            head2 = head2->next;
        }
    }
    if(head1 == NULL)
    {
        while(head2 != NULL)
        {
            finaltail->next = new Node(head2->data);
            finaltail = finaltail->next;
            head2 = head2->next;
        }
    }
    else
    {
        while(head1 != NULL)
        {
            finaltail->next = new Node(head1->data);
            finaltail = finaltail->next;
            head1 = head1->next;
        }
    }
    return finalhead;
}

void print(Node*head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    cout<<"enter the elements of 1st linked list "<<endl;
    Node* head1 = takeInput();
    print(head1);
    cout<<endl;
    cout<<"enter the elements of 2nd linked list "<<endl;
    Node* head2 = takeInput();
    print(head2);
    cout<<"\n";

    Node* finalhead = mergell(head1, head2);
    print(finalhead);

    return 0;
}

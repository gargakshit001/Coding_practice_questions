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

class Pair
{
public:
    Node* head;
    Node* tail;
};

Pair reverse_ll_2(Node*head)
{
    if(head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverse_ll_2(head->next);

    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;

}

Node* reverse_ll_better(Node* head)
{
    return reverse_ll_2(head).head;
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
    cout<<"enter the elements "<<endl;
    Node* head = takeInput();
    print(head);

    cout<<endl;
    Node* reverse_head = reverse_ll_better(head);
    print(reverse_head);

    return 0;
}

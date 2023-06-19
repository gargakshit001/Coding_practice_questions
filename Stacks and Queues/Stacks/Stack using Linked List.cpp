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
        next = NULL;
    }
};

class StackusingLinkedList
{
Node*head;
int size;

public:

    StackusingLinkedList()
    {
        head = NULL;
        size = 0;
    }

bool isEmpty()
{
    return head == NULL;
}

void push(int element)
{
    Node* newNode = new Node(element);
    newNode->next = head;
    head = newNode;
    size++;
}


int pop()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty "<<endl;
        return INT_MIN;
    }
    int ans = head->data;

    Node* temp = head;
    head = head->next;

    temp->next = NULL;
    delete temp;
    size--;
    return ans;
}

int getsize()
{
    /*if(isEmpty())
    {
        return 0;
    }*/
    return size;
}


int top()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty "<<endl;
        return INT_MIN;
    }
    return head->data;
}
};

int main()
{
    StackusingLinkedList s;
    s.push(15);
    s.push(20);
    cout<<s.pop()<<endl;

    cout<<s.top()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;
}

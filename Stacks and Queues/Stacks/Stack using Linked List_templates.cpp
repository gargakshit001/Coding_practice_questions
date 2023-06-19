#include<iostream>
using namespace std;

template <typename T>

class Node
{
public:

    T data;
    Node* next;

    Node(T data)
    {
        this->data = data;
        Node<T>* next = NULL;
    }
};

template <typename T>

class StackusingLinkedList
{
    Node<T>* head;
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

    int getsize()
    {
        return size;
    }

    void push(T element)
    {
        Node<T>*newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty "<<endl;
            return INT_MIN;
        }
        T ans = head->data;

        Node<T>* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
        size--;
        return ans;
    }

    T top()
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
    StackusingLinkedList<int> s;

    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;

    cout<<s.top()<<endl;
    cout<<s.getsize()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;
}

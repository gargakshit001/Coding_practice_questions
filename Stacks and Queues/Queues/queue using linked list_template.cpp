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
class QueueusingLinkedList
{
    Node<T>* head;
    Node<T>* nextIndex;
    int size;

public:
    QueueusingLinkedList()
    {
        head = NULL;
        nextIndex = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
    int getSize()
    {
        return size;
    }

    T front()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty "<<endl;
            return 0;
        }
        return head->data;
    }

    void enQueue(T element)
    {
        Node<T>* newNode = new Node<T>(element);
        if(head == NULL)
        {
            head = newNode;
            nextIndex = newNode;
        }
        nextIndex->next = newNode;
        nextIndex = nextIndex->next;
        size++;
    }

    T deQueue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty "<<endl;
            return 0;
        }
        T ans = head->data;
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
        return ans;
    }
};

int main()
{
    QueueusingLinkedList<int> q;

    q.enQueue(10);
    q.enQueue(20);
    cout<<q.deQueue()<<endl;

    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;
}

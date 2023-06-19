#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next = NULL;

    Node(int data)
    {
        this->data = data;
        Node* next = NULL;
    }
};


class QueueusingLinkedList
{
    Node* head;
    Node* nextIndex;
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

    int front()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty "<<endl;
            return 0;
        }

        return head->data;
    }

    void enQueue(int element)
    {
        Node*newNode = new Node(element);
        if(head == NULL)
        {
            head = newNode;
            nextIndex = newNode;
        }
        nextIndex->next = newNode;
        nextIndex = nextIndex->next;
        size++;
    }

    int deQueue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty "<<endl;
            return 0;
        }
        int ans = head->data;
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
        return ans;
    }
};

int main()
{
    QueueusingLinkedList q;

    q.enQueue(10);
    q.enQueue(20);
    cout<<q.deQueue()<<endl;

    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;
}

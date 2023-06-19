#include<iostream>
using namespace std;
template <typename T>

class Node
{
public:

    T data;
    Node* next;

    Node(T data){
    this->data = data;
    Node<T>* next = NULL;
    }
};

template <typename T>

class StackusingLinkedList
{
    Node<T>* head;
public:

    StackusingLinkedList()
    {
        head == NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(T element)
    {
        Node<T>* newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
    }

    T pop()
    {
        Node<T>* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    T top()
    {
        return head->data;
    }
};

bool isBalanced(string expr)
{
    StackusingLinkedList<char> s;
    for(int i = 0; i < expr.length(); i++)
    {
        if(s.isEmpty())
        {
            s.push(expr[i]);
        }

        else if(s.top() == '(' && expr[i] == ')' || s.top() == '{' && expr[i] == '}' || s.top() == '[' && expr[i] == ']')
        {
            s.pop();
        }
        else
        {
            s.push(expr[i]);

        }
    }
    if(s.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string expr = "{(())}]";

    if(isBalanced(expr))
    {
        cout<<"Balanced "<<endl;
    }
    else
    {
        cout<<"Not Balanced "<<endl;
    }
    return true;
}

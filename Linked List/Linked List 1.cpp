#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        Node* next = NULL;
    }
};

void print(Node* head)
{
    Node* temp = head;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main()
{
    //statically
    Node n1(10);
    //Node* head = &n1;
    Node n2(20);
    n1.next = &n2;

    cout<<n1.data<<" "<<n2.data<<endl;

    //dynamically
    Node* n3 = new Node (10);
    Node* head = n3;
    Node* n4 = new Node (56);
    n3->next = n4;

    cout<<n3->data<<endl;
    cout<<n3->next->data<<endl;

    cout<<head->data<<endl;
    print(head);

    return 0;
}

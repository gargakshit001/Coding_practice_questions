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

int mid_ll(Node*head)
{
    int count = 0;
    Node* temp = head;
    while(temp!=NULL)
    {
        temp = temp->next;
        count++;
    }

    int count1, count2;
    count1 = count/2;
    count2 = 0;

    Node* temp1 = head;
    if(count1%2!=0)  //if length of linked list is odd
    {
        while(count2<count1)
        {
            temp1 = temp1->next;
            count2++;
        }
        return temp1->data;
    }
    else   //if length of linked list is even
    {
        while(count2<count1-1)
        {
            temp1 = temp1->next;
            count2++;
        }
        return temp1->data;   //here we need to find the first mid element
    }
}

int mid_ele(Node*head)
{
    Node* slow = head->next;
    Node* fast = slow->next;

    while(fast != NULL || fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    int mid_element = slow->data;
    return mid_element;
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

    int  mid_ele1 = mid_ll(head);
    cout<<endl<<"mid element of linked list is: "<<mid_ele<<endl;

    int mid_ele2 = mid_ele(head);
    cout<<mid_ele1;
    return 0;
}

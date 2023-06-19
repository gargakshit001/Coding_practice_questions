#include<bits/stdc++.h>
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

Node* mergeNode(Node* head)
{
  Node* ans = NULL;
  Node* ans1 = NULL;
  if(head == NULL || head->next == NULL)
  {
    return 0;
  }
  Node* temp = head;

  while(temp != NULL)
  {
    int res;
    if(temp->data != 0)
    {
      res += temp->data;
      temp = temp->next;
    }
    else
    {
      Node* temp1 = new Node(res);
      if(ans == NULL)
      {
        ans = temp1;
        ans1 = temp1;
      }
      else
      {
        ans1->next = temp1;
        ans1 = ans1->next;
      }
      res = 0;
      temp = temp->next;
    }
  }
  return ans->next;

}

void print(Node* head)
{
  Node* temp = head;
  while(temp != NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

int main()
{
  Node* head = takeInput();
  print(head);

  Node* merged = mergeNode(head);
  print(merged);
}

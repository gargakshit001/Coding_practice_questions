#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:

    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }

};


BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter root Data "<<endl;
    cin>>rootData;
    if(rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;

    return root;
}

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter data "<<endl;
    cin>>rootData;

    if(rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1)
        {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1)
        {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}


void printBinaryTree(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<": ";
    if(root->left != NULL)
    {
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right != NULL)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

void printBinaryTreeLevelWise(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<": ";

        if(front->left != NULL)
        {
            if(front->left->data != -1)
            {
                cout<<"L"<<front->left->data<<" ";
                pendingNodes.push(front->left);
            }
        }

        if(front->right != NULL)
        {
            if(front->right->data != -1)
            {
                cout<<"R"<<front->right->data<<" ";
                pendingNodes.push(front->right);
            }
        }
        cout<<endl;
    }
}

template <typename T>
class Node
{
public:
    T data;
    Node* next;

    Node(T data)
    {
        this->data = data;
        Node<int>* next = NULL;
    }
};

class Pair
{
public:
    Node<int>* head;
    Node<int>* tail;
};

Pair constructLL(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    Node<int>* newNode = new Node<int>(root->data);

    Pair leftans = constructLL(root->left);
    Pair rightans = constructLL(root->right);

    Pair ans;

    if(leftans.head == NULL && rightans.head == NULL)
    {
        ans.head = newNode;
        ans.tail = newNode;
    }

    else if(leftans.head == NULL && rightans.head != NULL)
    {
        ans.head = newNode;
        newNode->next = rightans.head;
        ans.tail = rightans.tail;
    }

    else if(leftans.head != NULL && rightans.head == NULL)
    {
        ans.head = leftans.head;
        leftans.tail->next = newNode;
        ans.tail = newNode;
    }
    else
    {
        ans.head = leftans.head;
        leftans.tail->next = newNode;
        newNode->next = rightans.head;
        ans.tail = rightans.tail;
    }

    return ans;
}

Node<int>* LLfromTree(BinaryTreeNode<int>* root)
{
    return constructLL(root).head;
}

void printNode(Node<int>* head)
{
    if(head == NULL)
    {
        return;
    }

    Node<int>* temp = head;
    while(temp->next != NULL)
    {
        cout<<temp->data<<" ";
    }
}

int main()
{
    ///4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int>* root = takeInputLevelWise();

    printBinaryTreeLevelWise(root);

    Node<int>* head = LLfromTree(root);

    printNode(head);

    return 0;
}

#include<iostream>
#include "BinaryTree Node.h"
#include<vector>
#include <queue>


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
            if(front->left->data !=-1)
            {
                cout<<"L"<<front->left->data<<" ";
                pendingNodes.push(front->left);
            }
        }
        if(front->right != NULL)
        {
            if(front->right->data !=-1)
            {
                cout<<"R"<<front->right->data<<" ";
                pendingNodes.push(front->right);
            }
        }
        cout<<endl;
    }
}



int numNodes(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);
}


int main()
{
    // 1 2 3 4 -1 -1 5 -1 -1 6 -1 -1 -1

    BinaryTreeNode<int>* root = takeInputLevelWise();

    printBinaryTreeLevelWise(root);

    cout<<"Number of Nodes: "<<numNodes(root);

    delete root;
    return 0;
}

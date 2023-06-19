#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
using namespace std;

class BST
{
    BinaryTreeNode<int>* root;

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            return NULL;
        }

        if(data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }

        else if(data < node->data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }

        else
        {
            if(node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }

            else if (node->left == NULL)
            {
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }

            else if (node->right == NULL)
            {
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }

            else
            {
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;

                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;
            }

        }

    }

public:
    void deleteData(int data)
    {
        root = deleteData(data, root);
    }

private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if(data < node->data)
        {
            node->left = insert(data, node->left);
        }

        else if(data >= node->data)
        {
            node->right = insert(data, node->right);
        }

        return node;
    }

public:
    void insert(int data)
    {
        this->root = insert(data, this->root);
    }

private:
    bool hasData(int data, BinaryTreeNode<int>* Node)
    {
        if(Node == NULL)
        {
            return false;
        }

        if(Node->data == data)
        {
            return true;
        }

        else if(data < Node->data)
        {
            hasData(data, Node->left);
        }

        else if(data >= Node->data)
        {
            hasData(data, Node->right);
        }
    }

public:

    bool isData(int data)
    {
        return hasData(data, root);
    }

private:
    void printBinaryTree(BinaryTreeNode<int>* root)
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

public:
    void printBinaryTree()
    {
        printBinaryTree(root);
    }

};

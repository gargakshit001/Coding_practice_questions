#include<iostream>
#include "BinaryTree Node.h"
#include<queue>

BinaryTreeNode<int>* takeInput()
{
    cout<<"Enter Data"<<endl;
    int rootData;
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
        cin>> rightChildData;

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

int height(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

pair<int, int> heightdiameter(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftans = heightdiameter(root->left);
    pair<int, int> rightans = heightdiameter(root->right);

    int lh = leftans.first;
    int ld = leftans.second;
    int rh = rightans.first;
    int rd = rightans.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}

int main()
{
    // 1 2 3 4 -1 -1 5 -1 -1 6 -1

    BinaryTreeNode<int>* root = takeInput();

    printBinaryTree(root);

    pair<int, int> p= heightdiameter(root);
    cout<<"Height: "<<p.first<<endl;
    cout<<"Diameter: "<<p.second<<endl;

    delete root;

    return 0;
}

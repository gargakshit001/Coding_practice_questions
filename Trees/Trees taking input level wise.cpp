#include<iostream>
#include "Tree Node.h"
#include<vector>
#include <queue>


TreeNode<int>* takeInput()
{
    cout<<"Enter Root Data "<<endl;
    int rootData;
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    cout<<"enter number of children "<<endl;
    int n;
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
}

TreeNode<int>* takeInputLevelWise()
{
    cout<<"Enter Root Data "<<endl;
    int rootData;
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;

        for(int i = 0; i < numChild; i++)
        {
            cout<<"Enter value of "<<i<<"th child of "<<front->data<<endl;
            int childData;
            cin>>childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;

}

void printTree(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<": ";
    for(int i = 0; i<root->children.size(); i++)
    {
        cout<<root->children[i]->data<<", ";
    }

    cout<<endl;

    for(int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}


void printTreeLevelWise(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<": ";

        for(int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
            if(i == front->children.size() - 1)
            {
                cout<<front->children[i]->data;
            }
            else
            {
                cout<<front->children[i]->data<<", ";
            }
        }
        cout<<endl;


    }
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();

    printTreeLevelWise(root);

    return 0;
}

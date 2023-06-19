#include<iostream>
#include "Tree Node.h"
#include<vector>
#include<queue>

TreeNode<int>* takeInput()
{
    cout<<"Enter root data "<<endl;
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
            cout<<"Enter data of "<<i<<"th child of "<<front->data<<endl;
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

int numNodes(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    int ans = 1;
    for(int i = 0; i < root->children.size(); i++)
    {
        ans = ans + numNodes(root->children[i]);
    }
    return ans;
}

void printatlevelK(TreeNode<int>* root, int k)
{
    if(root == NULL)
    {
        return;
    }
    if(k == 0)
    {
        cout<<root->data<<endl;
        return;
    }
    for(int i = 0; i < root->children.size(); i++)
    {
        printatlevelK(root->children[i], k-1);

    }
}

int main()
{
    TreeNode<int>* root = takeInput();;
    printTree(root);

    cout<<"Enter level "<<endl;
    int k;
    cin>>k;

    printatlevelK(root, k);
}

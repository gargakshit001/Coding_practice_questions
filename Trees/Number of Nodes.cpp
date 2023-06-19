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
    int ans = 1;

    for(int i = 0; i < root->children.size(); i++)
    {
        ans = ans + numNodes(root->children[i]);
    }
    return ans;
}

int main()
{
    TreeNode<int>* root = takeInput();

    printTree(root);

    int length = numNodes(root);
    cout<<"Number of Nodes of Tree are "<<length<<endl;
    /*int height = heightTree(root);
    cout<<"Height of Tree is: "<<height<<endl;*/

    return 0;
}

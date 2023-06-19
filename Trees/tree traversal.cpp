#include<iostream>
#include "Tree Node.h"
#include<vector>
#include<queue>

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


void preorder(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    for(int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}


void postorder(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    for(int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
        cout<<" ";
    }

    cout<<root->data;
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();

    preorder(root);
    cout<<endl;
    postorder(root);

    return 0;
}

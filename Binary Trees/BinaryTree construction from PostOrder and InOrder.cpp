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

BinaryTreeNode<int>* tree(int *postorder, int *inorder,int postS,int postE, int inS, int inE)
{
    if(postS > postE)
        return NULL;


    int rootData = postorder[postE];
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);

    int rootIndex = 0;
    for(int i = inS; i <= inE; i++)
    { if(rootData == inorder[i])
        {
            rootIndex = i;
            break;
        }
    }

    int lpostS = postS;    //left poststart
    int linS = inS;  //left instart
    int linE = rootIndex - 1;   //left inend
    int lpostE = linE - linS + lpostS; //left  postend

    int rpostS = lpostE + 1; //right poststart
    int rpostE = postE - 1;//  right postend
    int rinS = rootIndex + 1;  //right instart
    int rinE = inE;   //right inend

    root->left = tree(postorder,inorder,lpostS,lpostE,linS,linE);
    root->right = tree(postorder,inorder,rpostS,rpostE,rinS,rinE);

    return root;


}
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return tree (postorder, inorder, 0, postLength - 1, 0, inLength - 1);

}

int main()
{
    // 1 2 3 4 -1 -1 5 -1 -1 6 -1 -1 -1
    int in[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int post[] = {4, 8, 2, 5, 1, 6, 3, 7};
    BinaryTreeNode<int>* root = buildTree(in, 8, post, 8);
    //BinaryTreeNode<int>* root = takeInput();
    cout<<endl;
    printBinaryTree(root);

    delete root;

    return 0;
}

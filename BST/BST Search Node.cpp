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


BinaryTreeNode<int>* searchNode(BinaryTreeNode<int>* root, int element)
{
    if(root == NULL || element == root->data)
    {
        return root;
    }

    if(element < root->data)
    {
        searchNode(root->left, element);
    }

    if(element > root->data)
    {
        searchNode(root->right, element);
    }

}

int main()
{
    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int>* root = takeInputLevelWise();

    printBinaryTree(root);

    cout<<endl<<"Enter the element "<<endl;
    int ele;
    cin>>ele;
    BinaryTreeNode<int>* search = searchNode(root, ele);
    cout<<search->data<<endl;

    delete root;
    return 0;
}

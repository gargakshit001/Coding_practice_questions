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

vector<int>* getRoottoNodePath(BinaryTreeNode<int>* root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput = getRoottoNodePath(root->left, data);
    if(leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRoottoNodePath(root->right, data);
    if(rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }

    else
    {
        return NULL;
    }
}

int main()
{
    /// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int>* root = takeInputLevelWise();

    printBinaryTreeLevelWise(root);

    cout<<"Enter the element "<<endl;
    int ele;
    cin>>ele;
    vector<int>* output = getRoottoNodePath(root, ele);
    for(int i = 0; i < output->size(); i++)
    {
        cout<<output->at(i)<<" ";
    }

    delete output;

    return 0;
}

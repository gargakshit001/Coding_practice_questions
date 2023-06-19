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


///Method 1:
int maximum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return true;
    }

    bool output = (root->data > maximum(root->left)) && (root->data < minimum(root->right)) && isBST(root->left) && isBST(root->right);
    return output;
}

///Method 2:
class isBSTreturn
{
public:
    bool isBST;
    int maximum;
    int minimum;
};

isBSTreturn isBST2(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        isBSTreturn output;
        output.isBST = true;
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        return output;
    }

    isBSTreturn leftoutput = isBST2(root->left);
    isBSTreturn rightoutput = isBST2(root->right);

    int minimum = min(root->data, min(leftoutput.minimum, rightoutput.minimum));
    int maximum = max(root->data, max(leftoutput.maximum, rightoutput. maximum));

    bool isBSTFinal = (root->data > leftoutput.maximum) && (root->data <= rightoutput.minimum) && leftoutput.isBST && rightoutput.isBST;

    isBSTreturn output;
    output.isBST = isBSTFinal;
    output.maximum = maximum;
    output.minimum = minimum;

    return output;
}

///Method 3:
bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data < min || root->data > max)
    {
        return false;
    }

    bool isLeftOK = isBST3(root->left, min, root->data - 1);
    bool isRightOK = isBST3(root->right, root->data + 1, max);

    return isLeftOK && isRightOK;
}

int main()
{
    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int>* root = takeInputLevelWise();

    printBinaryTreeLevelWise(root);

    cout<<endl<<isBST(root)<<endl;
    cout<<isBST3(root)<<endl;

    return 0;
}

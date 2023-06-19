#include<iostream>
using namespace std;

class StackusingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackusingArray(int totalsize)
    {
        data = new int[totalsize];
        nextIndex = 0;
        capacity = totalsize;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        /*if(nextIndex == 0)
        {
            return true;
        }
        else
        {
            return false;
        }*/

        return nextIndex == 0;
    }

    void push(int element)
    {
        if(nextIndex == capacity)
        {
            cout<<"Stack is Full "<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty "<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty "<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};

int main()
{
    StackusingArray s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.top()<<endl;
    cout<<s.size()<<endl;

    cout<<s.isEmpty()<<endl;

    return 0;

}

#include<iostream>
using namespace std;
#include<climits>

class StackusingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:

    StackusingArray()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int element)
    {
        if(nextIndex == capacity)
        {
            int *newdata = new int[2*capacity];
            for(int i = 0; i<capacity; i++)
            {
                newdata[i] = data[i];
            }
            delete []data;
            data = newdata;
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

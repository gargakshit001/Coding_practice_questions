#include<iostream>
using namespace std;

template <typename T>

class StackusingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:

    StackusingArray()
    {
        data = new T[4];
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

    void push(T element)
    {
        if(nextIndex == capacity)
        {
            T *newdata = new T[2*capacity];
            for(int i=0; i<capacity; i++)
            {
                newdata[i] = data[i];
            }
            delete []data;
            data = newdata;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty "<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty "<<endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};


int main()
{
    StackusingArray <int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout<<"Int: "<<endl;
    cout<<s1.top()<<endl;

    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;

    cout<<s1.top()<<endl;
    cout<<s1.size()<<endl;

    cout<<s1.isEmpty()<<endl;

    cout<<"Char: "<<endl;

    StackusingArray <char> s2;

    s2.push(100);
    s2.push(101);
    s2.push(102);
    s2.push(103);
    s2.push(104);

    cout<<s2.top()<<endl;

    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;

    cout<<s2.top()<<endl;
    cout<<s2.size()<<endl;

    cout<<s2.isEmpty()<<endl;

    return 0;
}

#include<iostream>
using namespace std;

template <typename T>

class QueueusingArray
{
    T* data;
    int nextIndex;
    int firstIndex;
    int size, capacity;

public:

    QueueusingArray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enQueue(T element)
    {
       if(size == capacity)
       {
           cout<<"Queue is Full "<<endl;
       }
       data[nextIndex] = element;
       nextIndex = (nextIndex+1)%capacity;
       if(firstIndex == -1)
       {
           firstIndex++;
           return;
       }
       size++;
    }

    T front()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty "<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    T deQueue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty "<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if(size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;

    }
};

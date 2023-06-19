#include<iostream>
using namespace std;

template <typename T>

class QueueusingArray
{
    T* data;
    int firstIndex, nextIndex, capacity, size;

public:

    QueueusingArray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        capacity = s;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
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

    int getSize()
    {
        return size;
    }

    void Enqueue(T element)
    {
        if(size == capacity)
        {
            T* newData= new T[2*capacity];
            int j = 0;
            for(int i = firstIndex; i<capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for(int i = 0; i< capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete []data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1)%capacity;
        if(firstIndex == -1)
        {
            firstIndex++;
        }
        size++;
    }

    T deQueue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty "<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size == 0)
        {
            nextIndex = 0;
            firstIndex = -1;
        }
        return ans;
    }
};

int main()
{
    QueueusingArray<int> q(5);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);

    cout<<q.front()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;
}

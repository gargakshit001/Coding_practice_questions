#include<iostream>
using namespace std;

#include "queue using array.h"
#include<queue>

/*
Since here queue is used as a template,
we will call its object as queue<int> q1
When using In-built functions:

enQueue(T element) -> q1.push(10)
T deQueue() -> void pop()
T front() -> T front()
getSize() -> size()
isEmpty() -> bool empty()
*/

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;

    return 0;
}

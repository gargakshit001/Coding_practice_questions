#include<iostream>
using namespace std;
#include "Stack using Dynamic Array.h"
#include <stack>

/*
Since here stack is used as a template,
we will call its object as stack<int> s1
When using In-built functions:

push(T element) -> s1.push(10)
T pop() -> void pop()
T top() -> T top()
size -> size()
isEmpty() -> bool empty()
*/

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;

    return 0;
}

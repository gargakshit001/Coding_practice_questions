#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue
{
  vector<int> pq;

public:
  PriorityQueue()
  {
  }

  bool isEmpty()
  {
    return pq.size() == 0;
  }

  int getSize()
  {
    return pq.size();
  }

  int getMin()
  {
    if(isEmpty())
    {
      return 0;
    }

    return pq[0];
  }

  void insert(int element)
  {
    pq.push_back(element);

    int childIndex = pq.size() - 1;

    while(childIndex > 0)
    {
      int parentIndex = (childIndex - 1) / 2;

      if(pq[childIndex] < pq[parentIndex])
      {
        int temp = pq[childIndex];
        pq[childIndex] = pq[parentIndex];
        pq[parentIndex] = temp;
      }
      else
      {
        break;
      }

      childIndex = parentIndex;
    }
  }

  int removeMin()
  {
    if(isEmpty())
    {
      return 0;
    }

    int ans = pq[0];
    pq[0] = pq[pq.size() - 1];
    pq.pop_back();

    int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;

    while(leftChildIndex < pq.size())
    {
      int minIndex = parentIndex;
      if(pq[minIndex] > pq[leftChildIndex])
      {
        minIndex = leftChildIndex;
      }
      if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex])
      {
        minIndex = rightChildIndex;
      }
      if(minIndex == parentIndex)
      {
        break;
      }
      int temp = pq[minIndex];
      pq[minIndex] = pq[parentIndex];
      pq[parentIndex] = temp;

      parentIndex = minIndex;
      leftChildIndex = 2 * parentIndex + 1;
      rightChildIndex = 2 * parentIndex + 2;
    }

    return ans;
  }
};

int main()
{
  PriorityQueue pq;

  pq.insert(109);
  pq.insert(101);
  pq.insert(102);
  pq.insert(103);
  pq.insert(104);
  pq.insert(105);
  pq.insert(106);

  cout<<pq.getSize()<<endl;
  cout<<pq.getMin()<<endl;

  while(!pq.isEmpty())
  {
    cout<<pq.removeMin()<<" ";
  }

  cout<<endl;

  return 0;
}

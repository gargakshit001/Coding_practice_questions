#include<iostream>
using namespace std;

class Egde
{
public:
  int source;
  int destination;
  int weight;

};

bool compare(Edge e1, Edge e2)
{
  return e1.weight < e2.weight;
}

int findParent(int v, int* parent)
{
  if(parent[v] == v)
  {
    return v;
  }
}

void kruskal(Edge* input, int n, int e)
{
  //Sort the input array in ascending order based on weights
  sort(input, input + e, compare);

  Edge* output = new Edge[n - 1];

  int* parent = new parent[n];
  for(int i = 0; i < n; i++)
  {
    parent[i] = i;
  }

  int count = 0;
  int i = 0;
  while(count < n - 1)
  {
    Edge currentEdge = input[i];

    //Check if we can add the current Edge in the MST or not
    int sourceParent = findParent(currentEdge.source, parent);
    int destinationParent = findParent(currentEdge.destination, parent);

    if(sourceParent != destinationParent)
    {
      output[count] = currentEdge;
      count++;
      parent[sourceParent] = destinationParent;
    }
    i++;
  }
}

int main()
{
  int n, e;
  cin>>n>>e;
  Edge* input = new Edge[e];
  for(int i = 0; i < n; i++)
  {
    int s, d, w;
    cin>>s>>d>>w;
    input[i].source = s;
    input[i].destination = d;
    input[i].weight = w;
  }

  kruskal(Edge, n, e);
}

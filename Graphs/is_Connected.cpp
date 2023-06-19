#include<iostream>
#include<queue>
using namespace std;

void BFS(int** edges, int n, int sv, bool* visited)
{
  queue<int> pendingVertices;
  pendingVertices.push(sv);
  visited[sv] = true;

  while(!pendingVertices.empty())
  {
    int currentVertex = pendingVertices.front();
    pendingVertices.pop();

    for(int i = 0; i < n; i++)
    {
      if(edges[currentVertex][i] == 1 && !visited[i])
      {
        pendingVertices.push(i);
        visited[i] = true;
      }
    }
  }
}

int main()
{
  int n, e;
  cin>>n>>e;

  int** edges = new int* [n];
  for(int i = 0; i < n; i++)
  {
    edges[i] = new int[n];
    for (size_t j = 0; j < n; j++)
    {
      edges[i][j] = 0;
    }
  }

  for(int i = 0; i < e; i++)
  {
    int f, s;
    cin>>f>>s;
    edges[f][s] = 1;
    edges[s][f] = 1;
  }

  bool* visited = new bool[n];
  for(int i = 0; i < n; i++)
  {
    visited[i] = false;
  }

  BFS(edges, n, 0, visited);
  for(int i = 0; i < n; i++)
  {
    if(!visited[i])
    {
      cout<<"false"<<endl;
      break;
    }
    if(i == n)
    {
      cout<<"true"<<endl;
    }
  }

  delete []visited;
  for(int i = 0; i < n; i++)
  {
    delete []edges[i];
  }

  delete []edges;
}

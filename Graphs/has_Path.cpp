#include<iostream>
using namespace std;

bool hasPath(int** edges, int n, bool* visited, int se, int ee)
{
  if(edges[se][ee] == 1)
  {
    return true;
  }

  visited[se] = true;
  bool result = false;

  for(int i = 0; i < n; i++)
  {
    if(edges[se][i] == 1 && !visited[i])
    {
      result = hasPath(edges, n, visited, i, ee);
    }

    if(result == true)
    {
      return true;
    }
  }

  return result;
}

int main()
{
  int n, e;
  cin>>n>>e;

  int** edges = new int* [n];
  for(int i = 0; i < n; i++)
  {
    edges[i] = new int[n];
    for(int j = 0; j < n; j++)
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

  int se, ee;
  cin>>se>>ee;

  if(hasPath(edges, n, visited, se, ee))
  {
    cout<<"true";
  }
  else
  {
    cout<<"false";
  }

  delete []visited;
  for(int i = 0; i < n; i++)
  {
    delete[] edges[i];
  }
  delete []edges;
}

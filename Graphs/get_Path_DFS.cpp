#include<iostream>
#include<vector>
using namespace std;

bool hasPath(int** edges, int n, bool* visited, int sv, int ev)
{
  if(edges[sv][ev] == 1)
  {
    return true;
  }

  visited[sv] = true;
  bool ans = false;

  for(int i = 0; i < n; i++)
  {
    if(edges[sv][i] == 1 && !visited[i])
    {
      ans = hasPath(edges, n, visited, i, ev);
    }

    if(ans == true)
    {
      return true;
    }
  }

  return ans;
}

bool getPathDFS(int** edges, int n, bool* visited, int sv, int ev, vector<int>& v)
{
  if(sv == ev)
  {
    v.push_back(sv);
    return true;
  }

  visited[sv] = true;
  bool ans = false;

  for(int i = 0; i < n; i++)
  {
    if(edges[sv][i] == 1 && !visited[i])
    {
      ans = getPathDFS(edges, n, visited, i, ev, v);
    }

    if(ans == true)
    {
      v.push_back(sv);
      return true;
    }
  }

  return ans;
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

  int sv, ev;
  cin>>sv>>ev;

  if(hasPath(edges, n, visited, sv, ev))
  {
    cout<<"true"<<endl;
  }
  else
  {
    cout<<"false"<<endl;
  }

  for(int i = 0; i < n; i++)
  {
    visited[i] = false;
  }

  vector<int> v;
  if(getPathDFS(edges, n, visited, sv, ev, v))
  {
    for(auto i : v)
    {
      cout<<i<<" ";
    }
  }

  delete []visited;
  for(int i = 0; i < n; i++)
  {
    delete []edges[i];
  }
  delete []edges;
}

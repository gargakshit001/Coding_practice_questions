#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<char>>& board, string word, int i, int j, int si)
{
  if(si == word.length())
  {
    return true;
  }

  if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] != word[si])
  {
    return false;
  }

  board[i][j] = '@'; // to mark as visited

  bool status = DFS(board, word, i + 1, j, si + 1) || DFS(board, word, i, j + 1, si + 1) || DFS(board, word, i, j - 1, si + 1) || DFS(board, word, i - 1, j, si + 1);

  board[i][j] = word[si];
  return status;
}

bool isWordExist(vector<vector<char>>& board, string word)
{
  if(word == "")
  {
    return false;
  }

  for(int i = 0; i < board.size(); i++)
  {
    for(int j = 0; j < board[i].size(); j++)
    {
      if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
      {
        return true;
      }
    }
  }

  return false;
}

int main()
{
  int m,n,i,j;
  cin>>n>>m;
  vector<vector<char>> board(n, vector<char>(m, '*'));
  //char s;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      cin>>board[i][j];
    }
  }

  string word;
  cin>>word;
  bool ans = isWordExist(board, word);
  if(ans)
  {
    cout<<1;
  }
  else
  {
    cout<<0;
  }

  return 0;
}

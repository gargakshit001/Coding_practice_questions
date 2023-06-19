#include<bits/stdc++.h>
using namespace std;

int evaluatePostfix(string s)
{
  stack<int> st;

  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == ' ')
    {
      continue;
    }
    else if(isdigit(s[i]))
    {
      int num = 0;
      while(isdigit(s[i]))
      {
        num = num * 10 + (int)(s[i] - '0');
        i++;
      }
      i--;

      st.push(num);
    }

    else
    {
      int operand2 = st.top();
      st.pop();
      int operand1 = st.top();
      st.pop();

      switch (s[i])
      {
        case '+':
        st.push(operand1 + operand2);
        break;
        case '-':
        st.push(operand1 - operand2);
        break;
        case '*':
        st.push(operand1 * operand2);
        break;
        case '/':
        st.push(operand1 / operand2);
        break;
        case '^':
        st.push(pow(operand1, operand2));
        break;
      }
    }
  }

  return st.top();
}

//GFG
int EvaluatePostfix(string s)
{
  int ans = 0;
  stack<int> st;
  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] >= '0' && s[i] <= '9')
    {
      st.push(s[i] - '0');
    }
    else
    {
      int operand2 = st.top();
      st.pop();
      int operand1 = st.top();
      st.pop();
      switch (s[i])
      {
        case '+':
        st.push(operand1 + operand2);
        break;
        case '-':
        st.push(operand1 - operand2);
        break;
        case '*':
        st.push(operand1 * operand2);
        break;
        case '/':
        st.push(operand1 / operand2);
        break;
        case '^':
        st.push(pow(operand1, operand2));
        break;
      }
    }
  }

  return st.top();
}

int main()
{
  string s = "100 200 + 2 / 5 * 7 +";
  cout<<evaluatePostfix(s);
  return 0;
}

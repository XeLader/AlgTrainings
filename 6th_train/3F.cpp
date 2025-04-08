#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  string input;
  unsigned int n;
  char prior[5];
  cin >> n;
  cin >> prior;
  cin >> input;
  stack<char> st;
  string output(n, ' ');
  char ch;
  unsigned int i, j = 0;
  for (i = 0; i < input.length(); i++)
  {
    ch = input[i];
    if (ch == '(' or ch == '[')
      st.push(ch);
    else
      st.pop();
    output[i] = ch;
  }
  for (i = input.length(); i < n; i++)
  {
    if (n - i - 1 <= st.size())
    {
      while (i < n)
      {
        if (st.top() == '(')
          output[i] = ')';
        else
          output[i] = ']';
        st.pop();
        i++;
      }
      break;
    }
    j=0;
    while (j < 4)
    {
      if(prior[j] == ')')
      {
        if (st.empty())
          j++;
        else if (st.top() == '(') 
        {
          output[i] = ')';
          st.pop();
          break;
        }
        else j++;
      }
      else if(prior[j] == ']')
      {
         if (st.empty())
           j++;
         else if (st.top() == '[') 
         {
          output[i] = ']';
          st.pop();
          break;
        }
        else j++;
      }
      else
      {
         output[i] = prior[j];
         st.push(prior[j]);
         break;
      }
    }
  }
  cout << output;
  
}

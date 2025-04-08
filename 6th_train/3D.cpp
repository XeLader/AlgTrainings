#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  string normal;
  vector<string> postfix = {};
  stack<char> prepPostfix;
  getline(cin, normal);
  
  char ch;
  for (unsigned int i = 0; i < normal.length(); i++)
  {
    ch = normal[i];
    if (ch == ' ')
      continue;
    else if (ch >= '0' and ch <= '9')
    {
      string digit;
      do
      {
        digit.push_back(ch);
        i++;
        ch = normal[i];
      } while (ch >= '0' and ch <= '9' and i < normal.length());
      postfix.push_back(digit);
      if (i==normal.length())
        break;
    }
    else 
    switch (ch)
    {
      case '*':
        postfix.push_back(string(1,'*'));
      break;
      
      case '+':
        postfix.push_back(string(1,'+'));
      break;
      
      case '-':
        postfix.push_back(string(1,'-'));
      break;
    }
  }
  stack<int> calc;
  
  for (unsigned int i = 0; i < postfix.size(); i++)
  {
    if (postfix[i] == string(1,'+') or postfix[i] == string(1,'-') or
        postfix[i] == string(1,'*'))
    {
        char oper = postfix[i][0];
        int b =  calc.top();
        calc.pop();
        int a = calc.top();
        calc.pop();
        switch (oper)
        {
          case '+':
            calc.push(a+b);
            break;
          
          case '-':
            calc.push(a-b);
            break;
            
          case '*':
            calc.push(a*b);
            break;
        }
    }
    else
      calc.push(stoi(postfix[i]));
  }
  cout << calc.top();
}


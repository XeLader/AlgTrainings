#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  string input;
  vector<char> postfix = {};
  stack<char> prepPostfix;
 
  char ch;
  string normal;
  getline(cin, normal);
  
  for (unsigned int i = 0; i < normal.length(); i++)
  {
    ch = normal[i];
    if (ch >= '0' and ch <= '1')
    {
      postfix.push_back(ch);
    }
    else switch (ch)
    {
      case '!':
        while (!prepPostfix.empty())
        {
          if (prepPostfix.top() == '!')
          {
            postfix.push_back(prepPostfix.top());
            prepPostfix.pop();
          }
          else break;
        }
        prepPostfix.push(ch);
      break;
      
      case '&':
        while (!prepPostfix.empty())
        {
          if (prepPostfix.top() == '&' or prepPostfix.top() == '!') 
          {
            postfix.push_back(prepPostfix.top());
            prepPostfix.pop();
          }
          else break;
        }
        prepPostfix.push(ch);
      break;
      
      case '|':
        while (!prepPostfix.empty())
        {
          if (prepPostfix.top() != '(') 
          {
            postfix.push_back(prepPostfix.top());
            prepPostfix.pop();
          }
          else break;
        }
        prepPostfix.push(ch);
        break;
      
      case '^':
        while (!prepPostfix.empty())
        {
          if (prepPostfix.top() != '(') 
          {
            postfix.push_back(prepPostfix.top());
            prepPostfix.pop();
          }
          else break;
        }
        prepPostfix.push(ch);
        break;
          
      case '(':
        prepPostfix.push(ch);
      break;
      
      case ')':
        while (!prepPostfix.empty())
        {
          if (prepPostfix.top() != '(')
          {
            postfix.push_back(prepPostfix.top());
            prepPostfix.pop();
          }
          else break;
        }
        if (!prepPostfix.empty())
            prepPostfix.pop(); 
      break;
      
      default:
        return 0;       
    }
  }
  
  while (!prepPostfix.empty())
  {
    postfix.push_back(prepPostfix.top());
    prepPostfix.pop();
  }
  
  stack<bool> calc;
  
  for (unsigned int i = 0; i < postfix.size(); i++)
  {
    if (postfix[i] < '0' or postfix[i] > '1')
    {
        char oper = postfix[i];
        if (oper != '!')
        {
          bool b = calc.top();
          calc.pop();
          bool a = calc.top();
          calc.pop();
          switch (oper)
          {
            case '&':
              calc.push(a&&b);
            break;
          
            case '|':
              calc.push(a||b);
            break;
            
            case '^':
              calc.push(a!=b);
            break;
          }
        }
        else
        {
          bool a = calc.top();
          calc.pop();
          calc.push(!a);
        }
    }
    else
      calc.push((bool)(postfix[i] - '0'));
  }
  
  if (calc.size() == 1)
    cout << calc.top();
  else
    return 0;   
}


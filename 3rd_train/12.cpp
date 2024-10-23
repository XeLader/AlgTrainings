#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  string input;
  vector<string> postfix = {};
  stack<char> prepPostfix;
  getline(cin, input);
  enum {NUM, OPER, BREKET_CLOSE, BREKET_OPEN} lc = BREKET_OPEN;
  
  char ch;
  string normal;
  for (unsigned int i = 0; i < input.length(); i++)
  {
    ch = input[i];
    if (ch == ' ')
      continue;
    else if (ch >= '0' and ch <= '9')
    { 
      if (lc != NUM)
      {
        
        while (i < input.length())
        { 
          if (ch >= '0' and ch <= '9')
            normal.push_back(ch);
          else
          {
            i--;
            break;
          }
          i++;
          ch = input[i];
        } 
      }
        
      else
      {
        cout << "WRONG";
        return 0;
      }
      lc = NUM;
    }
    else if (ch == '+' or ch == '-' or ch == '*')
    {

      if (lc == NUM or lc == BREKET_CLOSE)
      {
        normal.push_back(ch);
      }
      else if((ch == '+' or ch == '-') and lc == BREKET_OPEN)
      {
        normal.push_back('0');
        normal.push_back(ch);
      }
      else
      {
        cout << "WRONG";
        return 0;
      }
      lc = OPER;
    }
    else if (ch == '(')
    {
      if (lc == BREKET_CLOSE or lc == NUM)
      {
        normal.push_back('*');
        normal.push_back(ch);
      }
      else
      {
        normal.push_back(ch);
      }
      lc = BREKET_OPEN;
    }
    else if (ch == ')')
    {
      if (lc != OPER and lc != BREKET_OPEN)
        normal.push_back(ch);
      else
      {
        cout << "WRONG";
        return 0;
      }
      lc = BREKET_CLOSE;
    }
    else
    {
      cout << "WRONG";
      return 0;
    }
  }
  
  input.clear();
  
  for (unsigned int i = 0; i < normal.length(); i++)
  {
    ch = normal[i];
    if (ch >= '0' and ch <= '9')
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
    switch (ch)
    {
      case '*':
        while (!prepPostfix.empty())
        {
          if (prepPostfix.top() == '*' or prepPostfix.top() == '/')
          {
            postfix.push_back(string(1,prepPostfix.top()));
            prepPostfix.pop();
          }
          else break;
        }
        prepPostfix.push(ch);
      break;
      
      case '+':
        while (!prepPostfix.empty())
        {
          if (prepPostfix.top() != '(') 
          {
            postfix.push_back(string(1,prepPostfix.top()));
            prepPostfix.pop();
          }
          else break;
        }
        prepPostfix.push(ch);
      break;
      
      case '-':
        while (!prepPostfix.empty())
        {
          if (prepPostfix.top() != '(') 
          {
            postfix.push_back(string(1,prepPostfix.top()));
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
            postfix.push_back(string(1,prepPostfix.top()));
            prepPostfix.pop();
          }
          else break;
        }
        if (!prepPostfix.empty())
            prepPostfix.pop(); 
        else 
        {
          cout << "WRONG";
          return 0;  
        }
      break;
      
      default:
        cout << "WRONG";
        return 0;       
    }
  }
  while (!prepPostfix.empty())
  {
    if (prepPostfix.top() != '(')
    {
      postfix.push_back(string(1,prepPostfix.top()));
      prepPostfix.pop();
    }
    else
    {
      cout << "WRONG";
      return 0;     
    }
  }
  
  stack<int> calc;
  
  for (unsigned int i = 0; i < postfix.size(); i++)
  {
    if (postfix[i] == string(1,'+') or postfix[i] == string(1,'-') or
        postfix[i] == string(1,'*'))
    {
      if (calc.size() >= 2)
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
      {
        cout << "WRONG";
        return 0;     
      }
    }
    else
      calc.push(stoi(postfix[i]));
  }
  
  if (calc.size() == 1)
    cout << calc.top();
  else
  {
        cout << "WRONG";
        return 0;   
  }
    
  
}


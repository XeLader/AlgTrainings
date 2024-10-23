#include "stdio.h"
#include <stack>
#include <set>
#include <array>

using namespace std;

int main()
{
  int M, N, a, b;
  
  stack<array<int,2>> OS, temp;
  
  
  scanf("%d\n%d", &M, &N);
  
  if (N > 0)
  {
    scanf("%d %d", &a, &b);
    OS.push({a,b});
  }
  
  for(int i = 1; i < N; i++)
  {
    scanf("%d %d", &a, &b);
    
    if(OS.top()[1] == a)
    {
      OS.pop();
      OS.push({a,b});
    }
    else if(OS.top()[1] > a)
    {
      while(!OS.empty())
      {
        if (OS.top()[1] >= a)
        {
          temp.push(OS.top());
          OS.pop(); 
        }
        else break;
      }
      
      OS.push({a,b});
      
      while (!temp.empty())
      {
        if (temp.top()[0] <= b) 
          temp.pop();
        else break;
        
      }
      
      while (!temp.empty())
      {
        OS.push(temp.top());
        temp.pop(); 
      }
    }
    else
      OS.push({a,b});
  }
  
  printf("%ld", OS.size());
  
}

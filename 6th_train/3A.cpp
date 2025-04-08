#include "stdio.h"
#include "stack"

using namespace std;

int main()
{
  char a[100001], temp; 
  scanf("%s", a);
  unsigned int i = 0;
  stack<char> st;
  while (a[i]!= '\0')
  {
    if (a[i] == '(' or a[i] == '{' or a[i] == '[')
    {
      st.push(a[i]);
    }
    else
    {
      if( !st.empty())
      {
        temp = st.top();
        st.pop();
      }
      else 
      {
          printf("no");
          return 0;
      }
      switch (a[i])
      {
        case ')':
          if (temp != '(')
          {
            printf("no");
            return 0;
          };
        break;
    
        case '}':
          if (temp != '{')
          {
            printf("no");
            return 0;
          };
        break;
        case ']':
         if (temp != '[')
          {
            printf("no");
            return 0;
          };
        break;
      }
    }
    i++;
  }
  if (st.empty()) printf("yes");
  else printf("no");
}

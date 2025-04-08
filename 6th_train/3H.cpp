#include "iostream"
#include "stdlib.h"

using namespace std;

class stack
{
  public:
  stack(unsigned int);
  void push(unsigned long long);
  unsigned long long pop();
  unsigned long long top();
  unsigned long long sum(unsigned int);
  
  private:
  unsigned long long *val, *ps;
  unsigned i = 0; 
};

stack::stack(unsigned int n)
{
  val = (unsigned long long*)calloc(n, sizeof(unsigned long long));
  ps = (unsigned long long*)calloc(n + 1, sizeof(unsigned long long));
}

unsigned long long stack::top()
{
  return val[i-1];
}

unsigned long long stack::pop()
{
  i--;
  return val[i];
}

 void stack::push(unsigned long long v)
 {
   val[i] = v;
   ps[i + 1] = ps[i] + v;  
   i++;
 }
 
 unsigned long long stack::sum(unsigned int n)
 {
   return  ps[i] - ps[i-n];
 };
 
 
int main()
{
  unsigned int n, itemp;
  unsigned long long lltemp;
  cin >> n;
  stack st(n);
  char act;
  for (unsigned int i = 0 ; i < n; i++)
  {
    cin >> act;
    switch (act)
    {
      case '+':
        cin >> lltemp;
        st.push(lltemp);
        break;
        
      case '-':
        cout << st.pop() << '\n';
        break;
      
      case '?':
        cin >> itemp;
        cout << st.sum(itemp) << '\n';
        break;
    }
  }
}
 
 
 


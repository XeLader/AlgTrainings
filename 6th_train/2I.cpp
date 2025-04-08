#include "iostream"
#include "stdlib.h"
#include "algorithm"

using namespace std;

struct Pair{ 
  int n;
  unsigned long long v;
};

bool comp(Pair, Pair);

int main()
{
  int n;
  bool *l;
  Pair *a, *b;
  
  cin >> n;
  
  a = (Pair*)calloc(n, sizeof(Pair));
  b = (Pair*)calloc(n, sizeof(Pair));
  l = (bool*)calloc(n, sizeof(bool));
  
  for (int i = 0; i < n; i ++)
  {
    cin>>a[i].v;
    a[i].n = i;
  }
  for (unsigned long long i = 0, temp; i < n; i ++)
  {
    cin>>temp;
    b[i].n = i;
    b[i].v = a[i].v;
    a[i].v = a[i].v * 10000000000 + temp;
    b[i].v = temp * 10000000000 + b[i].v;
  }
  sort (a, a+n, comp);
  sort (b, b+n, comp);
  
  bool p;
  int ap = 0, bp = 0;
  for (int i = 0; i < n; i ++)
  {
     cin>> p;
     if (p)
     {
       while (l[b[bp].n])
         bp++;
       cout << b[bp].n + 1 << ' ';
       l[b[bp].n ] = true;
     }
     else
     {
       while (l[a[ap].n])
         ap++;
       cout << a[ap].n + 1 << ' ';
       l[a[ap].n ] = true;
     }
  }  
}


bool comp(Pair a1, Pair a2)
{
  if (a1.v != a2.v)
  {
    return a1.v > a2.v;
  }
  else
  {
    return a1.n < a2.n;
  }
}

#include "iostream"
#include "algorithm"
#include "stdlib.h"
#include "set"

struct Chair
{
  unsigned long n;
  unsigned long w;
  unsigned long h;
};

bool ChairComp(const Chair& a1, const Chair& a2)
{
  return a1.h < a2.h;
};

using namespace std;

int main()
{
  unsigned int n, H;
  cin >> n >> H;
  Chair *listCh = (Chair*)calloc(n, sizeof(Chair));
  for (int i = 0; i < n; i++)
  {
    cin >> listCh[i].h;
    listCh[i].n = i;
  }
  
  for (int i = 0; i < n; i++)
    cin >> listCh[i].w;
  
  sort(listCh, listCh+n, ChairComp); 
  
  unsigned int r = 0, l = 0;
  unsigned long long  sumw = listCh[0].w;
  multiset<unsigned long long, greater<unsigned long long>> uncomf;
  unsigned long long minUn = 10000000000;
  
  for (l; l < n-1; l++)
  {  
    while(sumw < H and r < n)
    {
      r++;
      sumw += listCh[r].w;
      uncomf.insert(listCh[r].h - listCh[r-1].h); 
    }
    if (sumw >= H)
    {
      if (uncomf.empty())
      {
        cout << 0;
        return 0;
      }    
      else if (*(uncomf.begin()) < minUn)
        minUn = *(uncomf.begin());
    }
    
    if (l == r) r++;
    else
    { 
      uncomf.erase(uncomf.find(listCh[l+1].h - listCh[l].h));
      sumw -= listCh[l].w;
    }
  }
  
  if (listCh[n-1].w >= H)
  {
    cout << 0;
    return 0;
  }
  
  cout << minUn;
}

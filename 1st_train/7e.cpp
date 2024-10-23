#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, count, sh, sm, eh, em, j = 0;
  int *in, *out;
  
  cin >> n;
  in = new int[n*2];
  out = new int[n*2];
  int m = n;
  for (int i = 0; i < m; i++)
  {
    cin >> sh >> sm >> eh >> em;
    sm += sh * 60;
    em += eh * 60;
    if (sm > em)
    {
      in[j] = 0;
      out[j] = em;
      j++;
      in[j] = sm;
      out[j] = 24*60;
    }
    else if (sm == em)
    {
    in[j] = 0;
    out[j] = 24*60;
    }
    else
    {
    in[j] = sm;
    out[j] = em;
    }
    j++;
  }
  
  sort(in, in + j);
  sort(out, out + j);
  
  count = 0;
  
  int o = 0, c = 0;
  int duration = 0, start;
  while(o < j)
  {
  if (in[o] <= out[c])
  {
    count ++;
    if (count == n)
      start = in[o];
    o++;
  }
  else
  {
    if (count == n)
      duration += out[c] - start ;
    count--;
    c++;
  }
  }
  if (count == n and c < j)
  {
    duration += out[c] - start ;
  }
  
  
  cout<<duration;
}



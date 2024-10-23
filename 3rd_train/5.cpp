#include "iostream"
#include "set"

using namespace std;

int main()
{
  long int N, c[26] = {0}, len = 0;
  set<long int> count;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> c[i];
    count.insert(c[i]);
  }
  
  set<long int>::iterator it;
  long int cuted = 0, cutCur;
  for (it = count.begin(); it != count.end(); ++it)
  {
    cutCur = (*it - cuted);
    c[0]-= cutCur;
    for (int i = 1; i < N; i++)
    {
      c[i]-= cutCur;
      if (c[i]>= 0 and c[i-1] >= 0)
        len += cutCur;
    }
    cuted += cutCur;
  }
  cout << len;
}

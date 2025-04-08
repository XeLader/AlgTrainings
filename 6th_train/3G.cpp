#include "iostream"

using namespace std;

int main()
{
  unsigned long long int n, b, a, que = 0, sum = 0;
  cin >> n >> b;
  for (unsigned long long i = 0; i < n; i++)
  {
    cin >> a;
    que+= a;
    sum+=que;
    if (que <= b)
      que = 0;
    else
      que -= b;
  }
  sum+=que;
  cout << sum;
}

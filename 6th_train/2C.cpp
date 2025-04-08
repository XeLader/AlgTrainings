#include "iostream"
#include "vector"

using namespace std;

int main()
{
  unsigned int N, r, L = 0, R = 1;
  long long count = 0;
  
  cin >> N >> r;
  vector<long long> mon(N);
  
  for (unsigned int i = 0; i < N; i++)
  {
    cin >> mon[i];
  }
  
  for (L;  L < N; L++)
  {
    while (mon[R] - mon [L] <= r and R < N)
      R++;
    if (mon[R] - mon [L] > r)
      count += N - R;
    else break;
  }
  cout << count;
}

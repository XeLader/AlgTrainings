#include "iostream"
#include "vector"

using namespace std;

int main()
{
  unsigned int N, L = 1, R = 1, K, c = 0;
  cin >> N >> K;
  vector<unsigned long long> ps(N+1);   
  for (unsigned int i = 1; i <= N; i++)
  {
    cin >> ps[i];
    ps[i]+=ps[i-1];
  }
  
  for (L; L <= N; L++)
  {
    while (ps[R]-ps[L-1] < K and (R < N))
      R++;

    if (ps[R]-ps[L-1] == K) c++;
  }
  cout << c;
}

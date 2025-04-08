#include "iostream"

using namespace std;

int main()
{
  int n;
  long long a, b = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    b+=a;
    cout << b << ' ';
  }
}

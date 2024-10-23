#include <iostream>

using namespace std;

int main(void)
{
  int n, *arr, suggest = 0, max, score = 0;
  int records[1001] = {0};
  cin >> n;
  arr = new int[n];
  cin >> arr[0];
  records[arr[0]]++;
  max = arr[0];
  cin >> arr[1];
  records[arr[1]]++;
  for (int i = 2; i<n; i++)
  {
    cin >> arr[i];
    records[arr[i]]++;
    if (max < arr[i-1])
    {
      max = arr[i-1];
      suggest = 0;
    }
    else if (arr[i-1] % 10 == 5 and arr[i] < arr[i-1] and suggest < arr[i-1] )
      suggest = arr[i-1];

      
  }
  if (max < arr[n-1])
    suggest = 0;
  if (suggest)
  {
    for (int i = suggest+1; i<=max; i++)
      score += records[i];
    cout << score+1;
  }
  else cout << 0;
}

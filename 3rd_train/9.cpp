#include <iostream>

using namespace std;

int main()
{
  int N, M, K;
  cin >> N>> M >> K;
  long int *arr;
  arr = new long int[N*M];
  for (int i = 0; i < N*M; i++)
    cin >> arr[i];
  
  long int *arrsum;
  arrsum = new long int[N*M];
  for (int i = 0; i < N; i++)
  {
    arrsum[i*M] = arr[i*M];
    for (int j = 1; j < M; j++)
       arrsum[i*M + j] = arr[i*M + j] + arrsum[i*M + j - 1];
  }
  
  for (int j = 0; j < M; j++)
  {
    for (int i = 1; i < N; i++)
       arrsum[i*M + j] += arrsum[(i-1)*M + j];
  }
  
  int x1, x2, y1, y2, sum;
  for (int i = 0; i < K; i++)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    sum = arrsum[(x2-1)*M + y2-1];
    if (x1 > 1 and y1 > 1)
      sum -= (arrsum[(x1-2)*M + y2-1] + arrsum[(x2-1)*M + y1-2] - arrsum[(x1-2)*M + y1-2]);
    else if (x1 > 1)
      sum -= arrsum[(x1-2)*M + y2-1];
    else if (y1 > 1)
      sum -= arrsum[(x2-1)*M + y1-2];
    cout << sum << '\n';
  }
}

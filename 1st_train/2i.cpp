#include <iostream>

using namespace std;

int main()
{
  int N, M, K;
  int arr[10000] = {0};
  
  int n, m;
  
  cin >> N >> M >> K;
  for (int i = 0; i < K; i++)
  {
    cin >> n >> m;
    if (arr[(n-1)*M + (m-1)] >= 0)
    {
      arr[(n-1)*M+(m-1)] = -1000000;
      if (n > 1)
      { 
        arr[(n-2)*M+(m-1)]++;
        if (m > 1)      
          arr[(n-2)*M+(m-2)]++;
        if (m < M)
          arr[(n-2)*M + m]++;
      }
      if (n < N)
      { 
        arr[n * M + (m-1)]++;
        if (m > 1)
          arr[n * M + (m-2)]++;
        if (m < M)
          arr[n * M + m]++;
      }
      if (m > 1)
       arr[(n-1)*M+(m-2)]++;
      if (m < M)
        arr[(n-1)*M + m]++;
    }
  }
  
  for (int i = 0 ; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (arr[i*M+j] < 0)
        cout << "* ";
      else
        cout << arr[i*M+j] << ' ';
    }
    cout <<'\n';
  }
}

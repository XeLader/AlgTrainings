#include <iostream>

using namespace std;

int main(void)
{
  int N, *arr;
  cin >> N;
  arr = new int[N];
  int s = 0, e = N-1;
  for (int i = 0; i<N; i++)
    cin >> arr[i];
  while( s < e){
    if (arr[s] == arr[e])
      e--;
    else
      e = N-1;
    s++;
  }
  cout << (s*2-N +(s==e))<<'\n';
  s -=(N-s-(s==e));
  while (s){
    s--;
    cout<<arr[s]<<' '; 
  }
}

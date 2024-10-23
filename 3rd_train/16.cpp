#include <iostream>
#include <set>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  
  long long int *arr;
  arr = new long long int[K];
  
  multiset<long long int> frame;
  for (int i = 0 ; i< K; i++)
  {
    cin >> arr[i];
    frame.insert(arr[i]);
  }
  cout << *frame.begin()<<'\n';
  for (int i = K; i < N; i++)
  {
    frame.erase(frame.find(arr[i%K]));
    cin >> arr[i%K];
    frame.insert(arr[i%K]);
    cout << *frame.begin()<<'\n';
  } 
}

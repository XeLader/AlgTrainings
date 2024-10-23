#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
  unsigned int N, K;
  cin >> K >> N;
  multimap<int, int> trains;
  multimap<int, int>::iterator it;
    
  set<int> empt;
    
  int arr, dep;
  
  int *blinds = new int[N];
  
  for (unsigned int i = 1; i <= K; i++)
 {
   empt.insert(i);
 } 
  
  for (unsigned int i = 0; i < N; i++)
  {
    cin >> arr >> dep;
    if (trains.begin() != trains.lower_bound(arr))
    {
      for (it = trains.begin(); it != trains.lower_bound(arr); ++it)
      {
        empt.insert(it->second);
      }
      trains.erase(trains.begin(), it);
    }
    if (!empt.empty())
    {
      trains.insert({dep, *empt.begin()});
      blinds[i] = *empt.begin();
      empt.erase(empt.begin());
    }
    else
    {
      cout << "0 " << i+1;
      return 0;
    }
  }
  
  for (unsigned int i = 0; i < N; i++)
    cout << blinds[i] << ' ';
}

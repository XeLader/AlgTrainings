#include <iostream>
#include <map>

using namespace std;

int main()
{
  int N, K;
  long long temp, twice = 0, single = 0, ways = 0;
  map<long long, long long> Cards;
  
  cin >> N >> K;
  
  for (int i = 0; i < N; i++)
  {
    cin >> temp;
    Cards[temp]++;
  }
  
  map<long long, long long>::iterator itr, itl;
  
  itr = Cards.begin();
  itl = itr;
  
  do
  {
    if (itl -> first * K >= (itr -> first))
    {
      if (itr -> second >= 3)
      {
        ways++;
        ways += twice*3;
        ways += 3*single*(single-1) + single * 3;
        twice++;
        single++;
      }
      else if (itr -> second == 2)
      {
        ways += twice * 3;
        ways += single*3 + 3*single*(single-1);
        twice ++;
        single ++;
      }
      else
      {
        ways += twice * 3;
        ways += 3*single*(single-1);
        single ++;
      }
      itr++;
    }
    else
    {
      if (itl -> second >= 2)
        {
          twice--;
          single--;
        }
        else
        {
          single --;
        }
      itl++;
    }
  } while(itr!=Cards.end());
  
  cout << ways;
}

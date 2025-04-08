#include "iostream"
#include "stack"
#include "array"
#include "vector"

using namespace std;

int main()
{
  int N, a, b;
  array<int,2> temp;
  stack<array<int,2>> city;
  cin >> N;
  vector<int> move(N);
  temp[0] = 0;
  cin >> temp[1];
  city.push(temp);
  for (int i = 1; i < N ; i++)
  {
    temp[0] = i;
    cin >> temp[1];
    while(temp[1] < city.top()[1])
    {
      move[city.top()[0]] = i;
      city.pop();
      if (city.empty()) break;
    }
    city.push(temp);
  }
  while (!city.empty())
  {
    move[city.top()[0]] = -1;
    city.pop();
  }
  for (int i = 0; i < N ; i++)
    printf("%d ", move[i]);
  
  
}

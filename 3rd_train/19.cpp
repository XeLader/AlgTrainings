#include <iostream>
#include <set>

using namespace std;

int main()
{
  multiset<long long> numbers;
  multiset<long long>::iterator it;
  int N;
  long long temp, Sum = 0;
  double Pay = 0;
  cin >> N;
  for (int i = 0; i< N; i++)
  {
    cin >> temp;
    numbers.insert(temp);
  }
  
  for (int i = 0; i < N - 1; i++)
  {
    it = numbers.begin();
    it++;
    Sum = (*numbers.begin()) + (*it);
    numbers.erase(numbers.begin(), ++it);
    Pay += Sum * 0.05;
    numbers.insert(Sum);
  }
   
  printf("%.2f", Pay);
}

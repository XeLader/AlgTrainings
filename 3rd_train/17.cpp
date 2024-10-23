#include <iostream>
#include <deque>

using namespace std;

int main()
{
  int N;
  cin >> N;
  deque<int> que;
  int temp;
  char stat; 
  
  for (int i = 0; i < N; i++)
  {
    cin >> stat;
    switch (stat)
    { 
      case '+':
        cin >> temp;
        que.push_back(temp);
        break;
    
     case '*':
       cin >> temp;
       que.insert(next(que.begin(), que.size()/2 + que.size() % 2), temp);
       break;
       
     case '-':
       cout << que.front()<< '\n';
       que.pop_front();
       break;
    }
  }
}

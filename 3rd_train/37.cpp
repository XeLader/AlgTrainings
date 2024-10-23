#include <iostream>
#include <queue>
#include <stack>


using namespace std;

int incFirst(int num);
int decLast(int num);
int leftShift(int num);
int rightShift(int num);


int main()
{
  int start = 0, end = 0, temp;
  int state[9999] = {0};
  int route[9999];

  scanf("%i %i", &start, &end);
  
  state[start] = 1;
  route[start] = -1;
  
  
  queue<int> q;
  
  q.push(start);
  while(!q.empty() and state[end] == 0)
  {
    temp = incFirst(q.front());
    if (temp and (state[temp] == 0  or state[temp] > (state[q.front()] + 1)))
    {
      state[temp] = state[q.front()] + 1;
      route[temp] = q.front();
      q.push(temp);
    }
    temp = decLast(q.front());
    if (temp and (state[temp] == 0  or state[temp] > (state[q.front()] + 1)))
    {
      state[temp] = state[q.front()] + 1;
      route[temp] = q.front();
      q.push(temp);
    }
    temp = leftShift(q.front());
    if (state[temp] == 0  or state[temp] > (state[q.front()] + 1))
    {
      state[temp] = state[q.front()] + 1;
      route[temp] = q.front();
      q.push(temp);
    }
    temp = rightShift(q.front());
    if (state[temp] == 0  or state[temp] > (state[q.front()] + 1))
    {
      state[temp] = state[q.front()] + 1;
      route[temp] = q.front();
      q.push(temp);
    }
    q.pop();
  }
  
  stack<int> s;
  s.push(end);
  while (route[s.top()] > 0)
    s.push(route[s.top()]);
  
  while (!s.empty())
  {
    cout << s.top()<<'\n';
    s.pop();
  }
  
}

int incFirst(int num)
{
  if (num / 1000 < 9)
    return num+1000;
  return 0;
}


int decLast(int num)
{
  if (num % 10 > 1)
    return num-1;
  return 0;
}


int leftShift(int num)
{
  return num / 1000 + (num % 1000) * 10;
}

int rightShift(int num)
{
  return num / 10 + (num % 10) * 1000;
}

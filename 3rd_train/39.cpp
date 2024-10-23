#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <utility>

using namespace std;

void inputTunnels();
void inputRobots();
void checkNeigbors();

void checkOdd(int step, bool *visitedOdd, bool *visited, queue<unsigned int> &needVisit, queue<int> &stepVisit, bool *conCheck);
void checkEven(int step, bool *visitedEven, bool *visited, queue<unsigned int> &needVisit, queue<int> &stepVisit, bool *conCheck);

void checkMeetInHall();
void checkMeetInTunnel();


  unsigned int N, K, M;
  map<unsigned int, set<unsigned int>> connections;
  map<unsigned int, set<unsigned int>> times;
  unsigned int* conF, *conS, *count, *countOdd, *countEven;
  int *odd, *even, *general;
  unsigned int pos;
  
  map<unsigned int, float> conStep;
  map<unsigned int, int> conCount;
  
  float minTime = 1000000000;

int main()
{
  
  cin >> N >> K;
  
  general = new int[N];
  odd = new int[N];
  even = new int[N];
  count = new unsigned int[N]{0};
  countOdd = new unsigned int[N]{0};
  countEven = new unsigned int[N]{0};
  
  conF = new unsigned int[K];
  conS = new unsigned int[K];
  
  
  for (unsigned int i = 0; i < N; i++)
  {
    odd[i] = -1;
    even[i] = -1;
    general[i] = -1;
  }
  
  inputTunnels();
  inputRobots();
  
  checkMeetInHall();
  checkMeetInTunnel();
  
  if (minTime !=1000000000)
    cout << minTime;
  else
    cout << -1;
}


void inputTunnels()
{
    for(unsigned int i = 0; i < K; i ++)
  {
    cin >> conF[i] >> conS[i];
    conF[i]--;
    conS[i]--;
    if (conF[i] < conS[i])
    {
      unsigned int temp = conF[i];
      conF[i] = conS[i];
      conS[i] = temp;
    }
    connections[conF[i]].insert(conS[i]);
    connections[conS[i]].insert(conF[i]);
    conStep[conF[i]* N + conS[i]] = -1.0f;
    conCount[conF[i] * N + conS[i]] = 0;
  }
}

void inputRobots()
{
  cin >> M;
  
  for(unsigned int i = 0; i < M; i ++)
  {
    cin >> pos;
    pos --;
    checkNeigbors();
  }
  
}

void checkNeigbors()
{
    bool *visited = new bool[N]{0};
    bool *visitedOdd = new bool[N]{0};
    bool *visitedEven = new bool[N]{0};
    
    bool *conCheck = new bool[N*N]{0};
    //set<pair<unsigned int, unsigned int>> conCheck;
    
    queue<unsigned int> needVisit;
    queue<int> stepVisit;
    
    needVisit.push(pos);
    stepVisit.push(0);
    visited[pos] = true;
    count[pos]++;
    if (general[pos] < 0)
         general[pos] = 0;
    
    visitedEven[pos] = true;
    countEven[pos]++;
    if (even[pos] < 0)
      even[pos] = 0;
    
    while(!needVisit.empty())
    {
      
      pos = needVisit.front();
      int step = stepVisit.front(); 
      
      needVisit.pop();
      stepVisit.pop();
      
      if (step%2 == 0)
      {
        checkOdd(step ,visitedOdd, visited, needVisit, stepVisit, conCheck);
      }
      else
      {
        checkEven(step ,visitedEven, visited, needVisit, stepVisit, conCheck);
      }
    }
    destroy_at(visited);
    destroy_at(visitedOdd);
    destroy_at(visitedEven);
    destroy_at(conCheck);
    
}


void checkOdd(int step, bool *visitedOdd, bool *visited, queue<unsigned int> &needVisit, queue<int> &stepVisit, bool *conCheck)
{
  set<unsigned int> con =  connections[pos]; 
  for (auto it =con.begin(); it != con.end(); it++)
  {  
    if (!visitedOdd[*it])
    {
      needVisit.push(*it);
      stepVisit.push(step + 1);
      visitedOdd[*it] = true;
      countOdd[*it]++;
      if (odd[*it] < step + 1)
          odd[*it] = step + 1;
    }
    if (!visited[*it])
    {
      visited[*it] = true;
      count[*it]++;
      if (general[*it] < step + 1)
        general[*it] = step + 1;
    }
    
    unsigned int f, s;
      if (pos > *it)
      {
        f = pos; s = *it;
      }
      else
      {
        f = *it; s = pos;
      }
      if (!conCheck[f*N + s])
      {
        int st = (step < general[*it])? step : general[*it];
        if (conStep[f * N + s] < st + 0.5)
          conStep[f*N + s] = st + 0.5;
        conCount[f*N + s]++;
       conCheck[f*N + s]= true;
      }
  }
}



void checkEven(int step, bool *visitedEven, bool *visited, queue<unsigned int> &needVisit, queue<int> &stepVisit, bool *conCheck)
{
  set<unsigned int> con =  connections[pos]; 
  for (auto it = con.begin(); it != con.end(); it++)
  {  
    if (!visitedEven[*it])
    {
      needVisit.push(*it);
      stepVisit.push(step + 1);
      visitedEven[*it] = true;
      countEven[*it]++;
      if (even[*it] < step + 1)
        even[*it] = step + 1;
    }
    if (!visited[*it])
    {
      visited[*it] = true;
      count[*it]++;
      if (general[*it] < step + 1)
        general[*it] = step + 1;
    }
    
    
      unsigned int f, s;
      if (pos > *it)
      {
        f = pos; s = *it;
      }
      else
      {
        f = *it; s = pos;
      }
      if (!conCheck[f*N + s])
      {
        int st = (step < general[*it])? step : general[*it];
        if (conStep[f * N + s] < st + 0.5)
          conStep[N*f+ s] = st + 0.5;
        conCount[f*N + s]++;
        conCheck[f*N + s] = true;
      }
  }
}


void checkMeetInHall()
{
  for (unsigned int i= 0; i < N; i++)
  {
     if(count[i] == M)
     {
       if (countEven[i] == M)
       {
         if (minTime > even[i]){
           minTime =  even[i]; 
        }
       }
       if (countOdd[i] == M)
       {
         if (minTime > odd[i])
         {          
           minTime =  odd[i];
         }
       } 
     } 
  }
}

void checkMeetInTunnel()
{
  for (unsigned int i = 0; i < K; i++)
  {
    if (conCount[conF[i] * N + conS[i]] == M)
      if (conStep[conF[i]*N + conS[i]] < minTime and conStep[conF[i]*N +  conS[i]] > 0)
        minTime  = conStep[conF[i]*N + conS[i]] ;
  }
}

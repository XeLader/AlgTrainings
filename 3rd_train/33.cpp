#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include "math.h"

using namespace std;

void BinSortInput(int N, long long *posX, long long *posY, unsigned long long **arr, unsigned int *arrOne, unsigned int *arrTwo);
int rbin(int l, int r, unsigned long long **arr,  unsigned long long a);
void prepMatrix(vector<vector<unsigned int>>& arr, unsigned int *arrOne, unsigned int *arrTwo, unsigned int maxDist, unsigned long long ** dist);
bool checkColor(vector<vector<unsigned int>>& arr);
bool dfs(vector<vector<unsigned int>>& arr, bool *Visited, unsigned int Now, int* Color, int PrepColor); 
unsigned int rbin(unsigned int l, unsigned int r, vector<vector<unsigned int>>& arr, unsigned int *arrOne, unsigned int *arrTwo, vector<unsigned long long>& distSet, unsigned long long **dist);

bool comparator ( const unsigned long long *l, const unsigned long long  *r)
   { return l[0] < r[0]; }


int main()
{
  int N;
  cin >> N;

  long long *posX = new long long[N];
  long long *posY = new long long[N];

  for (int i = 0; i < N; i++)
    cin >> posX[i] >> posY[i];
  
  unsigned long long ** dist = new unsigned long long*[N*(N-1)/2];
  unsigned int *distFir = new unsigned int[N*(N-1)/2];
  unsigned int *distSec = new unsigned int[N*(N-1)/2];
  vector<vector<unsigned int>> matrixNeig; 
  matrixNeig.resize(N);

  BinSortInput(N, posX, posY, dist, distFir, distSec);
  
  vector<unsigned long long> distSet = {dist[0][0]};
  for (int i = 1; i < N*(N-1)/2; i++)
    if (dist[i-1][0] != dist[i][0])
      distSet.push_back(dist[i][0]);
      
  unsigned int result = rbin(0, distSet.size() - 1, matrixNeig, distFir, distSec, distSet, dist);
  prepMatrix(matrixNeig, distFir, distSec, distSet[result], dist);
  bool *Visited = new bool[N]{0};
  int *Color = new int[N]{0};
  for (int i = 0; i < N; i++)
  {
    if (!Visited[i])
      dfs(matrixNeig, Visited, i, Color, 2);
  }

    printf("%.15Lf\n",sqrt((long double)distSet[result])/2.0l);
    for (int i = 0; i < N; i++)
      cout << Color[i] << ' ';
  
  
}


void BinSortInput(int N, long long *posX, long long *posY, unsigned long long **arr, unsigned int *arrOne, unsigned int *arrTwo)
{

  unsigned int Number = 0;
    
  for (int i = 0; i < N-1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      arr[Number] = new unsigned long long[2];
      arr[Number][0] = (posX[i] - posX[j])*(posX[i] - posX[j]) + (posY[i] - posY[j])*(posY[i] - posY[j]);
      arr[Number][1] = Number;
      arrOne[Number] = i;
      arrTwo[Number] = j;
      Number++;
    }
  }
    
    sort(arr, arr + Number, comparator);
  
}

int rbin(int l, int r, unsigned long long *arr,  unsigned long long a)
{
 int m;
  while (l<r)
  {
    m = (l + r + 1) / 2;
    if (arr[m] <= a)
      l = m;
    else 
      r = m - 1;
  }
  return l;
}

void prepMatrix(vector<vector<unsigned int>>& arr, unsigned int *arrOne, unsigned int *arrTwo, unsigned int maxDist, unsigned long long ** dist)
{
  unsigned int N = arr.size();
  for (unsigned int i = 0; i < N; i++)
    arr[i].clear();
    
  
  for (unsigned int i = 0; i < N*(N-1)/2; i++)
  {
    if (dist[i][0] >= maxDist)
      break;
    arr[arrOne[dist[i][1]]].push_back(arrTwo[dist[i][1]]);
    arr[arrTwo[dist[i][1]]].push_back(arrOne[dist[i][1]]);
  }
}

bool checkColor(vector<vector<unsigned int>>& arr)
{
  bool *Visited = new bool[arr.size()]{0};
  int *Color = new int[arr.size()]{0};
  
  for (unsigned int i = 0; i < arr.size(); i++)
  {
    if (!Visited[i])
      if (!dfs(arr, Visited, i, Color, 2))
        return false;
  }
  return true;
  
}

bool dfs(vector<vector<unsigned int>>& arr, bool *Visited, unsigned int Now, int * Color, int PrepColor)
{
  Color[Now] = (PrepColor == 1) ? 2 : 1;
  Visited[Now] = true;
  unsigned int neig;
  for (unsigned int i = 0; i < arr[Now].size(); i++)
  {
     neig = arr[Now][i];
     if (!Visited[neig])
     {
        if (!dfs(arr, Visited, neig, Color, Color[Now]))
          return false;
    }
     else if (Color[neig] == Color[Now])
        return false;
  }
  return true;
}

unsigned int rbin(unsigned int l, unsigned int r, vector<vector<unsigned int>>& arr, unsigned int *arrOne, unsigned int *arrTwo, vector<unsigned long long>& distSet, unsigned long long **dist)
{
  unsigned int m;
  while (l<r)
  {
    m = (l + r + 1) / 2;
    prepMatrix(arr, arrOne, arrTwo, distSet[m], dist);
    if (checkColor(arr))
      l = m;
    else 
      r = m - 1;
  }
  return l;
}


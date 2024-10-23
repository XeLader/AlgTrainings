#include <iostream>
#include <algorithm>

using namespace std;

bool comparator ( const int *l, const int  *r)
   { return l[0] < r[0]; }
void rfc(int x, int y);

int N, M;
int **field, **hxy;
bool **visited;

int main()
{  
  int count = 0;
  cin >> N >> M;
  field = new int*[N + 2];
  hxy = new int*[N*M];
  visited = new bool*[N];
  
  
  for (int i = 0; i < N; i++)
  {
    field[i] = new int[M + 2];
    visited[i] = new bool[M]{0};
  }
  
  field[N] = new int[M + 2];
  field[N+1] = new int[M + 2];
  
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      cin >> field[i][j];
      hxy[(i-1)*M+ (j-1)] = new int[3];
      hxy[(i-1)*M+(j-1)][0] = field[i][j];
      hxy[(i-1)*M +(j-1)][1] = i;
      hxy[(i-1)*M +(j-1)][2] = j;
    }
  }
  
  for (int i = 0; i <= N + 1; i++)
  {
    field[i][0] = -1;
    field[i][M + 1] = -1;
  }
  for (int j = 1; j <= M; j++)
  {
    field[0][j] = -1;
    field[N+1][j] = -1;
  }
  
  sort(hxy, hxy + N*M, comparator);
  
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (!visited[hxy[i*M + j][1] - 1][hxy[i*M +j][2] - 1])
      {
        count++;
        rfc(hxy[i*M +j][1], hxy[i*M +j][2]);
      }    
    }
  }
  
  cout << count;
  
  
  
}

void rfc(int x, int y)
{
  visited[x-1][y - 1] = true;
  if (field[x][y + 1] >= field[x][y])
  {
    if(!visited[x-1][y])
      rfc(x, y+1);
  }
  if (field[x][y - 1] >= field[x][y])
  {
    if (!visited[x-1][y-2])
      rfc(x, y-1);
  }
  if (field[x + 1][y] >= field[x][y])
  {
  if(!visited[x][y-1])
    rfc(x+1, y);
  }
  if (field[x - 1][y] >= field[x][y])
  {
    if(!visited[x-2][y-1])
      rfc(x-1, y);
  }
}

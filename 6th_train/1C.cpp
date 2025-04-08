#include <iostream>

int SqCount(int x1, int y1, int x2, int y2, bool s[10][10], int *x, int *y);
void checkOCL(int x1, int y1, int x2, int y2, int *x, int *y);
void checkHP(int x1, int y1, int x2, int y2, int *x, int *y);

using namespace std;

int main()
{
  int n;
  bool s[10][10] = {{0}};
  cin >> n;
  char c;
  int i, j, x1 = 10, x2 = -1, y1 = 10, y2 = -1;
  int x[4], y[4];
  for (i = n - 1; i >= 0; i--)
    for (j = 0; j < n; j++)
    {
      cin >> c;
      s[i][j] = (c == '#');
    }
  bool check = false;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (s[i][j])
      {
        check = true;
        if (x1 > j) x1 = j;
        if (x2 < j + 1) x2 = j + 1;
        if (y1 > i) y1 = i;
        if (y2 < i + 1) y2 = i + 1;
      }
  if (!check)
  {
     cout << 'X';
     return 0;
  }
  int count = SqCount(x1, y1, x2, y2, s, x, y);
  if (count == 0)
     cout << 'I';
  else if (count == 1)
    checkOCL(x1, y1, x2, y2, x, y);
  else if (count == 2)
    checkHP(x1, y1, x2, y2, x, y);
  else 
    cout << 'X';
}


int SqCount(int x1, int y1, int x2, int y2, bool s[10][10], int *x, int *y)
{
  int n = 0;
  for (int i = y1; i < y2; i++)
    for (int j = x1; j < x2; j++)
    {
        if (!s[i][j])
        {
          x[n*2] = j;
          y[n*2] = i;
          do
          {
            j++;
            if (j >= x2)
              break;
          }
          while (!s[i][j]);
          x[n*2 + 1] = j;
          j--;
          do
          {
            i++;
            if (i >= y2)
              break;
          }
          while (!s[i][j]);
          y[n*2 + 1] = i;
          for (i = y[2*n]; i < y[2*n + 1]; i++)
            for (j = x[2*n]; j < x[2*n + 1]; j++)
            {  
              if (!s[i][j])
                s[i][j] = true;
              else return -1;
            }
          i = y[n*2 + 1];
          j = 0;
          n++;
          if (n > 2) return -1;
          break;
        }
    }
    for (int i = y1; i < y2; i++)
      for (int j = x1; j < x2; j++)
        if (!s[i][j]) return -1;
  return n;
}


void checkOCL(int x1, int y1, int x2, int y2, int *x, int *y)
{
  if (y1 < y[0] and y[0] < y[1])
  {
    if(y[1] < y2)
    {
      if (x1 < x[0] and x[0] < x[1])
      { 
        if (x[1] < x2)
          cout << 'O';
        else 
          cout << 'C';
      }
      else cout<< 'X';
    }
    else if (x1 < x[0] and x[0] < x[1] and x[1] == x2)
      cout << 'L';
    else
      cout << 'X';
  }
  else cout << 'X';
}

void checkHP(int x1, int y1, int x2, int y2, int *x, int *y)
{
  if (x1 < x[0] and x[0] == x[2] and x[0] < x[1] and x[1] == x[3] and x[3] < x2)
  {
     if (y1 == y[0] and y[0] < y[1] and y[1] < y[2] and y[2] < y[3] and y[3] == y2)
       cout << 'H';
     else cout << 'X';       
  } else if (x1 < x[0] and x[0] == x[2] and x[2] < x[3] and x[3] < x[1] and x[1] == x2)
  {
    if (y1 == y[0] and y[0] < y[1] and y[1] < y[2] and y[2] < y[3] and y[3] < y2)
      cout << 'P';
    else cout << 'X';       
  }
  else cout << 'X';
}

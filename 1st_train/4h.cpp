#include <stdio.h>

using namespace std;

int GetNum(char);
bool comp(int *a1, int *a2, int* letters, int Uniq);

int main()
{
  int g, S, N = 0, Uniq = 0, temp;
  char ch;
  int word[52] = {0};
  int CompWord[52] = {0};
  int latters[52]={0};
  int wordfull[3000];
  
  scanf("%d %d\n", &g, &S);
  
  for (int i = 0;  i < g; i++)
  {
    ch = getchar();
    temp = GetNum(ch);
    word[temp]++;
    if (word[temp] == 1)
    {
      latters[Uniq] = temp;
      Uniq++;
    }
  }
  ch = getchar();
  for (int i = 0;  i < g; i++)
  {
    ch = getchar();
    temp = GetNum(ch);
    CompWord[temp]++;
    wordfull[i]=temp;
  }
  
  if (comp(word, CompWord, latters, Uniq))
   N++;
  
  
  for (int i = 0;  i < S - g; i++)
  {  
    CompWord[wordfull[i%g]]--;
    ch = getchar();
    temp = GetNum(ch);
    CompWord[temp]++;
    wordfull[i%g]=temp;
    if (comp(word, CompWord, latters, Uniq))
      N++; 
  }
  
  printf("%d",N);
}

int GetNum(char ch)
{
  if (ch >= 'a')
    return (int)(ch - 'a' + 26);
  else
    return (int)(ch - 'A');
}

bool comp(int *a1, int *a2, int* letters, int Uniq)
{
  for (int i = 0; i < Uniq; i++)
    if (a1[letters[i]] != a2[letters[i]]) return false;
  return true;
}

#include <iostream>
#include <string>
#include <set>

using namespace std;
void maxLenChar(char a, string *str, unsigned int  *max, unsigned int  k);

int main()
{
  string str;
  unsigned int  k, r, l, max = 0;
  bool alpha['z'-'a' + 1] = {0};
  cin >> k >> str;
  
  char comp = str[0];
  int temp = k;
  l = 0;
  for (r = 0; r < str.length(); r++)
  {
    

    if (str[r] != comp)
    {
      while(k == 0)
      {
        if (comp != str[l])
          k++;
        l++;
      }
      k--;
      alpha[str[r] - 'a'] = 1;
    }
    if (max < r - l + 1)   
      max = r - l + 1;
  }
  k = temp;
  
  
  
  for (int i = 0; i <= 'z'-'a'; i++)
  {
    if (alpha[i])
      maxLenChar('a' + i, &str, &max, k);
  }
  
  cout << max;
}

void maxLenChar(char a, string *str, unsigned int  *max, unsigned int k)
{
  unsigned int r, l = 0;
  for (r = 0; r <str->length(); r++)
  {
    if ((*str)[r] != a)
    {
      while(k == 0)
      {
        if ((*str)[l] != a)
          k++;
        l++;
      }
      k--;
    }
    if (*max < r - l + 1)   
      *max = r - l + 1;
  }
}

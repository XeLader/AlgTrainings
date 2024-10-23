#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  cin >> str;
  int len = str.length();
  unsigned long long int count['z'-'a'+1] = {0};
  char ch;
  
  for (int i = 0; i < len; i++)
  {
    ch = str[i];
    count[ch - 'a'] += (i+1)*(len -i);
  }
  
  for (int i = 0; i <= 'z' - 'a'; i++)
  {
    if (count[i])
        printf("%c: %llu\n", 'a'+ i,  count[i]);
  }
}
